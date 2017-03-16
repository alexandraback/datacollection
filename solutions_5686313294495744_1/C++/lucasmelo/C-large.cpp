#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define all(a) (a).begin(), (a).end()
#define in(a,b) ( (b).find(a) != (b).end())

int m;
map<string, int> idx1;
map<string, int> idx2;
int n1, n2;

#define MAX 1002

int edge[MAX][2];

struct MaxFlow {
  vector<vector<int> > adj;
  vector<vector<ll> > c;
  MaxFlow(int n) : adj(n), c(n, vector<ll>(n, 0)) {}
  ~MaxFlow() {}
  void add_edge(int u, int v, ll cap) {
    adj[u].push_back(v);
    adj[v].push_back(u);
    c[u][v] += cap;
  }

  ll maxflow(int s, int t) {
    ll ans = 0;
    int n = adj.size();
    vector<bool> V(n);
    vector<int> p(n);
    p[s] = -1;
    for (;;) {
      /* find augmenting path */
      {
        fill(all(V), false);
        queue<int> q;
        q.push(s);
        V[s] = true;
        while (!q.empty()) {
          int x = q.front();
          q.pop();
          if (x == t) break;
          for(auto v : adj[x]) {
            if (!V[v] && c[x][v] > 0) {
              V[v] = true;
              p[v] = x;
              q.push(v);
            }
          }
        }
      }
      /* augment it*/
      if (!V[t])
        break;
      else {
        int cur = t;
        ll mn = numeric_limits<ll>::max();
        while (p[cur] != -1) {
          mn = min(mn, c[p[cur]][cur]);
          cur = p[cur];
        }
        ans += mn;
        cur = t;
        while (p[cur] != -1) {
          c[p[cur]][cur] -= mn;
          c[cur][p[cur]] += mn;
          cur = p[cur];
        }
      }
    }
    return ans;
  }
};

int cnt1[MAX];
int cnt2[MAX];

int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  for (int cn = 1; cn <= t; cn++) {
    n1 = n2 = 0;

    cin >> m;
    for (int i = 0; i < m; ++i) {
      string a, b;
      cin >> a >> b;
      if (!in(a, idx1)) {
        idx1[a] = n1++;
      }
      if (!in(b, idx2)) {
        idx2[b] = n2++;
      }
      edge[i][0] = idx1[a];
      edge[i][1] = idx2[b];
    }

    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
    for (int i = 0; i < m; ++i) {
      cnt1[edge[i][0]]++;
      cnt2[edge[i][1]]++;
    }

    MaxFlow mf(1 + n1 + n2 + 1);

    for (int i = 0; i < n1; ++i) {
      mf.add_edge(0, 1 + i, cnt1[i] - 1);
    }
    for (int i = 0; i < n2; ++i) {
      mf.add_edge(1 + n1 + i, 1 + n1 + n2, cnt2[i] - 1);
    }
    for(int i=0; i < m; ++i) {
      mf.add_edge(1 + edge[i][0], 1 + n1 + edge[i][1], 1);
    }

    printf("Case #%d: %lld\n", cn, mf.maxflow(0, 1+n1+n2));
    idx1.clear();
    idx2.clear();
  }

  return 0;
}
