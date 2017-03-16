/* CodeJam solution motes in C++ by domob.  */

/* Clearly, it is always good to absorb all motes that can be absorbed, until
   you are stuck.  In that case, we have to decide on whether to remove all
   remaining motes, or create a new mote just smaller than the current size.
   So basically the question is simply: How often should we create new motes
   until we start removing all the remaining large ones?  Try that out, and
   the maximum number is of course limited by the number of motes in the game
   at large (since that's the maximum number we have to remove to get at least
   as good).  */

//#define NDEBUG

#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <deque>

typedef uint32_t moteT;
typedef std::deque<moteT> moteArr;

/* Absorb all motes as possible.  */
void
absorbAll (moteT& a, moteArr& others)
{
  while (true)
    {
      if (others.empty ())
        return;
      if (a <= others.front ())
        return;

      a += others.front ();
      others.pop_front ();
    }
}

/* Solve a single case.  */
void
solve_case ()
{
  moteT a;
  unsigned n;

  scanf ("%u %u\n", &a, &n);
  moteArr others;
  for (unsigned i = 0; i < n; ++i)
    {
      moteT cur;
      scanf ("%u", &cur);
      others.push_back (cur);
    }
  std::sort (others.begin (), others.end ());

  unsigned min = n;
  unsigned created = 0;
  while (created < min && !others.empty ())
    {
      absorbAll (a, others);
      unsigned cur = created + others.size ();
      if (cur < min)
        min = cur;

      ++created;
      a += a - 1;
    }

  printf ("%u", min);
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
