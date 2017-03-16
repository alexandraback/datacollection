#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <complex>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <iomanip>
#include <assert.h>
#include <array>
#include <cstdio>
#include <cstring>
#include <random>
#include <functional>
#include <numeric>
#include <bitset>
#include <fstream>

using namespace std;

struct before_main{before_main(){cin.tie(0); ios::sync_with_stdio(false);}} before_main;

#define REP(i,a,b) for(int i=a;i<(int)b;i++)
#define rep(i,n) REP(i,0,n)
#define all(c) (c).begin(), (c).end()
#define zero(a) memset(a, 0, sizeof a)
#define minus(a) memset(a, -1, sizeof a)
template<class T1, class T2> inline bool minimize(T1 &a, T2 b) { return b < a && (a = b, 1); }
template<class T1, class T2> inline bool maximize(T1 &a, T2 b) { return a < b && (a = b, 1); }

typedef long long ll;
int const inf = 1<<29;

int N;
vector<vector<string>> v;

namespace flow {  // not verified

struct edge {
  int to, cap, rev;
  edge(int t, int c, int r): to(t), cap(c), rev(r) {}
};

struct dinic {

  static constexpr int MaxV = 4400;

  vector<edge> G[MaxV];

  int level[MaxV];
  int iter[MaxV];

  void add_edge(int from, int to, int cap) {
    G[from].emplace_back(to, cap, G[to].size());
    G[to].emplace_back(from, 0, G[from].size()-1);
  }

  void bfs(int s) {
    minus(level);
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while(!q.empty()) {
      int v = q.front(); q.pop();
      for(auto && e: G[v]) {
        if(e.cap > 0 && level[e.to] < 0) {
          level[e.to] = level[v] + 1;
          q.push(e.to);
        }
      }
    }
  }

  int dfs(int v, int t, int f) {
    if(v == t) { return f; }
    for(auto && i = iter[v]; i < G[v].size(); i++) {
      auto && e = G[v][i];
      if(e.cap > 0 && level[v] < level[e.to]) {
        if(auto d = dfs(e.to, t, min(t, e.cap))) {
          e.cap -= d;
          G[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  int max_flow(int s, int t) {
    int flow = 0;
    for(;;) {
      bfs(s);
      if(level[t] < 0) { return flow; }
      zero(iter);
      for(int f;(f = dfs(s, t, inf)) > 0; flow += f);
    }
  }

};
}

int main() {

  int T; cin >> T;
  rep(_, T) {
    cout << "Case #" << _+1 << ": ";

    cin >> N;
    v.clear();
    v.resize(N, vector<string>(2));
    rep(i, N) {
      cin >> v[i][0] >> v[i][1];
    }

    flow::dinic dn;
    int S = 4004, T = 4005;
    rep(i, N) {
      dn.add_edge(S, i, 1);
      dn.add_edge(N*3+i, T, 1);
    }
    rep(i, N) rep(j, N) {
      if(i == j) { continue; }
      if(v[i][0] == v[j][0]) {
//        dn.add_edge(i, N+j, 1);dn.add_edge(N+j, 2*N+i, 1);
        dn.add_edge(i, 2*N+j, 1);
        rep(k, N) {
          if(i == k || j == k) { continue; }
          if(v[j][1] == v[k][1]) dn.add_edge(2*N+j, 3*N+k, 1);
        }
      }
    }
    /*
    rep(i, N) rep(j, N) {
      if(i == j) { continue; }
      if(v[i][1] == v[j][1]) dn.add_edge(N*2+i, N*3+j, 1);
    }
    */

    cout << dn.max_flow(S, T) << endl;
  }
  
  return 0;
}