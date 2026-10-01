int sensorBMin = 0;
int sensorBMax = 4095;

int sensorMMin = 0;
int sensorMMax = 4095;

int sensorTMin = 0;
int sensorTMax = 4095;

int sensorBPin = A3;
int sensorMPin = A2;
int sensorTPin = A1;

int ledBPin = 13;
int ledBValue;

int ledMPin = 27;
int ledMValue;

int ledTPin = 15;
int ledTValue;

int offBrightness = 0;
int onBrightness = 255;

int threshold = 1500;

void setup() {
  Serial.begin(9600);
  pinMode(ledBPin, OUTPUT);
  pinMode(ledMPin, OUTPUT);
  pinMode(ledTPin, OUTPUT);
}

void loop() {
  int sensorBValue = analogRead(sensorBPin);
  int sensorMValue = analogRead(sensorMPin);
  int sensorTValue = analogRead(sensorTPin);

  if (sensorBValue > threshold) {
    digitalWrite(ledBPin, HIGH);
  } else {
    digitalWrite(ledBPin, LOW);
  }

  if (sensorMValue > threshold) {
    digitalWrite(ledMPin, HIGH);
  } else {
    digitalWrite(ledMPin, LOW);
  }

  if (sensorTValue > threshold) {
    digitalWrite(ledTPin, HIGH);
  } else {
    digitalWrite(ledTPin, LOW);
  }

  //compare the two readings and decide which LED wins
if (sensorBValue > 3000 && sensorMValue < 3000 && sensorTValue < 3000)
{
  //neither sensor is active
  ledBValue = onBrightness;
}

else if (sensorBValue < 4500 && sensorMValue > 3000 && sensorTValue < 3000)
{
  //Sensor 1 is higher
  ledBValue = onBrightness;
  ledMValue = onBrightness;
}

else if (sensorBValue < 4500 && sensorMValue < 4500 && sensorTValue > 3000)
{
  //Sensor 1 is higher
  ledBValue = onBrightness;
  ledMValue = onBrightness;
  ledTValue = onBrightness;
}

else 
{
  //Sensor 2 is higher
  ledBValue = offBrightness;
  ledMValue = offBrightness;
  ledTValue = offBrightness;
}

// Set the LEDs
analogWrite(ledBPin, ledBValue);
analogWrite(ledMPin, ledMValue);
analogWrite(ledTPin, ledTValue);

//print the LED and Sensor values on one line
  Serial.print(" Bottom: ");

  Serial.print(sensorBValue);

  Serial.print(" LED Bottom: "); 

  Serial.print(ledBValue);

  Serial.print(" Middle: ");

  Serial.print(sensorMValue);

  Serial.print(" LED Middle: ");

  Serial.print(ledMValue);
  


  Serial.print(" Top: ");

  Serial.println(sensorTValue);

  Serial.print(" LED Top: ");

  Serial.print(ledTValue);
 

  delay(100);
}



