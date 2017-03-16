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

const int MaxN = 100005, MaxC = 0x3F3F3F3F, NA = -1;
const char p [MaxN] = "abcdefghijklmnopqrstuvwxyz";
const char q [MaxN] = "yhesocvxduiglbkrztnwjpfmaq";

char s [MaxN];
int n;

int main (void)
{
 int test, tests;
 int i;

 scanf (" %d ", &tests);
 for (test = 1; test <= tests; test++)
 {
  fgets (s, sizeof (s), stdin);
  n = strlen (s);
  for (i = 0; i < n; i++)
   if ('a' <= s[i] && s[i] <= 'z')
    s[i] = q[s[i] - 'a'];
  printf ("Case #%d: %s", test, s);
 }

 return 0;
}
