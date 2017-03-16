#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int t, n, m;
  cin >> t;
  int field[101][101], cols[101][101], rows[101][101];
  for (int i = 1; i <= t; ++i) {
    cin >> n >> m;
    for (int h = 0; h <= 100; ++h) {
      for (int j = 0; j < n; ++j)
        cols[j][h] = 0;
      for (int k = 0; k < m; ++k)
        rows[k][h] = 0;
    }
    for (int j = 0; j < n; ++j)
      for (int k = 0; k < m; ++k) {
        cin >> field[j][k];
        cols[j][field[j][k] - 1] += 1;
        rows[k][field[j][k] - 1] += 1;
      }
    for (int h = 1; h <= 100; ++h) {
      for (int j = 0; j < n; ++j)
        cols[j][h] += cols[j][h - 1];
      for (int k = 0; k < m; ++k)
        rows[k][h] += rows[k][h - 1];
    }
    // if (i == 37) {
      // for (int j = 0; j < n; ++j) {
        // for (int k = 0; k < m; ++k)
          // cout << field[j][k] << ' ';
        // cout << '\n';
      // }
    // }
    bool result = true;
    for (int j = 0; j < n; ++j)
      for (int k = 0; k < m; ++k) {
        if (cols[j][field[j][k] - 1] < m && rows[k][field[j][k] - 1] < n) {
          result &= false;
        }
      }
    cout << "Case #" << i << ": " << (result ? "YES" : "NO") << '\n';
  }
  return 0;
}
