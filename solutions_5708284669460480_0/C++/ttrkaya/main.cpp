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

ofstream fout("monkey.out");
ifstream fin("monkey.in");

const int MAX_N = 7;

int numKeys;
string keys;

int wordLength;
string word;

int numStrokes;

int numRes;
int maxFound;
int totFound;
char d[MAX_N];
void f(int at)
{
	if (at == numStrokes)
	{
		int numFound = 0;
		for (int i = 0; i <= numStrokes - wordLength; i++)
		{
			bool found = true;
			for (int j = 0; j < wordLength; j++)
			{
				if (d[i + j] != word[j])
				{
					found = false;
					break;
				}
			}
			if (found)
			{
				numFound++;
			}
		}
		numRes++;
		totFound += numFound;
		maxFound = max(maxFound, numFound);
		return;
	}

	for (int i = 0; i < numKeys; i++)
	{
		d[at] = keys[i];
		f(at + 1);
	}
}

double solve()
{
	numRes = 0;
	maxFound = 0;
	totFound = 0;
	f(0);

	if (totFound == 0) return 0.0;

	double res = maxFound - (double)totFound / (double)numRes;

	return res;
}

int main()
{
	fout << fixed << setprecision(9);

	int numTests;
	fin >> numTests;
	for (int i = 1; i <= numTests; i++)
	{
		fin >> numKeys >> wordLength >> numStrokes >> keys >> word;
		fout << "Case #" << i << ": " << solve() << endl;
	}

	return 0;
}

/*



*/