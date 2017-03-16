#include <bits/stdc++.h>

using namespace std;

#define sz(s) (int)s.size()
#define rep(i, n) for(int i = 0, _ = (n); i < _; ++i)
#define ufor(i, a, b) for(int i = (a); _ = (b); i <= _; ++i)
#define dfor(i, a, b) for(int i = (a); _ = (b); i >= _; --i)

long long dp[51];
long long b, m;

void solve() {
    cin >> b >> m;
    vector< pair<int, int> > pairs;
    for(int i = 0; i < b; ++i)
        for(int j = i + 1; j < b; ++j) pairs.push_back(make_pair(i, j));
    bool mark[10][10];
    memset(mark, 0, sizeof mark);
    int nPair = sz(pairs);
    for(int mask = 0; mask < (1 << nPair); ++mask) {
        vector< vector<int> > g;
        g.resize(b);
        for(int i = 0; i < nPair; ++i)
            if ((mask >> i) & 1) {
                int from  = pairs[i].first;
                int to = pairs[i].second;
                g[from].push_back(to);
            }
        dp[b - 1] = 1LL;
        for(int i = b - 2; i >= 0; --i) {
            dp[i] = 0LL;
            for(int v : g[i]) dp[i] += dp[v];
        }
        if (dp[0] == m) {
            printf("POSSIBLE\n");
            for(int i = 0; i < b; ++i)
                for(int v : g[i]) mark[i][v] = true;
            rep(i, b) {
                rep(j, b) printf("%d", (int)mark[i][j]);
                printf("\n");
            }
            return;
        }
    }
    printf("IMPOSSIBLE\n");
}

int main() {
    freopen("in", "r", stdin);
    freopen("outSmall", "w", stdout);
	int ntest;
	scanf("%d", &ntest);
	for(int tc = 1; tc <= ntest; ++tc) {
		printf("Case #%d: ", tc);
		solve();
	}
	return 0;
}
