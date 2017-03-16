// ConsoleApplication5.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"

#include <stdio.h>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <string>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
#include <array>

#include <iomanip>
#include <locale>
#include <sstream>
#include <string>
using namespace std;

//typedef long long LL;

int main() {
	ifstream inputFile;
	ofstream outputFile;
	inputFile.open("B.in");
	outputFile.open("B.out");

	int N =0;
	string deBuggerString;
	int nbrOfCases;
	int diff;
	
	inputFile >> nbrOfCases;

	int B; 

	for (int i42 = 1; i42 <= nbrOfCases; i42++)
	{
		//cout << "Case #" << i << ": ";
		//outputFile << "\n";
		//inputFile >> parties;

		int B;
		int M;
		inputFile >> B;
		inputFile >> M;
		int even = 0;
		string output = {};

		outputFile << "Case #" << i42 << ": ";

		if (M > pow(2, B-2))
		{
			outputFile << "IMPOSSIBLE" << "\n";

		}
		else
		{

			outputFile << "POSSIBLE" << "\n";
			


			M = M - 1;


			outputFile << 0;

			for (size_t ifirst = 1; ifirst < B-1; ifirst++)
			{
				outputFile << M % 2;
				M = M / 2;
			}
			outputFile << 1 << "\n";

			for (size_t iblocks = 1; iblocks < B-1; iblocks++)
			{

				outputFile << 0;
				for (size_t islides = 1; islides < B-1; islides++)
				{
					if (islides < iblocks)
					{
						outputFile <<1;
					}
					else
					{
						outputFile << 0;
					}
				}

				outputFile << 1 << "\n";
			}


			for (size_t ilast = 0; ilast < B ; ilast++)
			{
				outputFile << 0;
			}

			outputFile << "\n";


		}


//
///*
//		outputFile << "\n";
//*/
//		
	}
	std::cin >> N;
	//outputFile << "\n";
	inputFile.close();
	outputFile.close();
	return 0;
}