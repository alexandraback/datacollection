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

int q[111];
int n;

int solve() {
	LL a; cin >> a >> n;
	FI GI(q[i]);
	
	sort(q, q +n);
	int add = 0;
	int p = 0;
	while (p < n && q[p] < a) {
		a += q[p++];
	}
	int res = n-p;
	if (a == 1) return res;
	while (p < n) {
		add ++;
		a += a-1;
		while (p < n && q[p] < a) {
			a += q[p++];
		}
		res = min(res, n-p + add);
	}

	return res;
}

int main() {
//freopen("input.txt", "rt", stdin);
freopen("A-large.in", "rt", stdin);
freopen("A-large.out", "w", stdout);

	int ntc; GI(ntc);
	FORE(tc, 1, ntc) {
		int res = solve();
		printf("Case #%d: %d\n", tc, res);
		cerr << res << endl;
	}
}
