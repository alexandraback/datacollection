#include <cstdio>
#include <cstring>

#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <queue>

using namespace std;
typedef long long llint;
const llint inf = 1000000000000000000LL;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)

#define TRACE(x) cerr << #x << " = " << x << endl
#define _ << " _ " <<

namespace Dinic {
  const int MAXV = 1000100;
  const int MAXE = 1000100;
  const llint oo = 1e18;

  int V, E;
  int last[MAXV], dist[MAXV], curr[MAXV];
  int next[MAXE], adj[MAXE]; llint cap[MAXE];

  void init(int n) {
    V = n;
    E = 0;
    REP(i, V) last[i] = -1;
  }

  void edge(int x, int y, llint c1, llint c2) {
    adj[E] = y; cap[E] = c1; next[E] = last[x]; last[x] = E++;
    adj[E] = x; cap[E] = c2; next[E] = last[y]; last[y] = E++;
  }

  llint push(int x, int sink, llint flow) {
    if (x == sink) return flow;

    for (int &e = curr[x]; e != -1; e = next[e]) {
      int y = adj[e];

      if (cap[e] && dist[x] + 1 == dist[y])
        if (llint f = push(y, sink, min(flow, cap[e])))
          return cap[e] -= f, cap[e^1] += f, f;
    }
    return 0;
  }

  llint run(int src, int sink) {
    llint ret = 0;
    for (;;) {
      REP(i, V) curr[i] = last[i];
      REP(i, V) dist[i] = -1;

      queue<int> Q;
      Q.push(src), dist[src] = 0;

      while (!Q.empty()) {
        int x = Q.front(); Q.pop();

        for (int e = last[x]; e != -1; e = next[e]) {
          int y = adj[e];
          if (cap[e] && dist[y] == -1) Q.push(y), dist[y] = dist[x] + 1;
        }
      }
      if (dist[sink] == -1) break;

      while (llint f = push(src, sink, oo)) ret += f;
    }
    return ret;
  }
}

void solve() {
  int n;
  scanf("%d", &n);

  map< string, int > idm;
  int cid = 0;

  auto id = [&](string s) {
    if (!idm.count(s))
      idm[s] = cid++;
    return idm[s];
  };

  int source = 2 * n;
  int sink = 2 * n + 1;

  Dinic::init(2 * n + 2);

  set< int > l, r;

  REP(i, n) {
    string sa, sb;
    cin >> sa >> sb;
    sa += "$";

    int a = id(sa); l.insert(a);
    int b = id(sb); r.insert(b);

    Dinic::edge(a, b, 1, 0);
  }

  for (int i : l) Dinic::edge(source, i, 1, 0);
  for (int i : r) Dinic::edge(i, sink, 1, 0);

  int L = (int)l.size();
  int R = (int)r.size();
  int M = (int)Dinic::run(source, sink);

  printf("%d\n", n - L - R + M);
}

int main(void) 
{
  int T;
  scanf("%d", &T);
  FOR(i, 1, T + 1) {
    printf("Case #%d: ", i);
    solve();
  }

  return 0;
}

