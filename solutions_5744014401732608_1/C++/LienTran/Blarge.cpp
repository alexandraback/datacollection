#include <bits/stdc++.h>

using namespace std;

#define sz(s) (int)s.size()

long long dp[51];
long long b, m;
bool mark[51][51];

void solve() {
    memset(mark, 0, sizeof mark);
    cin >> b >> m;
    long long test = m;
    dp[b - 1] = 1LL;
    for(int i = b - 2; i > 0; --i) {
        dp[i] = 0LL;
        for(int j = i + 1; j < b; ++j) {
            dp[i] += dp[j];
            mark[i][j] = true;
        }
    }
    for(int i = 1; i < b; ++i) {
        if (m < dp[i]) continue;
        m -= dp[i];
        mark[0][i] = true;
    }
    dp[b - 1] = 1LL;
    for(int i = b - 2; i >= 0; --i) {
        dp[i] = 0LL;
        for(int j = i + 1; j < b; ++j)
            if (mark[i][j]) dp[i] += dp[j];
    }
    if (m) printf("IMPOSSIBLE\n");
    else {
        printf("POSSIBLE\n");
        for(int i = 0; i < b; ++i) {
            for(int j = 0; j < b; ++j) printf("%d", mark[i][j]);
            printf("\n");
        }
        assert(test == dp[0]);
    }
}

int main() {
    freopen("in", "r", stdin);
    freopen("outLarge", "w", stdout);
	int ntest;
	scanf("%d", &ntest);
	for(int tc = 1; tc <= ntest; ++tc) {
		printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}
