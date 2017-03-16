#include <cstdio>
#include <cmath>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;

inline void solve () {
  int x,y;
  scanf ("%d %d", &x, &y);

  while (x > 0) {
    printf ("WE");
    x --;
  }
  while (x < 0) {
    printf ("EW");
    x ++;
  }
  while (y > 0) {
    printf ("SN");
    y --;
  }
  while (y < 0) {
    printf ("NS");
    y ++;
  }
  printf ("\n");
}

int main () {
  int test;
  scanf ("%d", &test);

  for (int Case = 1;Case <= test;Case ++) {
    printf ("Case #%d: ", Case);
    solve ();
  }
}
