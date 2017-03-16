//============================================================================
// Name        : BEnergy.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> values;
int gMax;
int cur;
int E, R, N;


void brute_force(int step, int energy)
{
	if (step == values.size())
	{
		gMax = max(gMax, cur);
	}
	else
	{
		for (int i = 0; i <= energy; ++i)
		{
			cur += values[step] * i;
			brute_force(step + 1, min(E, energy - i + R));
			cur -= values[step] * i;
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int caseNum = 1; caseNum <= T; ++caseNum)
	{
		cin >> E >> R >> N;
		values = vector<int>(N);
		gMax = 0;
		cur = 0;
		for (int i = 0; i < N; ++i)
		{
			int Vi;
			cin >> Vi;
			values[i] = Vi;
		}

		brute_force(0, E);
		cout << "Case #" << caseNum << ": " << gMax << endl;
	}
}
