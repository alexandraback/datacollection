#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <algorithm>
#include <set>
#include <list>
#include <stack>
#include <cstdio>
#include <sstream>
#include <map>
#include <cmath>
#include <queue>
#include <ctime>

#define FOR(i,n) for(int i = 0; i < (n); ++i)
#define SZ(x) ((int)((x).size()))

using namespace std;

typedef long long int LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<bool> VB;
typedef vector<VB> VVB;
typedef vector<double> VD;
typedef vector<VD> VVD;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;

VD negPowerTwo(3000);
VVD choose (3000,VD(3000));

// chance of k success from n tries
double binom(int n, int k) {
	if (n >= 3000 || k >= 3000) cerr << "ERROR!\n";
	return choose[n][k] * negPowerTwo[n];
}

int main() {

	negPowerTwo[0] = 1.0;
	FOR(i,3000-1) negPowerTwo[i+1] = negPowerTwo[i] / 2.0;
	FOR(i,3000) choose[i][0] = 1.0;
	FOR(i,3000) choose[i][i] = 1.0;
	FOR(i,3000) for (int j = 1; j < i; ++j) choose[i][j] = choose[i-1][j-1] + choose[i-1][j];

	ifstream fin("b1.in");
	ofstream fout("b1.out");
	int t;
	fin >> t;

	for (int tt = 1; tt <= t; ++tt) {
		int n,x,y;
		fin >> n >> x >> y;
		int level = ((x < 0 ? -x : x) + y) / 2;
		double res;
		int nStartLevel = (level == 0 ? 0 : (2*(level-1)*(level-1) + 3*(level-1) + 1));
		int nEndLevel = 2*level*level + 3*level + 1;
		if (n <= nStartLevel) {
			res = 0.0;
		} else if (n >= nEndLevel) {
			res = 1.0;
		} else {
			int nLevel = nEndLevel - nStartLevel;
			if (nLevel != level*4 + 1) cerr << "ERROR!\n";
			int nLevelDown = n - nStartLevel;
			int minOnEachSide = nLevelDown > nLevel / 2
					? nLevelDown - nLevel / 2
					: 0;
			if (nLevelDown <= y || y == 2*level) {
				res = 0.0;
			} else if (minOnEachSide > y) {
				res = 1.0;
			} else {
				int unsure = nLevelDown - minOnEachSide*2;
				int needed = y - minOnEachSide + 1;
				// compute prob.
				res = 0.0;
				for (int k = unsure; k >= needed; --k)
					res += binom(unsure,k);
			}
		}

		fout << "Case #" << tt << ": " << res << "\n";
	}
	fin.close();
	fout.close();
	return 0;
}
