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

ofstream fout("battle.out");
ifstream fin("battle.in");

const int MAX_N = 20;

int d[MAX_N][MAX_N][MAX_N];

/*int caseLast(int w, int s)
{
	int emptyLineW = w - s + 1;
	int emptyLineClearer = (emptyLineW + s - 1) / s;

	int res = emptyLineClearer - 1;
}

int caseBefore(int w, int s)
{

}*/

int solve(int h, int w, int s)
{
	if (s == 1) return h * w;

	int emptyLineW = w - s + 1;
	int emptyLineClearer = (emptyLineW + s - 1) / s;

	int res = emptyLineClearer * h + s - 1;

	
	if (emptyLineW % s != 1) res++;

	return res;
}

int main()
{
	int numTests;
	fin >> numTests;
	for (int i = 1; i <= numTests; i++)
	{
		int h, w, s;
		fin >> h >> w >> s;
		fout << "Case #" << i << ": " << solve(h, w, s) << endl;
	}

	return 0;
}

/*



*/