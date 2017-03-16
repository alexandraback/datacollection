#include <cassert>
#include <cstdio>

//               1, -1,  i, -i,  j, -j,  k, -k
int mul_i[8] = { 2,  3,  1,  0,  7,  6,  4,  5};
int mul_j[8] = { 4,  5,  6,  7,  1,  0,  3,  2};
int mul_k[8] = { 6,  7,  5,  4,  2,  3,  1,  0};
char name[8][4] = {"1", "-1", "i", "-i", "j", "-j", "k", "-k"};
int r1 = 2, r2 = 6, r3 = 1;

int main() {
  int tn;
  assert (scanf ("%d", &tn) == 1);
  for (int t = 1; t <= tn; t++) {
    long long l, x;
    assert (scanf ("%lld%lld", &l, &x) == 2);
    if (x > 12) {
      x = 12 + x % 4;
    }
    int n = l * x;
    // fprintf (stderr, "l=%d, x=%d, n=%d\n", l, x, n);
    assert (n < 200000);
    char s[n + 1];
    assert (scanf ("%s", s) == 1);
    for (int i = l; i < n; i++)
      s[i] = s[i - l];
    s[n] = 0;
    int r = 0, rc = 0;
    for (int i = 0; i < n; i++) {
      // fprintf (stderr, "[i=%d] r=%d (%s)\n", i, r, name[r]);
      if (r == r1 && rc == 0)
        rc++;
      if (r == r2 && rc == 1)
        rc++;
      switch (s[i]) {
        case 'i': r = mul_i[r]; break;
        case 'j': r = mul_j[r]; break;
        case 'k': r = mul_k[r]; break;
      }
    }
    // fprintf (stderr, "r=%d (%s), rc=%d\n", r, name[r], rc);
    bool ans = r == r3 && rc == 2;
    printf ("Case #%d: %s\n", t, ans ? "YES" : "NO");
  }
  return 0;
}

