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
      if (r*c%x || x >= 7 || (x+1)/2 > r || x > c) break;
      if (x == 4 && r == 2 && c >= 4) break;
      if (x == 5 && r == 3 && c == 5) break;
      if (x == 6 && r == 3) break;
      res = false;
    } while (0);
    printf("Case #%d: %s\n", cc, res ? "RICHARD" : "GABRIEL");
  }
}
