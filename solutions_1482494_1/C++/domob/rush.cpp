/* CodeJam solution rush in C++ by domob.  */

/* The only thing that makes him "save" competing some levels is by doing
   2-stars at the first attempt.  So we can do a greedy approach, and select
   an immediate 2-star completion where it is possible, and from the 1-star
   ones that with *highest* 2-star number needed, so that we have best hopes
   of completing one of the remaining options later in the first try with
   2 stars already.  */

//#define NDEBUG

#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <stdint.h>

typedef std::pair<unsigned, unsigned> levelT;
typedef std::vector<levelT> levelArr;


/* Solve a single case.  */

void
solve_case ()
{
  unsigned N;
  std::cin >> N;

  levelArr levels;
  for (unsigned i = 0; i < N; ++i)
    {
      levels.push_back (levelT ());
      std::cin >> levels.back ().first >> levels.back ().second;
    }

  std::vector<unsigned> gotStars(N, 0);
  unsigned haveStars = 0;
  unsigned cnt = 0;
  while (true)
    {
      /* Loop over all levels and find next one to solve.  */
      bool allSolved = true;
      int nextSolve = -1;
      for (unsigned i = 0; i < N; ++i)
        {
          assert (gotStars[i] <= 2);
          if (gotStars[i] == 2)
            continue;

          allSolved = false;
          if (levels[i].second <= haveStars)
            {
              nextSolve = i;
              break;
            }
          if (levels[i].first <= haveStars
              && gotStars[i] == 0
              && (nextSolve == -1
                  || levels[i].second > levels[nextSolve].second))
            nextSolve = i;
        }

      /* Do it.  */
      if (allSolved)
        {
          std::cout << cnt;
          break;
        }
      if (nextSolve == -1)
        {
          std::cout << "Too Bad";
          break;
        }
      ++cnt;
      if (levels[nextSolve].second <= haveStars)
        {
          haveStars += 2 - gotStars[nextSolve];
          gotStars[nextSolve] = 2;
        }
      else
        {
          assert (levels[nextSolve].first <= haveStars);
          assert (gotStars[nextSolve] == 0);
          ++haveStars;
          gotStars[nextSolve] = 1;
        }
    }
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
