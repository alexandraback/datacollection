#include <bits/stdc++.h>

using namespace std;

struct Initializer {
  Initializer() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    cout << fixed << setprecision(15);
  }
} initializer;

void solve() {
  int64_t b, m;
  cin >> b >> m;
  if ((1ll << (b - 2)) < m) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }
  cout << "POSSIBLE" << endl;
  vector<vector<int>> res(b, vector<int>(b));
  for (int i = 0; i < b; ++i) {
    for (int j = i + 1; j < b; ++j) {
      res[i][j] = 1;
    }
  }
  int64_t r = (1ll << (b - 2)) - m;
  for (int i = 0; i < b - 2; ++i) {
    if (r & 1ll << i) res[i + 1][b - 1] = 0;
  }
  for (int i = 0; i < b; ++i) {
    for (int j = 0; j < b; ++j) {
      cout << res[i][j];
    }
    cout << endl;
  }
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    cout << "Case #" << i + 1 << ": ";
    solve();
  }
}
