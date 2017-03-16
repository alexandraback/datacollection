/*
 * Codejam 2013: Round 1A
 * Author: Mahmoud Aladdin (aladdin3)
 * 
 */
 
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <deque>
#include <stack>
#include <ctime>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <utility>
#include <sstream>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

typedef long long _int64;
typedef vector<int> _vi;
typedef vector<_int64> _vll;
typedef vector<string> _vs;

#define MX(a, b) ((a) > (b)? (a): (b))
#define MN(a, b) ((a) < (b)? (a): (b))
#define ABS(x) (((x) < 0)? -(x): (x))

#define ALL(V) (V).begin(), (V).end()
#define SZ(V) ((int)(V).size())
#define VPSH(V, X) (V).push_back(X)
#define REVA(V, S) reverse(V, V + s)
#define REV(V) reverse(ALL(V))

#define BTST(X, i) ((X) & (1 << (i)))
#define BSET(X, i) (X) |= (1 << (i))
#define BCLR(X, i) (X) &= ~(1 << (i))
#define BFLP(X, i) (X) ^= (1 << (i))

#define FOR(i, a, b, step) for(int (i) = (a); (((step) < 0)? ((i) > (b)): ((i) < (b))); (i) += (step)) 
#define REP(i, n) FOR(i, 0, n, 1)

#define filename_in "B.in"
#define filename_out "B.out"

#define MAX_E 6
#define MAX_N 11
int grid[MAX_E][MAX_N];
int vals[MAX_N];

int E, R, N;

int solve(int remE, int actNum) {
	if(actNum == N) {
		return 0;
	} else {
		if(grid[remE][actNum] != -1) return grid[remE][actNum];
		int maxGain = 0;
		for(int e = remE; e >= 0; e--) {
			int tempGain = e * vals[actNum];
			int trem = remE - e + R;
			trem = MN(E, trem);
			tempGain += solve(trem, actNum + 1);
			maxGain = MX(tempGain, maxGain);
		}
		return grid[remE][actNum] = maxGain;
	}
}

int main() {
	FILE *fin = fopen(filename_in, "r");
	FILE *fout = fopen(filename_out, "w");

	int TC; fscanf(fin, "%d", &TC);
	REP(tt, TC) {
		memset(grid, -1, sizeof grid);
		memset(vals, -1, sizeof vals);
		fscanf(fin, "%d %d %d", &E, &R, &N);
		
		REP(i, N) {
			fscanf(fin, "%d", vals + i);
		}
		
		int gain = solve(E, 0);
		fprintf(fout, "Case #%d: %d\n", tt + 1, gain);
		printf("Case #%d: %d\n", tt + 1, gain);
	}

	fclose(fin);
	fclose(fout);
	return 0;
}
