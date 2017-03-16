/* CodeJam solution password in C++ by domob.  */

/* Simply calculate the probability of success in each possibility.  This
   is rather straight-forward, simply by multiplying all success-probability
   of the characters that I will keep.  */

//#define NDEBUG

#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stdint.h>

typedef double realT;


/* Solve a single case.  */

void
solve_case ()
{
  unsigned A, B;
  std::cin >> A >> B;

  std::vector<realT> ps(A);
  for (unsigned i = 0; i < A; ++i)
    std::cin >> ps[i];

  /* Start with value needed if I completely retype.  */
  realT opt = 1.0 + B + 1.0;

  /* Try number of backspaces done.  */
  realT productOfPs = 1.0;
  for (unsigned numberKept = 0; numberKept <= A; ++numberKept)
    {
      if (numberKept > 0)
        productOfPs *= ps[numberKept - 1];
      const unsigned ifCorrect = (A - numberKept + B - numberKept + 1);
      const unsigned ifWrong = ifCorrect + B + 1;
      const realT currentExpect = productOfPs * ifCorrect
                                  + (1.0 - productOfPs) * ifWrong;
      if (currentExpect < opt)
        opt = currentExpect;
    }

  /* Output.  */
  printf ("%.12f", opt);
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
