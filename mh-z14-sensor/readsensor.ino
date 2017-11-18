# Arduino program to read the MH-Z14 CO2 sensor
# Copyright (c) Rudi Niemeijer
# MIT License

#include <SoftwareSerial.h>

#define SensorRX 10           // Yellow
#define SensorTX 11           // White

int co2AveragePpm = 0;
SoftwareSerial co2sensor (SensorRX, SensorTX);

int takeCO2Reading() {
  byte cmd[9] = {
    0xFF,0x01,0x86,0x00,0x00,0x00,0x00,0x00,0x79}; 
  byte response[9]; 

  co2sensor.begin(9600);        
  co2sensor.write(cmd, 9);
  delay(100);
  Serial.println("Data inlezen..");
  while (co2sensor.available()) {
    Serial.print(co2sensor.read());
    Serial.print(" ");
  }
  Serial.println();
  // co2sensor.readBytes(response, 9);
  // byte responseHigh = response[2];
  // byte responseLow = response[3];
  // int ppm = (256 * responseHigh) + responseLow;
  // Serial.print("CO2 value ");
  // Serial.println(ppm);
  //  Serial.println("Checksum: " + String(response[8], DEC));

  co2sensor.end();
  //  return ppm;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);
  co2AveragePpm = takeCO2Reading();
}

void loop() {
  delay(1000);
  takeCO2Reading();
  // co2AveragePpm = (4 * co2AveragePpm + takeCO2Reading()) / 5;
  // Serial.println("Average CO2 is " + String(co2AveragePpm));
  
  // put your main code here, to run repeatedly:

}
