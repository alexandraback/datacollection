#include <cassert>
#include <cstdio>

int main() {
  int tn;
  assert(scanf("%d", &tn) == 1);
  for (int tt = 1; tt <= tn; tt++) {
    int A, B;
    assert(scanf("%d%d", &A, &B) == 2);
    int k = 1, a = A;
    while (a >= 10)
      k *= 10, a /= 10;
    int ans = 0;
    for (int n = A; n <= B; n++) {
      int m = n;
      do {
        if (m > n && m <= B)
          ans++;
        m = m / 10 + k * (m % 10);
      } while (m != n);
    }
    printf("Case #%d: %d\n", tt, ans);
  }
  return 0;
}

