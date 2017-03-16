/* CodeJam solution Counter Culture in C++ by domob.  */

//#define NDEBUG

#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <stdint.h>

/* Solution for small:  Just keep track of the minimum number
   required for each N.  Count up, and try reversing for each number.
   If this gives a smaller count for the resulting number, use that.  */
static const int64_t MAX_N = 1000000;
static int64_t haveCached = 0;
std::vector<int64_t> cache(MAX_N + 1, MAX_N + 1);

/* Reverse digits of a number.  */
int64_t reverseDigits (int64_t n)
{
  int64_t res = 0;
  while (n > 0)
    {
      res *= 10;
      res += (n % 10);
      n /= 10;
    }

  return res;
}

/* Solve a single case.  */
int64_t
solve_case ()
{
  int64_t n;
  std::cin >> n;
  assert (n <= MAX_N && n >= 1);

  if (n > haveCached)
    {
      for (int64_t i = haveCached + 1; i <= n; ++i)
        {
          cache[i] = std::min (cache[i], cache[i - 1] + 1);
          const int64_t rev = reverseDigits (i);
          if (rev <= MAX_N && cache[rev] > cache[i] + 1)
            {
              assert (rev > i);
              cache[rev] = cache[i] + 1;
            }
        }
      haveCached = n;
    }

  assert (n <= haveCached);
  return cache[n];
}

/* Main routine, handling the different cases.  */
int
main ()
{
  haveCached = 1;
  cache[1] = 1;

  unsigned n;

  std::cin >> n;
  for (unsigned i = 1; i <= n; ++i)
    std::cout << "Case #" << i << ": " << solve_case () << std::endl;

  return EXIT_SUCCESS;
}
