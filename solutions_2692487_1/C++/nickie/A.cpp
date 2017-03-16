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
#include <vector>
#include <algorithm>

using namespace std;

int main ()
{
  int tests;
  scanf("%d\n", &tests);
  for (int test = 1; test <= tests; test++) {
    debug("\n-------------- test %d --------------------\n", test);
    int A, N;
    scanf("%d %d\n", &A, &N);
    vector<int> x(N);
    for (int i = 0; i < N; i++)
      scanf("%d", &(x[i]));
    sort(x.begin(), x.end());

    int p = 0;
    while (p < N && A > x[p]) {
      debug("eating %d for free\n", x[p]);
      A += x[p];
      p++;
    }
    int remaining = N-p;
    debug("possible with 0 + %d = %d\n", remaining, remaining);
    int best = remaining;
    int introduced = 0;
    while (p < N && A > 1) {
      while (A <= x[p]) {
        introduced++;
        debug("considering introducing max %d\n", A-1);
        A += A-1;
      }
      while (p < N && A > x[p]) {
        debug("eating %d\n", x[p]);
        A += x[p];
        p++;
      }
      int remaining = N-p;
      int possible = introduced + remaining;
      debug("possible with %d + %d = %d\n", introduced, remaining, possible);
      if (possible < best)
        best = possible;
    }
    printf("Case #%d: %d\n", test, best);
  }
  return 0;
}
