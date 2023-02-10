float freq = 0.0;
unsigned int currentTime, initialTime;
double liters_s;
double liters_h;
double total_liters;
void setup() {
  initialTime = millis();
}
  Serial.begin(9600); //baud rate 9600

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0); // read hall effect sensor value
  //Serial.println(sensorValue);
  delay(10);        // delay in between reads for stability
  if (sensorValue < 40) {
    freq++;
  }
  currentTime = millis();
  if(currentTime - initialTime > 1000){ // per second
    Serial.print("Freq : ");
    Serial.println(freq);
    liters_s=freq/450.0 ;     //in seconds
    liters_h=liters_s*60*60;  // liters in hours
    total_liters+=liters_s;  //total in hrs 
    initialTime=currentTime;
    Serial.print("Liter/s : ");
    Serial.println(liters_s);
    Serial.print("Liter/h : ");
    Serial.println(liters_h);
    Serial.print("Total Liters through wfm : ");
    Serial.println(total_liters);
    freq=0;
  }
}
