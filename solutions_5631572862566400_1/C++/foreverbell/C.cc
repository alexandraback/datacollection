#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
const int maxint = 0x7f7f7f7f, mod = 1000000007;
const double eps = 1e-8, pi = acos(-1.0);

void rd() { }
template<typename... T> void rd(int &h, T &... t) { scanf("%d", &h); rd(t...); }
template<typename... T> void rd(long long &h, T &... t) { scanf("%lld", &h); rd(t...); }
template<typename... T> void rd(double &h, T &... t) { scanf("%lf", &h); rd(t...); }

const int maxN = 1111;
int n, best[maxN], cyc_len[maxN];
int stamp[maxN], vis[maxN];
vector<int> edges[maxN];
int dp[maxN];

void dfs(int u, int cur) {
  vis[u] = true;
  if (stamp[u] != -1) {
    int len = cur - stamp[u];
    cyc_len[u] = len;
    int v = best[u];
    while (v != u) {
      cyc_len[v] = len;
      v = best[v];
    }
  } else {
    stamp[u] = cur;
    dfs(best[u], cur+1);
  }
}

int rec(int u, int pa, int must) {
  int best = 0, must_v = 0;
  for (int v : edges[u]) {
    if (v == pa) continue;
    rec(v, u, -1);
    if (v == must) {
      must_v = dp[v];
    } else best = max(best, dp[v]);
  }
  dp[u] = best+must_v+1;
  return dp[u];
}

int solve() {
  memset(cyc_len, 0, sizeof(cyc_len));
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; ++i) {
    if (!vis[i]) {
      memset(stamp, -1, sizeof(stamp));
      dfs(i, 1);
    }
  }
  int result = 0;
  for (int i = 1; i <= n; ++i) {
    result = max(result, cyc_len[i]);
  }
  for (int i = 1; i <= n; ++i) {
    edges[i].clear();
  }
  for (int i = 1; i <= n; ++i) {
    edges[best[i]].push_back(i);
  }
  int sum = 0;
  for (int i = 1; i <= n; ++i) {
    if (cyc_len[i] != 2) continue;
    int j = best[i];
    if (i > j) continue;
    memset(dp, 0, sizeof(dp));
    int a1 = rec(i, -1, j);
    memset(dp, 0, sizeof(dp));
    int a2 = rec(j, -1, i);
    sum += max(a1, a2);
  }
  return max(sum, result);
}

int main() {
  int tests;

//  freopen("C-small-attempt0.in", "r", stdin);
  freopen("C-large.in", "r", stdin);
  
  rd(tests);
  for (int tt = 1; tt <= tests; ++tt) {
    printf("Case #%d: ", tt);
    cerr << tt << endl;
    rd(n);
    for (int i = 1; i <= n; ++i) {
      rd(best[i]);
    }
    printf("%d\n", solve());
  }
  return 0;
}
