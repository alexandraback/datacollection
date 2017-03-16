#include <stdio.h>
#include <algorithm>
#include <assert.h>
#include <set>
#include <map>
#include <complex>
#include <iostream>
#include <time.h>
#include <stack>
#include <stdlib.h>
#include <memory.h>
#include <bitset>
#include <math.h>
#include <string>
#include <string.h>
#include <queue>
#include <vector>

using namespace std;

const int MaxN = 1e5 + 10;
const int MOD = 1e9 + 7;
const int INF = 1e9;

int dp[1 << 16];
int fa[1 << 16], fb[1 << 16];
int mark[1 << 16], color;
int f[1 << 16];
vector < int > graph[1 << 16];

bool IS(int mask, int bit) {
  return (mask >> bit) & 1;
}

bool dfs(int v) {
  if (mark[v] == color) {
    return false;
  }
  mark[v] = color;
  for (int i = 0; i < (int)graph[v].size(); ++i) {
    int to = graph[v][i];
    if (f[to] == -1 || dfs(f[to])) {
      f[to] = v;
      return true;
    }
  }
  return false;
}

void solve() {
  int n;
  cin >> n;
  map < string, int > ma, mb;
  vector < pair < int, int > > all;
  int za[1234] = {}, zb[1234] = {};
  int ca = 0, cb = 0, add = 0;
  for (int i = 0; i < n; ++i) {
    string a, b;
    cin >> a >> b;
    if (!ma.count(a)) ma[a] = ++ca;
    if (!mb.count(b)) mb[b] = ++cb;
    all.push_back(make_pair(ma[a], mb[b]));
    za[ma[a]]++;
    zb[mb[b]]++;
  }
  struct Graph {
    struct Edge {
      int to, fl, cp, nx;
    };
    int n, m, s, t, pt, lo, hi;
    int * la, * ds, * ptr;
    Edge * e;
    Graph(int _n, int _m, int _s, int _t, int _lo, int _hi) {
      n = _n; m = _m; s = _s; t = _t; lo = _lo; hi = _hi;
      e = new Edge[2 * m + 100];
      la = new int[hi + 100];
      ds = new int[hi + 100];
      ptr = new int[hi + 100];
      for(int i = lo; i <= hi; ++i) {
        ptr[i] = la[i] = ds[i] = -1;
      }
      memset(e, 0, sizeof(e));
      pt = 0;
    }
    void add(int u, int v, int c) {
      e[pt].nx = la[u];
      e[pt].to = v;
      e[pt].cp = c;
      e[pt].fl = 0;
      la[u] = pt++;
      e[pt].nx = la[v];
      e[pt].to = u;
      e[pt].cp = c;
      e[pt].fl = c;
      la[v] = pt++;
    }
    bool bfs() {
      for(int i = lo; i <= hi; ++i) {
        ds[i] = -1;
        ptr[i] = la[i];
      }
      ds[s] = 0; queue < int > q;
      q.push(s);
      while(!q.empty()) {
        int v = q.front(); q.pop();
        for(int i = la[v]; i >= 0; i = e[i].nx) {
          int to = e[i].to;
          if(ds[to] == -1 && e[i].fl < e[i].cp) {
            ds[to] = ds[v] + 1;
            q.push(to);
          }
        }
      }
      return ds[t] != -1;
    }
    int dfs(int v, int flow) {
      if(v == t)
        return flow;
      for(int & i = ptr[v]; i >= 0; i = e[i].nx) {
        int to = e[i].to;
        if(ds[to] == ds[v] + 1 && e[i].fl < e[i].cp) {
          int ps = dfs(to, min(flow, e[i].cp - e[i].fl));
          if(ps != 0) {
            e[i].fl += ps;
            e[i ^ 1].fl -= ps;
            return ps;
          }
        }
      }
      return 0;
    }
    int GetFlow() {
      int flow = 0;
      while(bfs()) {
        while(int pushed = dfs(s, INF))
          flow += pushed;
      }
      return flow;
    }
  };
  int st = 0, tt = ca + cb + 1;
  Graph G = Graph(ca + cb + 2, 2 * ca * cb + ca + cb, st, tt, st, tt);
  for (int i = 1; i <= ca; ++i) {
    if (za[i] == 1) {
      continue;
    }
    G.add(st, i, za[i] - 1);
  }
  for (int i = 0; i < (int)all.size(); ++i) {
    G.add(all[i].first, ca + all[i].second, +1);
  }
  for (int i = 1; i <= cb; ++i) {
    if (zb[i] == 1) {
      continue;
    }
    G.add(ca + i, tt, zb[i] - 1);
  }
  int ans = G.GetFlow();
  printf("%d\n", ans);
}
/*
string get(int n, int len) {
  string res;
  while (n > 0) {
    res += (char)(n % 10 + '0');
    n /= 10;
  }
  while (res.length() < len) {
    res += "0";
  }
  return res;
}

bool can(string &a, string &b) {
  for (int i = 0; i < (int)a.size(); ++i) {
    if (a[i] == '?' || a[i] == b[i]) {
      continue;
    }
    return false;
  }
  return true;
}

void solve() {
  string a, b;
  cin >> a >> b;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  int bst = INF;
  pair < int, int > result = make_pair(INF, INF);
  int len = (int)a.length();
  string arr[1000];
  int to = (len == 1 ? 10 : len == 2 ? 100 : 1000);
  for (int i = 0; i < to; ++i) {
    arr[i] = get(i, len);
  }
  for (int i = 0; i < 1000; ++i) {
    string sa = arr[i];
    if (!can(a, sa)) continue;
    for (int j = 0; j < 1000; ++j) {
      if (bst < abs(i - j)) {
        continue;
      }
      string sb = arr[j];
      if (!can(b, sb)) continue;
      if (bst > abs(i - j) || bst == abs(i - j) && result > make_pair(i, j)) {
        bst = abs(i - j);
        result = make_pair(i, j);
      }
    }
  }
  reverse(arr[result.first].begin(), arr[result.first].end());
  if (result.second != result.first) {
    reverse(arr[result.second].begin(), arr[result.second].end());
  }
  cout << arr[result.first] << ' ' << arr[result.second] << endl;
}
*/
int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t;
  scanf("%d", &t);
  for (int ti = 1; ti <= t; ++ti) {
    printf("Case #%d: ", ti);
    solve();
  }
  return 0;
}
