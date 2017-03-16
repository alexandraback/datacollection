#include <cstdio>
#include <algorithm>

using namespace std;

inline int solve () {
  int r,c,w;
  scanf ("%d %d %d", &r, &c, &w);

  return r*(c/w)+w-(c%w == 0);
}

int main () {
  int t;
  scanf ("%d", &t);

  for (int i = 1;i <= t;i ++) {
    printf ("Case #%d: %d\n", i, solve ());
  }
}
