#undef DEBUG

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) do ; while(0)
#define NDEBUG
#endif

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <set>

using namespace std;

int main ()
{
  int tests;

  scanf("%d\n", &tests);

  for (int test=1; test<=tests; test++) {
    // input
    int a, b;
    scanf("%d %d", &a, &b);
    // calculate
    unsigned long int result = 0;
    for (int m=a; m<=b; m++) {
      debug("considering %d\n", m);
      set<int> s;
      int d = 1;
      while (d*10<=m)
        d*=10;
      debug("  d = %d\n", d);
      for (int b=10; b<=m; b*=10, d/=10) {
        int t = m % b;
        int n = t * d + m / b;
        debug("  cut %d, recycled %d, ", t, n);
        if (a <= n && n < m) {
          s.insert(n);
          debug("added\n");
        }
        else
          debug("discarded\n");
      }
      result += s.size();
      debug("  total %d distinct numbers added\n", s.size());
    }
    // output
    printf("Case #%d: %lu\n", test, result);
  }
  return 0;
}
