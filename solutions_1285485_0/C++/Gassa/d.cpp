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

const int MaxN = 32, MaxC = 0x3F3F3F3F, NA = -1;

char a [MaxN] [MaxN];
int w, h, d, cx, cy;

bool go (int x, int y)
{
 int dx, dy, mx, my, px, py, e, e1, e2, e3;

 eprintf ("go %3d %3d\n", x, y);

 if (x == 0 && y == 0)
  return false;

 dx = x > 0 ? +1 : -1;
 dy = y > 0 ? +1 : -1;
 mx = cx;
 my = cy;
 px = 0;
 py = 0;
 e = 0;

 while (px != x || py != y)
 {
  e1 = e + abs (y);
  e2 = e - abs (x);
  e3 = e + abs (y) - abs (x);

  if (e3 + e == 0)
  {
   eprintf ("3\n");
   if (a[mx + dx][my + dy] == '#')
   {
    if (a[mx + dx][my] == '#' && a[mx][my + dy] == '#')
    {
     dx = -dx;
     dy = -dy;
    }
    else if (a[mx + dx][my] == '#')
    {
     dx = -dx;
     my += dy;
    }
    else if (a[mx][my + dy] == '#')
    {
     mx += dx;
     dy = -dy;
    }
    else
    {
     return false;
    }
   }
   else
   {
    mx += dx;
    my += dy;
   }
   px += (x > 0 ? +1 : -1);
   py += (y > 0 ? +1 : -1);
   e = e3;
  }
  else if (abs (e2) < abs (e1))
  {
   eprintf ("2\n");
   if (a[mx][my + dy] == '#')
    dy = -dy;
   else
    my += dy;
   py += (y > 0 ? +1 : -1);
   e = e2;
  }
  else if (abs (e1) < abs (e2))
  {
   eprintf ("1\n");
   if (a[mx + dx][my] == '#')
    dx = -dx;
   else
    mx += dx;
   px += (x > 0 ? +1 : -1);
   e = e1;
  }
  else
  {
   assert (false);
  }

  eprintf ("%3d %3d: %+d %+d, %3d %3d, %3d %3d, %3d %3d %3d %3d\n",
   x, y, dx, dy, px, py, mx, my, e, e1, e2, e3);
  if (e == 0)
  {
   if (mx == cx && my == cy)
    if (px == x && py == y && e == 0)
     eprintf ("!\n");
   if (mx == cx && my == cy)
    return (px == x && py == y && e == 0);
  }
 }

 assert (e == 0);
 assert (!(mx == cx && my == cy));

 return false;
}

int main (void)
{
 int test, tests;
 int i, j, res;

 scanf (" %d ", &tests);
 for (test = 1; test <= tests; test++)
 {
  scanf (" %d %d %d", &h, &w, &d);
  cx = cy = NA;
  memset (a, '#', sizeof (a));
  for (i = 1; i <= h; i++)
   for (j = 1; j <= w; j++)
   {
    scanf (" %c", &a[i][j]);
    if (a[i][j] == 'X')
    {
     cx = i;
     cy = j;
    }
   }

  res = 0;
  for (i = -d; i <= +d; i++)
   for (j = -d; j <= +d; j++)
    if (i * i + j * j <= d * d)
     res += go (i, j);

  printf ("Case #%d: %d\n", test, res);
 }

 return 0;
}
