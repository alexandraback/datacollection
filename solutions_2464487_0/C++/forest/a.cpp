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
#include <cmath>

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

const double P = acos(-1.0);

LL solve() {
	unsigned LL r, S;
	cin >> r >> S;
	
	
	double gL = 0, gR = S;
	REP(k, 300) {
		double mid = (gL+gR)/2;
		if ((2*r+1)*mid + 2*mid*(mid-1) <= (double)S )
			gL = mid;
		else gR = mid;
	}

	unsigned LL n = gL;
	while ( (2*r+1)*n + 2*n*(n-1) > S ) --n;
	while ( (2*r+1)*n + 2*n*(n-1) <= S ) ++n;
	return n-1;
}

int main() {
//freopen("input.txt", "rt", stdin);
freopen("A-small-attempt0.in", "rt", stdin);
freopen("A-small-attempt0.out", "w", stdout);

	int ntc; GI(ntc);
	FORE(tc, 1, ntc) {
		LL res = solve();
		printf("Case #%d: ", tc);
		cout << res << endl;
	}
}
