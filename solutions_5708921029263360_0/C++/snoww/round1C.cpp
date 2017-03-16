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
	inputFile.open("C.in");
	outputFile.open("C.out");

	int N =0;
	string deBuggerString;
	int nbrOfCases;
	int diff;
	
	inputFile >> nbrOfCases;

	int partySize[26]; 

	for (int i42 = 1; i42 <= nbrOfCases; i42++)
	{
		//cout << "Case #" << i << ": ";
		//outputFile << "\n";
		//inputFile >> parties;
		int J = 0;
		int P = 0;
		int S = 0;
		int K = 0;
		inputFile >> J;
		inputFile >> P;
		inputFile >> S;
		inputFile >> K;
		int cJ = 1;
		int cP = 1;
		int cS = 1;

		outputFile << "Case #" << i42 << ": ";

		if (K >=S)
		{
			outputFile << J*P*S << "\n";
			for (size_t iJ = 1; iJ <= J; iJ++)
			{
				for (size_t iP = 1; iP <= P; iP++)
				{
					for (size_t iS = 1; iS <= S; iS++)
					{
						outputFile << iJ << " " << iP << " " << iS << "\n";
					}
				}
			}
		}
		else
		{


					outputFile << J*P*K << "\n";
					for (size_t iJ = 1; iJ <= J; iJ++)
					{
						for (size_t iP = 1; iP <= P; iP++)
						{
							for (size_t iS = 1; iS <= K; iS++)
							{
								cS = (iJ + iP + iS) % S;
								outputFile << iJ << " " << iP << " " << cS + 1 << "\n";
							}
						}
					}
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