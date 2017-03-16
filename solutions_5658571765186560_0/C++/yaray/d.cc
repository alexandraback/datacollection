#include <algorithm>
#include <cstdio>
using namespace std;

#define REP1(i, n) FOR(i, 1, n+1)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

int ri()
{
  int x;
  scanf("%d", &x);
  return x;
}

int main()
{
  int cases = ri();
  REP1(cc, cases) {
    int x = ri(), r = ri(), c = ri();
    bool res = true;
    if (r > c) swap(r, c);
    do {
      if (r*c%x) break;
      for (int i = (x+1)/2; i; i--)
        if (i > r || x+1-i > c)
          goto L1;
      if (x == 4 && r == 2 && c == 4) break;
      res = false;
L1:
      ;
    } while (0);
    printf("Case #%d: %s\n", cc, res ? "RICHARD" : "GABRIEL");
  }
}

/*
 *  ####
 *  ####
 *  ####
 */
