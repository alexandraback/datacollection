#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <math.h>
#include <algorithm>
#include <list>

#define uint64 unsigned long long
#define uint32 unsigned int

using namespace std;

ifstream inFile;
ofstream outFile;

uint32 rows, columns, Ts, Dots, datasetSize;
uint32 lawn[100][100] = {0};
uint32 rowMax[100] = {0};
uint32 columnMax[100] = {0};
string line;

void resetMax(void)
{
	for(uint32 i = 0; i < 100; i++)
	{
		rowMax[i] = 0;
		columnMax[i] = 0;
	}
}

void fillData(void)
{
	inFile >> rows;
	cout << rows << "\n";
	inFile >> columns;
	for(uint32 r = 0; r < rows; r++)
	{
		for(uint32 c = 0; c < columns; c++)
		{
			inFile >> lawn[r][c];
			
			if (rowMax[r] < lawn[r][c])
				rowMax[r] = lawn[r][c];
			if (columnMax[c] < lawn[r][c])
				columnMax[c] = lawn[r][c];
		}
	}
}

string isPossible(void)
{
	for(uint32 r = 0; r < rows; r++)
	{
		for(uint32 c = 0; c < columns; c++)
		{
			if (lawn[r][c] < rowMax[r] && lawn[r][c] < columnMax[c])
			{
				return "NO";
			}
		}
	}
	return "YES";
}

int main(int argc, char* argv[])
{
	// Check if filename parameter is passed
	if(argc < 3)
	{
		outFile << "No files passed!\n";
		return 1;
	}
	
	inFile.open(argv[1]);
	outFile.open(argv[2]);
	inFile >> datasetSize;
	//getline(inFile, line);// Get rid of newline
	
	clock_t start = clock();
	for(uint32 i = 0; i < datasetSize; i++)
	{
		
		fillData();
		outFile << "Case #" << i+1 << ": ";
		outFile << isPossible() << "\n";
		resetMax();
	}
	
	cout << "Time taken: " << (float)(clock()-start)/CLOCKS_PER_SEC << "\n";
	
	inFile.close();
	outFile.close();
	
	return 0;
}