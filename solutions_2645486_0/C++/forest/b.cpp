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
#include <numeric>

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

void rLL(LL& e) { int r; GI(r); e=r;}

LL a[100000];

LL solve() {
	int E, R; GI2(E, R);
	int n; GI(n);
	FI rLL(a[i]);

	LL res = accumulate(a, a+n, 0LL)*R;
	return res +(*max_element(a, a+n))*(E-R);
}

int main() {
//freopen("input.txt", "rt", stdin);
freopen("B-small-attempt0.in", "rt", stdin);
freopen("B-small-attempt0.out", "w", stdout);

	int ntc; GI(ntc);
	FORE(tc, 1, ntc) {
		LL res = solve();
		printf("Case #%d: ", tc);
		cout << res << endl;
	}
}
