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
#include <hash_set>
#include <assert.h>
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
int impossibleAmount = 0;
void findNeighbourhoods(vector<vector<int>>& arr, const pair<int,int>& var, list<pair<int,int> >& cells, int C, int R)
{
	assert(var.first >=0 && var.first < C);
	assert(var.second >=0 && var.second < R);
	if (var.first + 1 < C && arr[var.first + 1][var.second] == '*')
	{
		cells.push_back(MP(var.first + 1, var.second));
	}
	if (var.first - 1 >= 0 && arr[var.first - 1][var.second] == '*')
	{
		cells.push_back(MP(var.first - 1, var.second));
	}
	if (var.second + 1 < R && arr[var.first][var.second + 1] == '*')
	{
		cells.push_back(MP(var.first, var.second + 1));
	}
	if (var.second - 1 >= 0 && arr[var.first][var.second - 1] == '*')
	{
		cells.push_back(MP(var.first, var.second - 1));
	}
	if (var.first + 1 < C && var.second + 1 < R && arr[var.first + 1][var.second + 1] == '*')
	{
		cells.push_back(MP(var.first + 1, var.second + 1));
	}
	if (var.first - 1 >= 0 && var.second + 1 < R && arr[var.first - 1][var.second + 1] == '*')
	{
		cells.push_back(MP(var.first - 1, var.second + 1));
	}
	if (var.first - 1 >= 0 && var.second - 1 >= 0 && arr[var.first - 1][var.second - 1] == '*')
	{
		cells.push_back(MP(var.first - 1, var.second - 1));
	}
	if (var.first + 1 < C && var.second - 1 >= 0 && arr[var.first + 1][var.second - 1] == '*')
	{
		cells.push_back(MP(var.first + 1, var.second - 1));
	}
	assert(cells.size() <= 8);
}

void bfs(int M, int C, int R, vector<vector<int>>& arr, const list<pair<int,int>>& cellsToTest, int& amountOfNonMineCells, bool& solutionWasFound)
{
	if (solutionWasFound)
		return;
	int diff = R*C - amountOfNonMineCells;
	if (diff > M)
	{
		list<pair<int,int>> newCellsToTest;
		for each (const pair<int,int>& var in cellsToTest)
		{
			newCellsToTest.clear();
			findNeighbourhoods(arr, var, newCellsToTest, C, R);
			for each(const pair<int,int>& v in newCellsToTest)
			{
				arr[v.first][v.second] = '.';
				assert(v.first < C);
				assert(v.second < R);
			}
			amountOfNonMineCells += newCellsToTest.size();
			assert(amountOfNonMineCells <= C*R);
			bfs(M,C,R,arr,newCellsToTest,amountOfNonMineCells,solutionWasFound);
			if (solutionWasFound)
				return;
			for each(const pair<int,int>& v in newCellsToTest)
			{
				arr[v.first][v.second] = '*';
				assert(v.first < C);
				assert(v.second < R);
			}
			amountOfNonMineCells -= newCellsToTest.size();
		}
	}
	else if (diff == M)
	{
		solutionWasFound = true;
		return;
	}
	else
	{
		return;
	}
}

void processTestCase(fstream& inputFile, fstream& outputFile, bool lastCase)
{
	int R,C,M;
	inputFile >> R >> C >> M;
	//outputFile << "R= " <<R<<"; C= "<< C << "; M= " << M << endl;
	list<pair<int,int>> startCells;
	/*startCells.push_back(MP(0,0));
	if (R > 1)
	startCells.push_back(MP(0,1));
	if (C > 1)
	startCells.push_back(MP(1,0));
	if (R > 1 && C > 1)
	startCells.push_back(MP(1,1));*/
	for (int i = 0; i < C; ++i)
	{
		for (int j = 0; j < R; ++j)
		{
			startCells.push_back(MP(i,j));
		}
	}
	for each (pair<int,int> val in startCells)
	{
		vector<vector<int>> arr(C, vector<int>(R, '*'));//* - mine
		list<pair<int,int>> cellsToTest;
		findNeighbourhoods(arr, val, cellsToTest, C, R);
		for each(const pair<int,int>& v in cellsToTest)
		{
			arr[v.first][v.second] = '.';
		}
		arr[val.first][val.second] = 'c';
		int amountOfNonMineCells = 1 + cellsToTest.size();
		bool succeeded = false;
		bfs(M, C, R, arr, cellsToTest, amountOfNonMineCells, succeeded);
		if (!succeeded)
		{
			arr = vector<vector<int>>(C, vector<int>(R, '*'));
			arr[val.first][val.second] = 'c';
			cellsToTest.clear();
			cellsToTest.push_back(MP(val.first, val.second));
			amountOfNonMineCells = 1;
			bfs(M, C, R, arr, cellsToTest, amountOfNonMineCells, succeeded);
		}
		if (succeeded)
		{
			for (int j = 0; j < R; ++j)
			{
				for (int i = 0; i < C; ++i)
				{
					outputFile << (char)arr[i][j];
				}
				if (j != R - 1)
					outputFile << endl;
				else if (j == R - 1 && !lastCase)
					outputFile << endl;
			}
			return;
		}
	}
	impossibleAmount++;
	outputFile << "Impossible";
	if (!lastCase)
		outputFile << endl;
}

int _tmain(int argc, _TCHAR* argv[])
{
   //fstream out("input_test.txt", fstream::out);
   //for (int i = 1; i <= 5; ++i)
   //{
	  // for (int j = 1; j <= 5; ++j)
	  // {
		 //  int k = 0;
		 //  while (k < i*j)
		 //  {
			//   out << i << " " << j << " " << k << endl;
			//   k++;
		 //  }
	  // }
   //}
   //return 0;
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
      outputFile << "Case #" << ++testCasesProcessed << ":\n";
	  processTestCase(inputFile, outputFile, testCasesProcessed == testCasesQty);
      if (testCasesProcessed == testCasesQty)
         break;
   }
  // outputFile << endl << impossibleAmount;
	return 0;
}


