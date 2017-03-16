#include <cstdio>
#include <cassert>

const int maxN = 10000000;

int res[maxN + 1];

int rev (int i) {
  int res = 0;
  while (i > 0) {
    res = res * 10 + (i % 10);
    i /= 10;
  }
  return res;
}

void relax (int &a, int b) {
  if (a > b) {
    a = b;
  }
}

int main () {
  for (int i = 0; i <= maxN; ++i) {
    res[i] = maxN + 1;
  }
  res[1] = 1;
  int mm = res[1];
  for (int i = 1; i < maxN; ++i) {
    relax (res[i + 1], res[i] + 1);
    int j = rev (i);
    relax (res[j], res[i] + 1);
    if (res[i] > mm) {
      mm = res[i];
    }
  }
  printf ("%d\n", mm);
  int n, nt;
  assert (scanf ("%d", &nt) == 1);
  for (int tt = 1; tt <= nt; ++tt) {
    assert (scanf ("%d", &n) == 1);
    printf ("Case #%d: %d\n", tt, res[n]);
  }
  return 0;
}
