#include <cstdio>
#include <cassert>

const int maxN = 100;

int w, h;
int a[maxN][maxN];
int mh[maxN], mv[maxN];

int main() {
  int nt;
  assert (scanf ("%d", &nt) == 1);
  for (int tt = 1; tt <= nt; ++tt) {
    assert (scanf ("%d%d", &h, &w) == 2);
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        assert (scanf ("%d", &a[i][j]) == 1);
      }
    }
    for (int i = 0; i < h; ++i) {
      mh[i] = 0;
    }
    for (int i = 0; i < w; ++i) {
      mv[i] = 0;
    }
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (a[i][j] > mh[i]) {
          mh[i] = a[i][j];
        }
        if (a[i][j] > mv[j]) {
          mv[j] = a[i][j];
        }
      }
    }
    bool ok = true;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        if (a[i][j] != mh[i] && a[i][j] != mv[j]) {
          ok = false;
        }
      }
    }
    printf ("Case #%d: %s\n", tt, ok ? "YES" : "NO");
  }
  return 0;
}
