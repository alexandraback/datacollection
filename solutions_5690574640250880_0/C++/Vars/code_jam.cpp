// code_jam.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "InputFileReader.h"
#include <conio.h>
#include <algorithm>
#include <map>

using namespace std;

class SecondTask : public InputFileReader
{

public:
   SecondTask(string fileName)
      : InputFileReader(fileName)
   {

   }
   virtual void readTestCase( std::ifstream & file, std::ofstream & fileOut, int caseNumber ) 
   {
      vector<int> inputVtr;
      readValue(file, inputVtr);
	  rows = inputVtr[0];
	  columns = inputVtr[1];
	  int minesQuantity = inputVtr [2];
	  fileOut << "Case #" << caseNumber+1 << ": " << endl;
	 // fileOut << rows << " " << columns << " " << minesQuantity << ": " << endl;
	  int emptyPlaces = rows * columns - minesQuantity;
	  vector<string> outputVector;
	  //init
	  for (int i = 0; i<rows; i++)
	  {
		  string tempString(columns, '*');
		  outputVector.push_back(tempString);
	  }
	  outputVector[0][0] = click;
	  emptyPlaces --;
	  if ( (rows == 1)||(columns==1))
	  {
		  for (int i = 0; i<rows; i++)
			  for (int j = 0; j<columns && emptyPlaces>0; j++)
			  {
			     if (i !=0 || j!=0)
			     {
					 outputVector[i][j] = empty;
					 emptyPlaces --;
			     }
			  }
	  }
	  else if (emptyPlaces < 3 && emptyPlaces>0)
	  {
		  fileOut << "Impossible" << endl;
		  return;
	  }
	  else if (emptyPlaces > 2)
	  {
		 outputVector[0][1] = empty;
		 outputVector[1][1] = empty;
		 outputVector[1][0] = empty;

		 if (!checkVector(outputVector, 2, 2, emptyPlaces-3))
		 {
			 fileOut << "Impossible" << endl;
			 return;
		 }
	  }
	  for (int i = 0; i< rows; i++)
	  {
		  fileOut << outputVector[i] << endl;
	  }
      
   }

   bool checkVector(vector<string>& outputVector, int row, int col, int emptyPlaces)
   {
	   if (emptyPlaces == 0)
	   {
		   return true;
	   }
	   bool returnValue = false;
	   if (row <= emptyPlaces && col < columns)
	   {
		   vector<string> modifiedVector = outputVector;
		   for (int i=0; i<row; i++)
		   {
		      modifiedVector[i][col] = empty;
		   }
		   if (checkVector(modifiedVector, row, col+1, emptyPlaces-row))
		   {
			   outputVector = modifiedVector;
			   returnValue = true;
		   }
	   }

	   if (col <= emptyPlaces && row < rows && !returnValue)
	   {
		   vector<string> modifiedVector = outputVector;
		   for (int i=0; i<col; i++)
		   {
			   modifiedVector[row][i] = empty;
		   }
		   if (checkVector(modifiedVector, row+1, col, emptyPlaces-col))
		   {
			   outputVector = modifiedVector;
			   returnValue = true;
		   }
	   }
	   if (!returnValue && col > emptyPlaces && row < rows && col > 2)
	   {
		   if (emptyPlaces > 1)
		   {
			   for (int i=0; i < col && emptyPlaces > 0; i++)
			   {
				   outputVector[row][i] = empty;
				   emptyPlaces--;
			   }
			   returnValue = true;
		   }
		   else
		   {
			   if (row > 2) 
			   {
				   emptyPlaces++;
				   outputVector[row-1][col-1] = '*';
				   for (int i=0; i<col && emptyPlaces > 0; i++)
				   {
					   outputVector[row][i] = empty;
					   emptyPlaces--;
				   }
				   returnValue = true;
			   }

		   }
	   }
	   if (!returnValue && row > emptyPlaces && col < columns && row > 2 )
	   {
		   if (emptyPlaces > 1)
		   {
			   for (int i=0; i<row && emptyPlaces > 0; i++)
			   {
				   outputVector[i][col] = empty;
				   emptyPlaces--;
			   }
				returnValue = true;
		   }
		   else
		   {
			   if (col > 2)
			   {
				   emptyPlaces++;
				   outputVector[row-1][col-1] = '*';
				   for (int i=0; i<row && emptyPlaces > 0; i++)
				   {
					   outputVector[i][col] = empty;
					   emptyPlaces--;
				   }
				   returnValue = true;
			   }
		   }

	   }
       return returnValue;	
   }

   static const char empty = '.';
   static const char click = 'c';
   int rows;
   int columns;
};


int _tmain(int argc, _TCHAR* argv[])
{
	SecondTask fr("c:\\jam.in");
	fr.readFile();
   getch();
	return 0;
}

