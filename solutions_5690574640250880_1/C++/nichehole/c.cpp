#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool f = 0;
int r, c, m;
char a[55][55];

bool solve() {
  if (m == 0) return 1;
  a[0][0] = 'c'; --m;
  if (m == 0) return 1;
  if (r <= 1) {
    a[0][1] = '.'; --m;
    for (int i = 2; m > 0 && i < c; ++i) {
      a[0][i] = '.'; --m;
    }
  } else if (r == 2) {
    if (!(m & 1)) return 0;
    else {
      a[1][0] = '.'; --m;
      if (m == 0) return c <= 1;
      a[0][1] = a[1][1] = '.';
      m -= 2;
      for (int i = 2; m > 0 && i < c; ++i) {
        a[0][i] = a[1][i] = '.';
        m -= 2;
      }
    }
  } else {
    if (m <= 2) return 0;
    else {
      a[1][0] = a[0][1] = a[1][1] = '.';
      m -= 3;
      if (m == 0) return 1;
      if (m == 1 || m == 3) return 0;
      for (int i = 2; m > 3 && i < c; ++i) {
        a[0][i] = a[1][i] = '.';
        m -= 2;
      }
      for (int i = 2; m >= 2 && i < r; ++i) {
        a[i][0] = a[i][1] = '.';
        m -= 2;
      }
      for (int i = 2; i < r; ++i) {
        for (int j = 2; j < c && m > 0; ++j) {
          a[i][j] = '.'; --m;
        }
      }
    }
  }
  return m == 0;
}

int main() {
  int T, cas = 0;
  scanf("%d", &T);
  while (T--) {
    memset(a, 0, sizeof(a));
    f = 0;
    scanf("%d%d%d", &r, &c, &m);
    m = r * c - m;
    printf("Case #%d:\n", ++cas);
    if (r > c) {
      swap(r, c); f = 1;
    }
    if (solve()) {
      int nr = f ? c : r;
      int nc = f ? r : c;
      for (int i = 0; i < nr; ++i) {
        for (int j = 0; j < nc; ++j) {
          char c = f ? a[j][i] : a[i][j];
          if (!c) printf("*");
          else printf("%c", c);
        } puts("");
      }
    } else {
      puts("Impossible");
    }
  }
  return 0;
}
