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
   int chrckMote(int mote, int i, vector<int> & testVtr)
   {
      int retValue = 0;
      map<int, int>::iterator pos = m_checked.find(i);
      while(i < size)
      {
         if (mote > testVtr)
         {
            mote += testVtr[i];
            i++;
         }
         else
         {
            int add = chrckMote(mote, i, testVtr);
            int remove = chrckMote(mote, i+1, testVtr);
            if (add < remove)
            {
               return 1+add;
            }
            else
            {
               return 1+remove;
            }
         }
      }
      return retValue;
   }
   virtual void readTestCase( std::ifstream & file, std::ofstream & fileOut, int i ) 
   {
      m_checked.clear();
      vector<int> inputVtr;
      readValue(file, inputVtr);
      m_mote = inputVtr[0];
      size = inputVtr[1];
      vector<int> testVtr;
      readValue(file, testVtr);
      sort(testVtr.begin, testVtr.end());
      fileOut << "Case #" << i+1 << ": ";
      fileOut << chrckMote(m_mote, 0, testVtr);
      fileOut << endl;
   }

   int m_mote;
   int size;
   map<int, int> m_checked;

};


int _tmain(int argc, _TCHAR* argv[])
{
	SecondTask fr("c:\\jam.in");
	fr.readFile();
  // getch();
	return 0;
}

