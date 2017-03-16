#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

vector<string> zip;

bool comp(int a, int b) { return zip[a] < zip[b]; }

bool check(vector<int>& S, int s, vector<bool> used, vector<vector<int> >& adj) {
  int maxim = -1;
  for (int i = 0; i < adj[s].size(); ++i) {
    int v = adj[s][i];
    for (int j = 0; j < S.size(); ++j) {
      if (S[j] == v) maxim = max(maxim, j);
    }
  }

  if (maxim == -1) return false;

  queue<int> Q;
  for (int i = 0; i <= maxim; ++i) Q.push(S[i]);
  Q.push(s);
  while (not Q.empty()) {
    int u = Q.front(); Q.pop();
    for (int i = 0; i < adj[u].size(); ++i) {
      int v = adj[u][i];
      if (not used[v]) {
        used[v] = true;
        Q.push(v);
      }
    }
  }
  if ( used == vector<bool>(used.size(), true) ) {
    S.resize(maxim + 1);
    S.push_back(s);
    return true;
  }
  return false;
}

string solve() {
  int n, m;
  cin >> n >> m;
  zip.resize(n);
  for (int i = 0; i < n; ++i) cin >> zip[i];

  vector<vector<int> > adj(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> sigma(n);
  for (int i = 0; i < n; ++i) sigma[i] = i;

  sort(sigma.begin(), sigma.end(), comp);

  string res;

  vector<bool> used(n, false);
  vector<int> S;

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (used[sigma[j]]) continue;
      if (j == 0 or check(S, sigma[j], used, adj)) {
        res += zip[sigma[j]];
        used[sigma[j]] = true;
        if (j == 0) S.push_back(sigma[j]);
        break;
      }
    }  
  }
  return res;
}

int main() {
  int casos;
  cin >> casos;
  for (int cas = 1; cas <= casos; ++cas) {
    cout << "Case #" << cas << ": " << solve() << endl;
  }
}
