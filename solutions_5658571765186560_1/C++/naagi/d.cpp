#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int mn[] = {0, 0, 0, 2, 3, 4, 4};
int mx[] = {0, 1, 2, 3, 4, 5, 6};
              
int main (void)
{
  int test, tests;
  scanf ("%d", &tests);
  for (test = 0; test < tests; test++)
  {
    int x,r,c, res = 1;
    scanf ("%d %d %d", &x, &r, &c);
    if (r * c % x != 0)
      res = 0;
    if (x >= 7)
      res = 0;
    else if (min (r, c) < mn[x] || max (r, c) < mx[x])
      res = 0;

    printf ("Case #%d: %s\n", test + 1, res? "GABRIEL":"RICHARD");
  }
  return 0;
}
