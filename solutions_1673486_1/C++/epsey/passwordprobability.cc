
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <fstream>
#include <vector>
#include <iostream>



double CalculateP(int charsTyped, int passwdLen, std::vector<double> charP)
{
	std::vector<double> expectedResults;

	//case 1: keep typing
	double Pcorrect = 1.0;
	for (int i = 0; i < charP.size(); i++)
	{
		Pcorrect *= charP[i];
	}
	double keepTrying = ((passwdLen - charsTyped + 1.0) * Pcorrect) + 
		((1.0-Pcorrect) * (passwdLen - charsTyped + 1.0 + passwdLen + 1.0));
	expectedResults.push_back(keepTrying);

	//case 4: enter right away
	expectedResults.push_back(1 + passwdLen + 1);



	//case others: backaspace
	for (int num = 1; num <= charsTyped; num++)
	{
		Pcorrect = 1.0;
		for (int i = 0; i < charP.size() - num; i++)
		{
			Pcorrect *= charP[i];
		}

		int countIfCorrect = passwdLen - charsTyped + 1 + num + num;
		int countIfIncorrect = passwdLen - charsTyped + 1 + num + num + 1 + passwdLen;
		
		double ppp = (countIfCorrect * Pcorrect) + 
			(countIfIncorrect * (1.0 - Pcorrect));
		
		expectedResults.push_back(ppp);
	}
	

	//retun best result
	double bestResult = expectedResults[0];
	for (int i = 0; i < expectedResults.size(); i++)
	{
		if (expectedResults[i] < bestResult)
		{
			bestResult = expectedResults[i];
		}
	}
	return bestResult;
}


int main(int argc, char** argv)
{
	if (argc < 2)
	{
		printf("Please provide an input file\n");
		return 1;
	}
	std::fstream fin;
	fin.open(argv[1]);

	int testCases = 0;
	fin >> testCases;

	for (int i = 0; i < testCases; i++)
	{
		int A, B;
		fin >> A >> B;

		double p;
		std::vector<double> probabilities;
		for (int c = 0; c < A; c++)
		{
			fin >> p;
			probabilities.push_back(p);
		}

		printf("Case #%d: %10.10f\n", i+1, CalculateP(A,B,probabilities));
	}

	fin.close();
	return 0;
}
