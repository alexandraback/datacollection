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
const uint32 cacheSize = 41;
uint64 datasetSize, fairSquareTable[cacheSize] = {0};
//string line;

bool isPalindrome(uint64 nr)
{
	uint64 /*digits = 0,*/ tmp = nr, reverse = 0;
	unsigned char digValue = 0;
	while(tmp > 0)
	{	
		reverse *= 10;
		reverse += tmp % 10;
		tmp /= 10;
		//++digits;
	}
	return (reverse == nr);
}
void precomputePalindromeTable(void)
{
	uint64 sq, i = 0;
	for(uint64 n = 0; n <= 10000001; n++)
	{
		sq = n*n;
		if (isPalindrome(n) && isPalindrome(sq))
		{
			fairSquareTable[i++] = sq;
		}
	}
}

uint32 sum(uint64 a, uint64 b)
{
	uint32 acc = 0;
	for(uint32 i = 0; i < cacheSize; ++i)
	{
		if(fairSquareTable[i] <= b && fairSquareTable[i] >= a)
		{
			acc++;
		}
	}
	return acc;
}

int main(int argc, char* argv[])
{
	clock_t start = clock();
	precomputePalindromeTable();
	cout << "Time taken to precompute Palindrome table: " << (float)(clock()-start)/CLOCKS_PER_SEC << "\n";
		
	// Check if filename parameter is passed
	if(argc < 3)
	{
		outFile << "No files passed!\n";
		return 1;
	}

	inFile.open(argv[1]);
	outFile.open(argv[2]);
	inFile >> datasetSize;
	
	uint64 a, b;
	start = clock();
	for(uint32 i = 0; i < datasetSize; i++)
	{
		inFile >> a >> b;
		//cout << " " << sum(a,b) << "\n";
		outFile << "Case #" << i+1 << ": " << sum(a,b) << "\n";
	}
	
	cout << "Time taken: " << (float)(clock()-start)/CLOCKS_PER_SEC << "\n";
	
	inFile.close();
	outFile.close();

	return 0;
}