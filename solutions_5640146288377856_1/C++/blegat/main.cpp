#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <utility>

using namespace std;

#define ABS(x) (((x) < 0) ? (-(x)) : (x))
#define MIN(a,b) (((a) < (b)) ? (a) : (x))
#define MAX(a,b) (((a) > (b)) ? (a) : (x))

int main (void) {
  int T;
  scanf("%d", &T);
  for (int currentcase = 1; currentcase <= T; ++currentcase) {
    int r, c, w;
    scanf("%d %d %d", &r, &c, &w);
    int best = r * (c / w) + w;
    if ((c % w) == 0) {
      best--;
    }
    printf("Case #%d: %d\n", currentcase, best);
  }
  return 0;
}
