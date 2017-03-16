#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define P printf
#define S scanf
#define F(i, n) for(I i = 0; i < (n); i++)
#define I int

I count_occurences(const char *haystack, int haystack_len, const char *needle, int needle_len) {
  I ret = 0;
  F(i, haystack_len - needle_len + 1) {
    if(memcmp(haystack + i, needle, needle_len) == 0) {
      ret++;
    }
  }
  return ret;
}

I main() {
  I T; S("%d", &T);
  F(t, T) {
    I k, l, s;
    char ks[101], ls[101];
    S("%d %d %d %s %s", &k, &l, &s, ks, ls);

    int possibilities = pow(k, s);
    int max_count = 0;
    double total_count = 0;

    F(i, possibilities) {
      int _i = i;
      char attempt[10];
      F(j, s) {
        attempt[j] = ks[_i % k];
        _i /= k;
      }
      // P("%s - %d - %s - %d == %d\n", attempt, s, ls, l,
      //     count_occurences(attempt, s, ls, l));
      int now = count_occurences(attempt, s, ls, l);
      if(now > max_count) max_count = now;
      total_count += now;
    }

    // P("%d %f %d\n", max_count, total_count, possibilities);

    P("Case #%d: %.9f\n", t + 1, max_count - (total_count / (double)possibilities));
  }
}
