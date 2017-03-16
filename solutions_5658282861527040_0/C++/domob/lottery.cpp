/* CodeJam solution lottery in C++ by domob.  */

//#define NDEBUG

#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stdint.h>

/* Solve a single case.  */
void
solve_case ()
{
  unsigned long a, b, k;
  scanf ("%lu %lu %lu", &a, &b, &k);

  /* For small: Just try everything.  */
  unsigned long res = 0;
  for (unsigned ra = 0; ra < a; ++ra)
    for (unsigned rb = 0; rb < b; ++rb)
      if ((ra & rb) < k)
        ++res;

  printf ("%lu", res);
}

/* Main routine, handling the different cases.  */
int
main ()
{
  int n;

  scanf ("%d\n", &n);
  for (int i = 1; i <= n; ++i)
    {
      printf ("Case #%d: ", i);
      solve_case ();
      printf ("\n");
    }

  return EXIT_SUCCESS;
}
