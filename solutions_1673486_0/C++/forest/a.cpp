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

double p_corr[100500], p[100500], f[100500];
int n;

double solve() {
	int A, n; GI2(A, n); 
	FIR(A) scanf("%lf", &p_corr[i]);
	p[0]=1;
	FIR(A) p[i+1] = p[i]*p_corr[i];
	
	f[0] = n+1;
	FORE(i, 1, A) {
		f[i] = p[i] * (n-i + 1) + (1-p[i])*(n-i+n+2);
		f[i] = min(f[i], 1 + f[i-1]);
		f[i] = min(f[i], n+2.0);
	}

	return f[A];
}

int main() {
freopen("A-small-attempt0.in", "rt", stdin);
freopen("A-small-attempt0.out", "w", stdout);

	int tc; GI(tc);
	FORE(ntc, 1, tc) {
		double res = solve();
		printf("Case #%d: %.8lf\n", ntc, res);
	}
}
