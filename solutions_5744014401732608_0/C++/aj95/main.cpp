// :)
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

vector<pair<int, int> > v;
vector<int> g[7];
int ans[7][7];
int w[7];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Users/Ayur/Downloads/B-small-attempt2.in.txt", "r", stdin);
  freopen("/Users/Ayur/Downloads/B-small-2.txt", "w", stdout);
  int t, tt, i, j, k, b, n;
  queue<int> Q;
  ll m;
  cin >> tt;
  for (t = 1; t <= tt; t++) {
    cout << "Case #" << t << ": ";
    cin >> b >> m;
    v.clear();
    for (i = 0; i < b; i++) {
      for (j = 0; j < b; j++) {
        ans[i][j] = 0;
        // g[i].clear();
        if (i == j || i == b - 1)
          continue;
        v.push_back({i, j});
      }
    }
    n = (int)v.size();
    for (i = 0; i < (1 << n); i++) {
      k = 0;
      for (j = 0; j < b; j++) {
        g[j].clear();
        w[j] = 0;
      }

      for (j = 0; j < n; j++) {
        if (i & (1 << j)) {
          g[v[j].first].push_back(v[j].second);
          if (v[j].second == b - 1)
            k = 1;
        }
      }
      if (k == 0)
        continue;
      while (!Q.empty())
        Q.pop();
      Q.push(0);
      w[0] = 1;
      int f = 1;
      while (!Q.empty()) {
        k = Q.front();
        Q.pop();
        if (w[k] > m) {
          f = 0;
          break;
        }
        for (j = 0; j < (int)g[k].size(); j++) {
          w[g[k][j]] += w[k];
          Q.push(g[k][j]);
        }
      }
      if (f && w[b - 1] == m) {
        break;
      }
    }
    if (i < (1 << n)) {
      for (i = 0; i < b; i++)
        for (j = 0; j < (int)g[i].size(); j++)
          ans[i][g[i][j]] = 1;
      cout << "POSSIBLE\n";
      for (i = 0; i < b; i++) {
        for (j = 0; j < b; j++)
          cout << ans[i][j];
        cout << '\n';
      }
    } else {
      cout << "IMPOSSIBLE\n";
    }
  }
  return 0;
}