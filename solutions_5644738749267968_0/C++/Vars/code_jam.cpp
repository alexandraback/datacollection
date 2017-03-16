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
   virtual void readTestCase( std::ifstream & file, std::ofstream & fileOut, int i ) 
   {
	  int vectSize;
	  readValue(file, vectSize);
      vector<double> inputNaomi;
      readValue(file, inputNaomi);
	  vector<double> inputKen;
	  readValue(file, inputKen);
	  sort(inputNaomi.begin(), inputNaomi.end());
	  sort(inputKen.begin(), inputKen.end());
      fileOut << "Case #" << i+1 << ": " << justPlay(inputNaomi, inputKen) << " " << fairPlay(inputNaomi, inputKen) ;
      fileOut << endl;
   }

   double getNext(vector<double> & inp)
   {
	   double res = inp.back();
	   inp.pop_back();
	   return res;
   }

   double getSmartNext(vector<double> & inp, const vector<double> & kens )
   {
	   if ((inp.size() == 1) ) 
	   {
		   double res = inp.back();
		   inp.pop_back();
		   return res;
	   }

	   if ((inp.back()>kens.back()) && (inp.front()>kens.front()))
	   {
		    inp.erase(inp.begin());
			return kens.back()+0.00001;
	   }
	   inp.erase(inp.begin());
	   return kens.back()-0.00001;
   }

   int getKenNext(vector<double> & inp, double naomi)
   {
	   vector<double>::iterator pos = upper_bound(inp.begin(), inp.end(), naomi);
	   if (pos == inp.end())
	   {
		   pos = inp.begin();
	   }
	   double res = *pos;
	   inp.erase(pos);
	   return res > naomi?0:1;
   }

   int justPlay( vector<double> inputNaomi, vector<double> inputKen)
   {
	   int gameResult = 0;
	   while (inputNaomi.size() > 0)
	   {
		   gameResult+=getKenNext(inputKen, getSmartNext(inputNaomi, inputKen));
	   }
	   return gameResult;
   }

   int fairPlay( vector<double> inputNaomi, vector<double> inputKen)
   {
	   int gameResult = 0;
	   while (inputNaomi.size() > 0)
	   {
		   gameResult+=getKenNext(inputKen, getNext(inputNaomi));
	   }
	   return gameResult;
   }


};


int _tmain(int argc, _TCHAR* argv[])
{
	SecondTask fr("c:\\jam.in");
	fr.readFile();
   getch();
	return 0;
}

