// {{{
#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define EB emplace_back
#define SZ(c) int((c).size())
#define ALL(c) (c).begin(),(c).end()
#define REP(i,n) for(int i=0;i<int(n);++i)
template<class T>inline void check_min(T&a,T b){if(b<a)a=b;}
template<class T>inline void check_max(T&a,T b){if(a<b)a=b;}
typedef long long lint;
typedef vector<int> VI;
typedef pair<int, int> PII;
// }}}

const int MAX_N = 1024;
int n, g[MAX_N];
int vis[MAX_N];
VI es[MAX_N];

int dfs(int u, int par, int dep) {
  int ret = dep;
  for (int v: es[u]) {
    if (v == par) continue;
    check_max(ret, dfs(v, u, dep + 1));
  }
  return ret;
}

int gao() {
  fill(es, es + MAX_N, VI());

  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &g[i]);
    es[g[i]].PB(i);
  }

  int ans = 0;
  for (int u = 1; u <= n; ++u) {
    if (g[g[u]] == u && u < g[u]) {
      ans += dfs(u, g[u], 1) + dfs(g[u], u, 1);
    }
  }

  for (int s = 1; s <= n; ++s) {
    fill(vis, vis + MAX_N, 0);

    int u = s;
    vis[u] = 1;
    while (!vis[g[u]]) {
      vis[g[u]] = vis[u] + 1;
      u = g[u];
    }

    check_max(ans, vis[u] - vis[g[u]] + 1);
  }

  return ans;
}

int main() {
  int n_case;
  scanf("%d", &n_case);
  for (int index = 1; index <= n_case; ++index) {
    printf("Case #%d: %d\n", index, gao());
  }
  return 0;
}
