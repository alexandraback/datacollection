#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REP1(i, n) for (int i = 1; i <= (n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define CLR(x, n) memset(x, n, sizeof(x))
using namespace std;

void setIO(string name) {
	string in_f = name + ".in";
	string out_f = name + ".out";
	freopen(in_f.c_str(), "r", stdin);
	freopen(out_f.c_str(), "w", stdout);
}

int e, r, n;
int dp[10010][20];
int v[100010];

void init() {
	scanf("%d%d%d", &e, &r, &n);
	REP1(i, n) scanf("%d", v + i);
	CLR(dp, 0);
}

void solve() {
	REP1(i, n) REP(j, e + 1) {
		int rest = min(j + r, e);
		int t = 0;
		while (j + t <= e) dp[i][rest] = max(dp[i][rest], dp[i - 1][j + t] + t * v[i]), ++t;
	}
	int ans0 = 0;
	REP(i, e + 1) ans0 = max(ans0, dp[n][i]);
	printf("%d\n", ans0);
}

int main() {
	setIO("2");
	int TT;
	cin >> TT;
	REP1(i, TT) {
		printf("Case #%d: ", i);
		init();
		solve();
	}
	return 0;
}
