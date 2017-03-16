#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int n_tests;
  scanf("%d", &n_tests);
  for (int test = 1; test <= n_tests; ++test) {
    int R, E, n;
    scanf("%d %d %d", &E, &R, &n);
    int v[n];
    for (int i = 0; i < n; ++i) {
      scanf("%d", &v[i]);
    }
    int T[n][E + 1];
    for (int f = 0; f <= E; ++f) {
      T[n - 1][f] = v[n - 1] * f;
    }
    for (int i = n - 2; i >= 0; --i) {
      for (int f = 0; f <= E; ++f) {
        T[i][f] = -1;
        for (int x = 0; x <= f; ++x) {
          int tmp = x * v[i] + T[i + 1][min(f - x + R, E)];
          if (T[i][f] == -1 || tmp > T[i][f]) {
            T[i][f] = tmp;
          }
        }
      }
    }
    printf("Case #%d: %d\n", test, T[0][E]);
  }
  return 0;
}
