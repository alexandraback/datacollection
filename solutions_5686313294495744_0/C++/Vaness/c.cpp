#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> g;
vector<int> mt;
vector<char> used;

bool try_kuhn(int v) {
  if (used[v]) {
    return false;
  }
  used[v] = true;
  for (int i = 0; i < g[v].size(); ++i) {
    int to = g[v][i];
    if (mt[to] == -1 || try_kuhn(mt[to])) {
      mt[to] = v;
      return true;
    }
  }
  return false;
}

int solve() {
  int N;
  cin >> N;
  vector<pair<string, string>> v(N);
  vector<string> f(N), s(N);
  for (int i = 0; i < N; ++i) {
    cin >> v[i].first >> v[i].second;
    f[i] = v[i].first;
    s[i] = v[i].second;
  }
  map<string, int> nf;
  for (const string& str : f) {
    if (!nf.count(str)) {
      int c = nf.size();
      nf[str] = c;
    }
  }
  map<string, int> ns;
  for (const string& str : s) {
    if (!ns.count(str)) {
      int c = ns.size();
      ns[str] = c;
    }
  }

  g.clear();
  g.resize(nf.size());
  for (int i = 0; i < N; ++i) {
    g[nf[v[i].first]].push_back(ns[v[i].second]);
  }
  mt.assign(ns.size(), -1);
  for (int i = 0; i < nf.size(); ++i) {
    used.assign(nf.size(), false);
    try_kuhn(i);
  }

  int cnt = 0;
  for (int i = 0; i < ns.size(); ++i) {
    cnt += mt[i] != -1;
  }
  int cnt1 = cnt;
  cnt += nf.size() - cnt1;
  cnt += ns.size() - cnt1;
  return N - cnt;
}

int main() {
  int T;
  cin >> T;
  for (int test = 1; test <= T; ++test) {
    printf("Case #%d: %d\n", test, solve());
  }
}
