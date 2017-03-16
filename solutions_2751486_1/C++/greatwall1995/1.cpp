#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define REP1(i, n) for (int i = 1; i <= (n); ++i)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define CLR(x, n) memset(x, n, sizeof(x))
#define maxN 1000010
using namespace std;
typedef long long int64;

void setIO(string name) {
	string in_f = name + ".in";
	string out_f = name + ".out";
	freopen(in_f.c_str(), "r", stdin);
	freopen(out_f.c_str(), "w", stdout);
}

char str[maxN];
int L, n;
int64 dp[maxN];

void init() {
	str[0] = '0';
	scanf("%s%d", str + 1, &n);
	L = strlen(str) - 1;
	CLR(dp, 0);
}

void solve() {
	int t = 0, p = 0;
	REP1(i, L) {
		dp[i] = dp[i - 1];
		if (str[i] != 'a' && str[i] != 'e' && str[i] != 'i' && str[i] != 'o' && str[i] != 'u') ++t;
		else t = 0;
		if (t >= n) dp[i] += int64(i - n + 1 - p), p = i - n + 1;
	}
	int64 ans = 0;
	REP1(i, L) ans += dp[i];
	printf("%lld\n", ans);
}

int main() {
	setIO("1");
	int TT;
	cin >> TT;
	REP1(i, TT) {
		printf("Case #%d: ", i);
		init();
		solve();
	}
	return 0;
}
