#include <iostream>
#include <cstring>
using namespace std;
const int kBufSize = 110;

int process(char *p) {
  char *b = p;
  while (*p) {
    *p = *p == '+' ? 0 : 1;
    ++p;
  }
  return p - b;
}

int solve(char *b, int n) {
  for (int round = 0;; ++round) {
    int i = n - 1;
    while (i >= 0 && !b[i]) --i;
    if (i < 0) return round;
    if (!b[0]) {
      ++round;
      int t = 0;
      while (t < n && !b[t]) b[t++] = true;
    }
    for (int p = 0, q = i; p <= q; ++p, --q) {
      bool pv = !b[p], qv = !b[q];
      b[p] = qv; b[q] = pv;
    }
  }
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 1; i <= t; ++i) {
    char buf[kBufSize];
    scanf("%s", buf);
    int n = process(buf);
    printf("Case #%d: %d\n", i, solve(buf, n));
  }
  return 0;
}
