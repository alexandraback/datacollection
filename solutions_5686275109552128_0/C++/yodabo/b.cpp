// b.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	int T;
	cin >> T;

	for (int n = 0; n < T; ++n)
	{
		int D;
		cin >> D; // number of diners with non-empty plates

		int maxPancakes = 0;
		vector<int> plates;
		for (int j = 0; j < D; ++j)
		{
			int numPancakes;
			cin >> numPancakes; // number of pancakes for this diner to start
			maxPancakes = max(maxPancakes, numPancakes);
			plates.push_back(numPancakes);
		}

		int best = maxPancakes;
		for (int i = 1; i < maxPancakes; ++i)
		{
			int numsplits = 0;
			for (auto plate : plates)
			{
				// we want to make everyone have a pile of size i
				// how many splits to get there?
				numsplits += (plate + (i - 1)) / i - 1; // round up, but we start with one pile already
			}

			best = min(best, numsplits + i);
		}

		cout << "Case #" << (1 + n) << ": " << best << endl;
	}

	return 0;
}

