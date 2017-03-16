#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
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

const int MaxN = 103, MaxC = 0x3F3F3F3F, NA = -1;

int f [MaxN] [MaxN];
int t [MaxN];
int n, s, p;

int main (void)
{
 int test, tests;
 int i, k;

 scanf (" %d ", &tests);
 for (test = 1; test <= tests; test++)
 {
  scanf (" %d %d %d", &n, &s, &p);
  for (i = 0; i < n; i++)
   scanf (" %d", &t[i]);

  k = 0;
  for (i = 0; i < n; i++)
   if ((t[i] + 2) / 3 >= p)
    k++;
   else if (s > 0 && t[i] >= 2 && (t[i] + 4) / 3 >= p)
   {
    k++;
    s--;
   }
  printf ("Case #%d: %d\n", test, k);
 }

 return 0;
}
