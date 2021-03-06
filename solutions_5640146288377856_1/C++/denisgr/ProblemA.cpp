// ProblemA.cpp: определяет точку входа для консольного приложения.
//

#include <stdio.h>
#include <tchar.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <deque>
#include <algorithm>
#include <sstream>
#include <map>
#include <set>
#include <assert.h>
using namespace std;
#pragma comment(linker, "/STACK:134217728")
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VInt;

#define FOR(i, a, b) for(i = (a); i < (b); ++i)
#define RFOR(i, a, b) for(i = (a) - 1; i >= (b); --i)
#define CLEAR(a, b) memset(a, b, sizeof(a))
#define SIZE(a) int((a).size())
#define ALL(a) (a).begin(),(a).end()
#define PB push_back
#define MP make_pair

int processTestCase(fstream& inputFile)
{
	int R = 0, C = 0, W = 0;
	inputFile >> R >> C >> W;

	int emptyRowsAmount = (R - 1) * int(double(C) / W);

	int amount = 0;

	if (C == W)
	{
		return W + emptyRowsAmount;
	}

	if (C < 2 * W)
	{
		return W + 1 + emptyRowsAmount;
	}

	while (C >= 2 * W)
	{
		C -= W;
		amount++;
	}

	if (C == W)
	{
		return W + amount + emptyRowsAmount;
	}

	return amount + W + 1 + emptyRowsAmount;
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
      outputFile << "Case #" << ++testCasesProcessed << ": " << processTestCase(inputFile);
      if (testCasesProcessed == testCasesQty)
         break;
      else
         outputFile  << '\n';
   }
	return 0;
}

