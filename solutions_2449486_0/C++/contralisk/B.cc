#include <ctype.h>
#include <stdio.h>
#include <string.h>

const int MAX_LEN = 100;

int a[MAX_LEN][MAX_LEN];
int h[MAX_LEN];
int v[MAX_LEN];

int main() {
  int num_tests = 0;
  scanf("%d", &num_tests);
  for (int test = 1; test <= num_tests; ++test) {
    int n, m;
    scanf("%d%d", &n, &m);
    memset(h, 0, sizeof(h));
    memset(v, 0, sizeof(v));
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        scanf("%d", &a[i][j]);
        if (a[i][j] > h[i])
          h[i] = a[i][j];
        if (a[i][j] > v[j])
          v[j] = a[i][j];
      }
    }
    bool ok = true;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (a[i][j] < h[i] && a[i][j] < v[j]) {
          ok = false;
          break;
        }
    printf("Case #%d: %s\n", test, ok ? "YES": "NO");
  }
  return 0;
}
