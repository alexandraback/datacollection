#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;
              
int main (void)
{
  int test, tests;

  freopen ("b.in", "rt", stdin);
  freopen ("b.out", "wt", stdout);

  scanf ("%d", &tests);
  for (test = 0; test < tests; test++)
  {
    int res = 0, A, B, K, i, j;
    scanf (" %d %d %d", &A, &B, &K);
    for (i = 0; i < A; i++)
      for (j = 0; j < B; j++)
        if ((i & j) < K)
          res++;
    printf ("Case #%d: %d\n", test + 1, res);
  }
  return 0;
}
