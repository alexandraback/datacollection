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

#define filename_in "A.in"
#define filename_out "A.out"


int solve(int r, int t) {
	int R = r; int ans = 0;
	while (t > 0) {
		int newR = (R + 1);
		int needed = (newR * newR) - (R * R);
		if(t >= needed) {
			ans++;
			t -= needed;
			R = newR + 1;
		} else {
			break;
		}
	}
	return ans;
}


int main() {
	FILE *fin = fopen(filename_in, "r");
	FILE *fout = fopen(filename_out, "w");

	int T; fscanf(fin, "%d", &T);
	REP(tt, T) {
		int r, t;
		fscanf(fin, "%d %d", &r, &t);
		int ans = solve(r, t);
		fprintf(fout, "Case #%d: %d\n", tt + 1, ans);
		
	}

	fclose(fin);
	fclose(fout);
	return 0;
}
