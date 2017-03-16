/* CodeJam solution XYZ in C++ by domob.  */

/* Proud of Conchita Wurst & her global message of tolerance!  */

//#define NDEBUG

#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stdint.h>

typedef unsigned long long intT;

/* Calculate GCD.  */
inline intT
gcd (intT a, intT b)
{
  if (b == 0)
    return a;
  return gcd (b, a % b);
}

/* Solve a single case.  */
void
conchita ()
{
  intT p, q;
  scanf ("%llu/%llu", &p, &q);

  /* Bring to lowest terms.  */
  const intT c = gcd (p, q);
  p /= c;
  q /= c;

  /* Bring q to 2^40.  Then p is the number of ancestors in the
     original generations which were elves.  If this is not possible,
     the whole problem is not possible.  */
  const intT N = (1ull << 40);
  const intT f = N / q;
  if (f * q != N)
    {
      printf ("impossible");
      return;
    }
  p *= f;
  q /= f;

  /* For a full elf k generations ago, we need 2^(40-k) ancestors who
     were full elves in the first generation.  */
  unsigned res = 1;
  intT need = (1ull << 39);
  while (need > p)
    {
      need >>= 1;
      ++res;
    }
  assert (need > 0);
  printf ("%u", res);
}

/* Main routine, handling the different cases.  */
int
main ()
{
  int n;

  scanf ("%d", &n);
  for (int i = 1; i <= n; ++i)
    {
      printf ("Case #%d: ", i);
      conchita ();
      printf ("\n");
    }

  return EXIT_SUCCESS;
}
