#undef DEBUG

#ifdef DEBUG
#define debug(...) fprintf(stderr, __VA_ARGS__)
#else
#define debug(...) do ; while(0)
#define NDEBUG
#endif

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <vector>
#include <algorithm>

using namespace std;
typedef long double real;

int main ()
{
  int tests;

  scanf("%d\n", &tests);

  for (int test=1; test<=tests; test++) {
    // input
    int n;
    scanf("%d", &n);
    vector<int> s(n);
    int x = 0;
    int max = 0;
    for (int i=0; i<n; i++) {
      scanf("%d", &(s[i]));
      x += s[i];
      if (s[i] > max) max = s[i];
    }
    // calculate
    vector<real> y(n);
    int big = 0;
    int k = 0;
    for (int i=0; i<n; i++) {
      y[i] = (real) (2*x - n*s[i]) / (x * n);
      if (y[i] < 0) big += s[i]; else k++;
    }
    for (int i=0; i<n; i++)
      if (y[i] < 0.0)
        y[i] = 0.0;
      else
        y[i] = (real) (2*x - big - k*s[i]) / (x * k);
    // output
    printf("Case #%d:", test);
    for (int i=0; i<n; i++)
      printf(" %0.6Lf", y[i] >= 0 ? 100 * y[i] : 0.0);
    printf("\n");
  }
  return 0;
}
