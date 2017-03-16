#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <queue>
#include <memory.h>

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;

#define FOR(i,a,n) for (int i = (a); i < (n); ++i)
#define FORE(i,a,n) for (int i = (a); i <= (n); ++i)
#define FORD(i,a,b) for (int i = (a); i >= (b); --i)
#define REP(i,n) FOR(i,0,n)
#define REPE(i,n) FORE(i,0,n)
#define LL long long
#define FIR(n) REP(i,n)
#define FJR(n) REP(j,n)
#define ALL(v) v.begin(), v.end()

#define FI FIR(n)
#define FJ FJR(n)
#define FR(i,a) FOR(i,a,n)
#define REPN(i) REP(i,n)

#define GI(n) scanf("%d", &n)
#define GI2(n,m) scanf("%d %d", &n, &m)

double f[5000];
double next[5000];

double solve() {
	int n, x, y;
	GI(n); GI2(x, y);
	if (x < 0) x= -x;
	int round = 1;
	int sum = 1, last_sum = 0;
	while (sum < n) {
		last_sum = sum;
		sum += 2*round + 2*round+1;
		++round;
	}

	
	int eround = 1+(x+y) / 2;
	if (eround < round)
		return 1;
	if (eround > round)
		return 0;


	int t = n - last_sum;
	--round;
	
	int L = 2*round;
	if (y == L)
		return t == 2*L + 1 ? 1 : 0;

	memset(f, 0, sizeof f);
	f[0] = 1;
	
	FOR(step, 0, t) {
		FORE(i, 0, L)
			next[i] = 0;
		FORE(i, 0, step) {
			if (i == L) {
				next[i] += f[i];
				break;
			}
			
			int other = step - i;
			if (other == L)
				next[i+1] += f[i];
			else {
				next[i+1] += f[i] * 0.5;
				next[i] += f[i] * 0.5;
			}
			
		}
		FORE(i, 0, L)
			f[i] = next[i];
	}

	double res = 0;
	FORE(i,y+1, L)
		res += f[i];
	return res;
}

int main() {
//freopen("input.txt", "rt", stdin);
freopen("B-large.in", "rt", stdin);
freopen("B-large.out", "w", stdout);

	int ntc; GI(ntc);
	FORE(tc, 1, ntc) {
		double res = solve();
		printf("Case #%d: %.8lf\n", tc, res);
	}
}
