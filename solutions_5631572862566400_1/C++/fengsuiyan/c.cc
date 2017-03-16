#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
int f[N];
vector<int> g[N];
int op[N];
int vis[N];

int dfs(int v) {
  vis[v] = 1;
  int mx = 0;
  for (int i = 0; i < g[v].size(); ++i) {
    int u = g[v][i];
    if (!vis[u]) {
      mx = max(mx, dfs(u));
    }
  }
  return mx + 1;
}

int go(int v) {
  vector<int> vv;
  for (int i = v; !vis[i]; i = f[i]) {
    vis[i] = 1;
    vv.push_back(i);
  }
  for (int i = 0; i < vv.size(); ++i)
    vis[vv[i]] = 0;
  if (vv.size() >= 2 && f[vv.back()] == vv[0])
    return vv.size();
  return 0;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int _ = 1; _ <= t; ++_) {
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
      scanf("%d", f + i);
      g[i].clear();
    }
    vector<pair<int, int> > vop;
    memset(op, 0, sizeof(op));
    for (int i = 1; i <= n; ++i) {
      for (int j = i + 1; j <= n; ++j) {
        if (f[i] == j && f[j] == i) {
          op[i] = j;
          op[j] = i;
          vop.push_back(make_pair(i, j));
        }
      }
    }
    for (int i = 1; i <= n; ++i) {
      if (f[i] != op[i]) {
        g[f[i]].push_back(i);
      }
    }
    memset(vis, 0, sizeof(vis));
    int ans1 = 0;
    for (int i = 0; i < vop.size(); ++i) {
      pair<int, int> t = vop[i];
      int d1 = dfs(t.first);
      int d2 = dfs(t.second);
      ans1 += d1 + d2;
    }
    int ans2 = 0;
    for (int i = 1; i <= n; ++i) {
      if (!vis[i]) {
        ans2 = max(ans2, go(i));
      }
    }
    printf("Case #%d: %d\n", _, max(ans1, ans2));
  }
  return 0;
}
