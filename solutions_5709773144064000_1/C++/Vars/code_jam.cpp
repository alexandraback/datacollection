// code_jam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "InputFileReader.h"
#include <conio.h>
#include <algorithm>
#include <map>
#include <iomanip>

using namespace std;

class SecondTask : public InputFileReader
{

public:
   SecondTask(string fileName)
      : InputFileReader(fileName)
   {

   }
   virtual void readTestCase( std::ifstream & file, std::ofstream & fileOut, int i ) 
   {
      vector<double> inputVtr;
      readValue(file, inputVtr);
	  double price = inputVtr[0];
	  double salary = inputVtr[1];
	  double target = inputVtr[2];
	  double timeResult = target/2;
	  double timeTemp = timeResult;
	  double timeAccum = 0.0;
	  int cook = 0;
	  do 
	  {
		  timeResult = timeTemp;
		  timeAccum = timeAccum + price / (2+salary*cook);	
		  cook++;
		  timeTemp = timeAccum + target / (2+salary*cook);
	  } while (timeTemp < timeResult);
	  fileOut << "Case #" << i+1 << ": " << std::fixed << std::showpoint << std::setprecision(7) << timeResult;
      fileOut << endl;
   }

};


int _tmain(int argc, _TCHAR* argv[])
{
	SecondTask fr("c:\\jam.in");
	fr.readFile();
   getch();
	return 0;
}

