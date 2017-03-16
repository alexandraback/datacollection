#include <bits/stdc++.h>

using namespace std;

string a[16];
string b[16];
bool good[16][16][2];
int f[1 << 16];

int main() {
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  freopen("log", "w", stderr);
  int tt;
  scanf("%d", &tt);
  for (int cc = 1; cc <= tt; ++cc) {
    printf("Case #%d: ", cc);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        good[i][j][0] = (a[i] == a[j]);
        good[i][j][1] = (b[i] == b[j]);
      }
    }
    for (int i = 0; i < (1 << n); ++i) {
      f[i] = 0;
      for (int j = 0; j < n; ++j) {
        if ((i >> j) & 1) {
          int x = 0, y = 0;
          for (int k = 0; k < n; ++k) {
            if (k == j) {
              continue;
            }
            if ((i >> k) & 1) {
              if (good[j][k][0]) {
                x = 1;
              }
              if (good[j][k][1]) {
                y = 1;
              }
            }
          }
          f[i] = max(f[i], f[i ^ (1 << j)] + (x & y));
        }
      }
    }
    printf("%d\n", f[(1 << n) - 1]);
  }
  return 0;
}
