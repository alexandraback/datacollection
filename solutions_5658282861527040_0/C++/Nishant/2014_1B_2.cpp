// CookieClicker.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <iomanip>

using namespace std;

unsigned int Solve(unsigned int  A, unsigned int B, unsigned int K)
{
	unsigned int ret = 0;

	for (unsigned int i = 0; i < A; ++i)
	{
		for (unsigned int j = 0; j < B; ++j)
		{
			if ((i&j) < K)
			{

				++ret;
			}
		}
	}

	return ret;
}

int _tmain(int argc, _TCHAR* argv [])
{
	ifstream ifs;
	ofstream ofs;
	ifs.open("c:\\GCJ_Inputs\\2014_1B_2\\input.in", ifstream::in);
	ofs.open("c:\\GCJ_Inputs\\2014_1B_2\\output.out", ifstream::out);

	if (!ifs)
	{
		cout << "Error reading input" << endl;
		return 0;
	}

	if (!ofs)
	{
		cout << "Error opening output" << endl;
		return 0;
	}

	cout << "STARTING" << endl;

	unsigned int numTests = 0;
	ifs >> numTests;

	for (unsigned int i = 0; i < numTests; ++i)
	{
		cout << "..";

		unsigned int A, B, K = 0;
		ifs >> A;
		ifs >> B;
		ifs >> K;


		unsigned int ret = Solve(A, B, K);
		ofs << "Case #" + std::to_string(i + 1) + ": ";
		ofs << ret << endl;
	}

	cout << endl;
	cout << "COMPLETE" << endl;

	ofs.close();
	ifs.close();

	return 0;
}

