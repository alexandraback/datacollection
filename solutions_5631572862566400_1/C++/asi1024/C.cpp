#include <bits/stdc++.h>

#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()

using namespace std;

int depth(const vector<vector<int>> &t, int v, int w) {
  int res = 1;
  for (int i: t[v]) {
    if (i == w) continue;
    res = max(res, depth(t, i, w) + 1);
  }
  return res;
}

int solve() {
  int N, res = 0;
  cin >> N;
  vector<int> f(N);
  vector<vector<int>> t(N);
  REP(i,N) {
    cin >> f[i];
    --f[i];
    t[f[i]].push_back(i);
  }
  vector<pair<int,int>> p;
  REP(i,N) {
    if (f[f[i]] == i) p.emplace_back(i, f[i]);
  }
  REP(i,N) {
    map<int,int> memo;
    int v = i;
    REP(j,100000) {
      if (memo.count(v)) {
        res = max(res, j - memo[v]);
        break;
      }
      memo[v] = j;
      v = f[v];
    }
  }
  int sum = 0;
  for (auto q: p) {
    sum += depth(t, q.first, q.second) + depth(t, q.second, q.first);
  }
  return max(res, sum / 2);
}

int main() {
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    cout << "Case #" << cas << ": ";
    cout << solve() << endl;
  }
  return 0;
}
