// DeceitfulWar.cpp: определяет точку входа для консольного приложения.
//

#include <stdio.h>
#include <tchar.h>
#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <deque>
#include <time.h>
#include <iterator>
#include <iomanip>
using namespace std;

typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair

using namespace std;

void processTestCase(fstream& inputFile, fstream& outputFile)
{
	int N;
	inputFile >> N;
	set<double> NaomiBlocks;
	double temp;
	for (int i = 0; i < N; ++i)
	{
		inputFile >> temp;
		NaomiBlocks.insert(temp);
	}
	set<double> KenBlocks;
	for (int i = 0; i < N; ++i)
	{
		inputFile >> temp;
		KenBlocks.insert(temp);
	}

	{
		int NaomiPointsIfDeceitfulWar = N;
		set<double> NaomiBlocksCopy(ALL(NaomiBlocks));
		set<double> KenBlocksCopy(ALL(KenBlocks));

		while (!NaomiBlocksCopy.empty())
		{
			if (*NaomiBlocksCopy.begin() < *KenBlocksCopy.begin())
			{
				NaomiPointsIfDeceitfulWar-= 1;
				NaomiBlocksCopy.erase(NaomiBlocksCopy.begin());
				KenBlocksCopy.erase(--KenBlocksCopy.end());
			}
			else
			{
				NaomiBlocksCopy.erase(NaomiBlocksCopy.begin());
				KenBlocksCopy.erase(KenBlocksCopy.begin());
			}
		}
		outputFile << NaomiPointsIfDeceitfulWar << " ";
	}

	{
		int NaomiPointsIfWar = N;
		set<double> KenUsedBlocks;
		for each (double naomiVal in NaomiBlocks)
		{
			for each (double kenVal in KenBlocks)
			{
				if (kenVal > naomiVal && KenUsedBlocks.find(kenVal) == KenUsedBlocks.end())
				{
					NaomiPointsIfWar--;
					KenUsedBlocks.insert(kenVal);
					break;
				}
			}
		}
		outputFile << NaomiPointsIfWar;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
   if (argc != 3)
   {
      std::cerr << "Usage: applicationName inputFileName outputFileName";
      return -1;
   }
   fstream inputFile(argv[1], fstream::in);
   fstream outputFile(argv[2], fstream::out);

   std::string line;
   getline(inputFile, line);
   int testCasesQty = atoi( line.c_str() );
   int testCasesProcessed = 0;
   while (true)
   {
      outputFile << "Case #" << ++testCasesProcessed << ": ";
	  processTestCase(inputFile, outputFile);
      if (testCasesProcessed == testCasesQty)
         break;
      else
         outputFile  << '\n';
   }
	return 0;
}


