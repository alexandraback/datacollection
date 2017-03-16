#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>
#include <climits>
#include <cfloat>

using namespace std;

typedef long long ll;

ofstream fout("coin.out");
ifstream fin("coin.in");

const int MAX_V = 30;
int v;

bool has[MAX_V + 1];

int solve(int added = 0)
{
	vector<bool> canReach(v + 1);
	canReach[0] = true;
	for (int c = 1; c <= v; c++)
	{
		if (!has[c]) continue;

		for (int to = v; to >= c; to--)
		{
			if (canReach[to - c]) 
				canReach[to] = true;
		}
	}

	for (int i = 1; i <= v; i++)
	{
		if (!canReach[i])
		{
			has[i] = true;
			return solve(added + 1);
		}
	}
	return added;
}

int main()
{
	fout << fixed << setprecision(9);

	int numTests;
	fin >> numTests;
	for (int i = 1; i <= numTests; i++)
	{
		int c, numGiven;
		fin >> c >> numGiven >> v;
		for (int j = 0; j < MAX_V; j++)
		{
			has[j] = false;
		}
		for (int j = 0; j < numGiven; j++)
		{
			int g;
			fin >> g;
			has[g] = true;
		}
		fout << "Case #" << i << ": " << solve() << endl;
	}

	return 0;
}

/*



*/