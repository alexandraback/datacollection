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

#define Q 2000000

int best[Q+1];

int solve() {
	int A, B; cin >> A >> B;
	int res = 0;

	FORE(i, A, B) {
		int q = best[i];
		while (q<=B) {
			++res;
			q = best[q];
		}
	}

	return res;
}

#define  INF 1000000000

int main() {
freopen("C-large.in", "rt", stdin);
freopen("C-large.out", "w", stdout);

	FORE(t, 1, Q) {
		int d = 0;
		int m = 1;
		int tt = t;
		while (tt) tt/=10, ++d, m*=10;
		m /= 10;

		best[t]=INF;
		tt =t;
		while(--d) {
			int last = tt % 10;
			tt/=10;
			tt += m*last;
			if (tt > t && tt < best[t])
				best[t] =tt;
		}
	}


	int ntc; GI(ntc);
	FORE(tc, 1, ntc) {
		int res = solve();
		printf("Case #%d: %d\n", tc, res);
	}


}
