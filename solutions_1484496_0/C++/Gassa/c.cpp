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

/* start RNG */
const unsigned int RAND_MULT = 1664525, RAND_ADD = 1013904223;
unsigned int currand = 0;
void initrand (int value) {currand = value;}
inline void nextrand (void) {currand = (currand * RAND_MULT) + RAND_ADD;}
inline unsigned int rndvalue (void) {nextrand (); return currand;}
inline int rndvalue (int range) {return (((int64) rndvalue ()) * range) >> 32;}
/* end RNG */

const int MaxN = 1003, MaxC = 0x3F3F3F3F, NA = -1;
const int STEPS = 10, AMOUNT = 1000000;

int64 a [MaxN];
int64 u [MaxN];
int p [MaxN];
int n, m, k;

template <class T> void shuffle (T * a, int n)
{
 int i, k;
 for (i = 0; i < n; i++)
 {
  k = rndvalue (i + 1);
  swap (a[i], a[k]);
 }
}

void gen (int64 * a)
{
 int i;
 for (i = 0; i < m; i++)
  p[i] = i;
 shuffle (p, m);
 for (i = 0; i < k; i++)
  u[i] = a[p[i]];
}

int main (void)
{
 int test, tests;
 int i, j, r;
 unsigned int cr;
 int64 sum, x;

 initrand (128957);
 scanf (" %d ", &tests);
 for (test = 1; test <= tests; test++)
 {
  scanf (" %d", &n);
  for (i = 0; i < n; i++)
   scanf (" " INT64, &a[i]);
  m = n >> 1;
  k = m >> 1;

  printf ("Case #%d:\n", test);
  x = NA;
  map <int64, unsigned int> f, g;
  for (i = 0; i < STEPS; i++)
  {
   f.clear ();
   g.clear ();
   shuffle (a, n);

   for (r = 0; r < AMOUNT; r++)
   {
    cr = currand;
    gen (a);
    sum = 0;
    for (j = 0; j < k; j++)
     sum += u[j];
    f[sum] = cr;

    cr = currand;
    gen (a + m);
    sum = 0;
    for (j = 0; j < k; j++)
     sum += u[j];
    g[sum] = cr;
   }

   map <int64, unsigned int>::iterator it;
   for (it = f.begin (); it != f.end (); it++)
    if (g.find (it -> first) != g.end ())
     break;
   if (it != f.end ())
   {
    x = it -> first;
    break;
   }
  }
  if (i == STEPS)
  {
   printf ("Impossible\n");
  }
  else
  {
   initrand (f[x]);
   gen (a);
   for (j = 0; j < k; j++)
    printf (INT64 "%c", u[j], "\n "[j + 1 < k]);
   initrand (g[x]);
   gen (a + m);
   for (j = 0; j < k; j++)
    printf (INT64 "%c", u[j], "\n "[j + 1 < k]);
  }
  fflush (stdout);
 }

 return 0;
}
