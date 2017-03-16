// NewLotteryGame.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

unsigned int Solve(unsigned int A, unsigned int B, unsigned int K)
{
	unsigned int count = 0;
	for (unsigned int i = 0; i < A; ++i)
	{
		for (unsigned int j = 0; j < B; ++j)
		{
			count += (i & j) < K;
		}
	}
	return count;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream inputFile("B-small-attempt0.in");
	if (!inputFile.is_open())
	{
		cerr << "Error reading file" << endl;
		return 1;
	}

	int T;
	inputFile >> T;

	ofstream outputFile("output.txt");
	ostream &output = outputFile; //cout;
	for (int i = 0; i < T; ++i)
	{
		unsigned int A, B, K;
		inputFile >> A >> B >> K;

		unsigned int solution = Solve(A, B, K);
		output << "Case #" << (i+1) << ": " << solution << endl;
	}

	return 0;
}

