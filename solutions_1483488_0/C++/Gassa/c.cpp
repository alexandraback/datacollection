#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
typedef long double real;

#ifdef WIN32
#define INT64 "%I64d"
#define UINT64 "%I64u"
#else
#define INT64 "%lld"
#define UINT64 "%llu"
#endif

#ifdef DEBUG
#define eprintf(...) fprintf (stderr, __VA_ARGS__)
#else
#define eprintf(...) assert (true)
#endif

const int MaxN = 2000007, MaxC = 0x3F3F3F3F, NA = -1;

int a, b;

int main (void)
{
 int test, tests;
 int i, j, k, n, p, res;

 scanf (" %d ", &tests);
 for (test = 1; test <= tests; test++)
 {
  scanf (" %d %d", &a, &b);

  n = 0;
  for (k = a; k > 0; k /= 10)
   n++;
  p = 1;
  for (j = 1; j < n; j++)
   p *= 10;

  res = 0;
  for (i = a; i <= b; i++)
  {
   k = i;
   set <int> s;
   for (j = 0; j < n; j++)
   {
    k = (k / 10) + (k % 10) * p;
    if (i < k && k <= b && s.find (k) == s.end ())
    {
     s.insert (k);
     res++;
    }
   }
  }

  printf ("Case #%d: %d\n", test, res);
 }

 return 0;
}
