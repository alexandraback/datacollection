#include <cassert>
#include <cstdio>
#include <cstring>

#include <algorithm>

using namespace std;

long long flip( long long x ) {
  long long r = 0;
  while (x > 0) {
    r = r * 10 + (x % 10);
    x /= 10;
  }
  return r;
/*
  char s[20];
  sprintf (s, "%lld", x);
  int n = strlen (s);
  for (int i = 0; i + i < n; i++) {
    swap (s[i], s[n - 1 - i]);
  }
  sscanf (s, "%lld", &x);
  return x;
  */
}

int main() {
  int tn;
  assert (scanf ("%d", &tn) == 1);
  for (int t = 1; t <= tn; t++) {
    long long n, ans = -1;
    assert (scanf ("%lld", &n) == 1);
    if (n < 1000000) {
      int d[n + 1];
      memset (d, 0x7f, sizeof(d));
      d[0] = 0;
      for (int i = 0; i < n; i++) {
        d[i + 1] = min (d[i + 1], d[i] + 1);
        int x = flip (i);
        if (x > n)
          continue;
        d[x] = min (d[x], d[i] + 1);
      }
      ans = d[n];
    }

    long long res = 10, x = 10, k = 2, y = 10;
    while (x * 10 <= n) {
      res += y;
      if (k % 2 == 1)
        y *= 10;
      res += y - 1;
      k++;
      x *= 10;
    }

    // fprintf (stderr, "x=%lld, res=%lld\n", x, res);

    long long ans2 = -1;
    if (n < 10)
      ans2 = n;
    else {
      ans2 = n;
      ans2 = min (ans2, res + n - x);
      for (int i = 0; i < 110000000; i++) {
        long long y = flip (x + i);
        if (y > n)
          continue;
        ans2 = min (ans2, res + i + 1 + n - y);
      }
    }
    // fprintf (stderr, "ans2 = %lld\n", ans2);
    assert (ans == -1 || ans2 == ans);

    // fprintf (stderr, "Case #%d: %lld, diff=%lld\n", t, ans2, ans2 - res);
    printf ("Case #%d: %lld\n", t, ans2);
  }
  return 0;
}

