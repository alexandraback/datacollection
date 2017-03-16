#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <sstream>
#include <vector>
 
using namespace std;
 
typedef vector<bool> VB; typedef vector<double> VD;
typedef vector<int> VI; typedef vector<string> VS;

typedef unsigned int uint;
typedef unsigned long long ull;

int main(void)
{
	string line;
	uint numTests;
	stringstream ss;

	getline(cin, line);
	ss << line;
	ss >> numTests;
	ss.clear();

	double probability[100001];
	double totalProbability[100001];

	for(uint testCase=0; testCase < numTests; testCase++)
	{
		int passwordLength = 0;
		int charsTyped = 0;

		getline(cin, line);
		ss << line;
		ss >> charsTyped;
		ss >> passwordLength;
		ss.clear();

		getline(cin, line);
		ss << line;
		for(int i=0;i<charsTyped;i++)
		{
			ss >> probability[i];
			totalProbability[i] = probability[i];
			if(i>0)
				totalProbability[i] *= totalProbability[i-1];
		}
		ss.clear();

#define asdf 0
#if asdf
		printf("p: ");
		for(int i=0;i<charsTyped;i++)
			printf("%f ", probability[i]);
		printf("\n");

		printf("tp: ");
		for(int i=0;i<charsTyped;i++)
			printf("%f ", totalProbability[i]);
		printf("\n");
#endif

		double res = 9999999;


		int enterChars = 1 + passwordLength + 1;
		double enterKeys = (double)enterChars;

		if(enterKeys < res)
			res = enterKeys;

#if asdf
		printf("enter = %d\n", enterChars);
#endif


		double goodChance = totalProbability[charsTyped-1];
		double badChance = 1.0 - goodChance;

		int goodChars = passwordLength - charsTyped + 1;
		int badChars = goodChars + passwordLength + 1;

		double finishKeys = badChance * (double)badChars;
		finishKeys += goodChance * (double)goodChars;

#if asdf
		printf("finish = (%f * %d) + (%0.04f * %d) = %0.04f\n", badChance, badChars, goodChance, goodChars, finishKeys);
#endif

		if(finishKeys < res)
			res = finishKeys;


		for(int i=0;i<charsTyped;i++)
		{
			int goodChars = charsTyped - i;
			goodChars += passwordLength - i;
			goodChars += 1;

			int badChars = goodChars + passwordLength + 1;

			double goodChance = 1.0;
			if(i > 0)
				goodChance = totalProbability[i-1];

			badChance = 1.0 - goodChance;

			double backspaceKeys = badChance * (double)badChars;
			backspaceKeys += goodChance * (double)goodChars;

#if asdf
			printf("bksp[%d] = (%f * %d) + (%0.04f * %d) = %0.04f\n", i, badChance, badChars, goodChance, goodChars, backspaceKeys);
#endif

			if(backspaceKeys < res)
				res = backspaceKeys;
		}


		cout << "Case #" << testCase+1 << ": ";// << res << endl;
		printf("%f\n", res);
	}

	return 0;
}

