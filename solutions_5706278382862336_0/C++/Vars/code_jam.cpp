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
   virtual void readTestCase( std::ifstream & file, std::ofstream & fileOut, int z ) 
   {
	   int firstTimeRowNumber;
	   readValue(file, firstTimeRowNumber);
	   firstTimeRowNumber --;
		vector<int> tempRow;
		readValue(file, tempRow);
      int result(0);

		fileOut << "Case #" << z+1 << ": " << result;
      
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

