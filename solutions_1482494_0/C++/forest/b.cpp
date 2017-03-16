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

int n;
int a[1050], b[1050];

int solve() {
	GI(n);
	FI GI2(a[i], b[i]);

	int todo = n;
	int res = 0, t = 0;
	while (todo) {
		bool done = false;
		FI if (b[i] <= t) {
			done = true;
			--n;
			if(a[i] < 100000000) t += 2; else ++t;
			swap(a[n], a[i]);
			swap(b[n], b[i]);
			
			--todo;
			++res;
			break;
		}
		if (done) continue;

		int best = -1;
		FI if (a[i] <= t && (best < 0 || b[i] > b[best]))
			best = i;

		if (best < 0)
			return -1;

		a[best] = 100000000;
		++t;
		++res;

	}

	return res;

}

int main() {
//freopen("input.txt", "rt", stdin);
freopen("B-small-attempt2.in", "rt", stdin);
freopen("B-small-attempt2.out", "w", stdout);

	int tc; GI(tc);
	FORE(ntc, 1, tc) {
		int res = solve();
		
		if (res < 0)
			printf("Case #%d: Too Bad\n", ntc);
		else
			printf("Case #%d: %d\n", ntc, res);
	}

	

}
