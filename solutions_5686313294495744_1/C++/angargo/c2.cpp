#include <bits/stdc++.h>
using namespace std;

using VI = vector<int>;
using VVI = vector<VI>;
using ll = long long;
using VL = vector<ll>;
using VVL = vector<VL>;
using P = pair<int, int>;
using VP = vector<P>;
using VVP = vector<VP>;

const ll INF = 1000000000000000000LL;

#define VEI(w,e) ((E[e].u == w) ? E[e].v : E[e].u)
#define CAP(w,e) ((E[e].u == w) ? E[e].cap[0] - E[e].flow : E[e].cap[1] + E[e].flow)
#define ADD(w,e,f) E[e].flow += ((E[e].u == w) ? (f) : (-(f)))

struct Edge {
  int u, v;
  ll cap[2], flow;
};

VI d, act;

bool bfs(int s, int t, VVI& adj, vector<Edge>& E) {
  queue<int> Q;
  d = VI(adj.size(), -1);
  d[t] = 0;
  Q.push(t);
  while (not Q.empty()) {
    int u = Q.front(); Q.pop();
    for (int i = 0; i < int(adj[u].size()); ++i) {
      int e = adj[u][i], v = VEI(u, e);
      if (CAP(v, e) > 0 and d[v] == -1) {
        d[v] = d[u] + 1;
        Q.push(v);
      }
    }
  }
  return d[s] >= 0;
}

ll dfs(int u, int t, ll bot, VVI& adj, vector<Edge>& E) {
  if (u == t) return bot;
  for (; act[u] < int(adj[u].size()); ++act[u]) {
    int e = adj[u][act[u]];
    if (CAP(u, e) > 0 and d[u] == d[VEI(u, e)] + 1) {
      ll inc = dfs(VEI(u, e), t, min(bot, CAP(u, e)), adj, E);
      if (inc) {
        ADD(u, e, inc);
        return inc;
      }
    }
  }
  return 0;
}

ll maxflow(int s, int t, VVI& adj, vector<Edge>& E) {
  for (int i = 0; i < int(E.size()); ++i) E[i].flow = 0;
  ll flow = 0, bot;
  while (bfs(s, t, adj, E)) {
    act = VI(adj.size(), 0);
    while ((bot = dfs(s, t, INF, adj, E))) flow += bot;
  }
  return flow;
}

void solve(int cas) {
  int n;
  cin >> n;
  int fc = 0, sc = 0;
  map<string, int> f, s;
  VI a(n), b(n);
  for (int i = 0; i < n; ++i) {
    string first, second;
    cin >> first >> second;
    int k1, k2;
    if (not f.count(first)) f[first] = fc++;
    k1 = f[first];
    if (not s.count(second)) s[second] = sc++;
    k2 = s[second];
    a[i] = k1; b[i] = k2;
  }

  vector<Edge> E;
  VVI adj(fc + sc + 2);
  int source = fc + sc, sink = source + 1;
  auto add_edge = [&](int u, int v) {
    Edge e;
    e.u = u;
    e.v = v;
    e.cap[0] = 1;
    e.cap[1] = 0;
    adj[u].push_back(E.size());
    adj[v].push_back(E.size());
    E.push_back(e);
  };

  for (int i = 0; i < fc; ++i) add_edge(source, i);
  for (int i = 0; i < n; ++i) add_edge(a[i], fc + b[i]);
  for (int i = 0; i < sc; ++i) add_edge(fc + i, sink);

  ll res = n - (fc + sc - maxflow(source, sink, adj, E));
  cout << "Case #" << cas << ": " << res << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) solve(i + 1);
}
