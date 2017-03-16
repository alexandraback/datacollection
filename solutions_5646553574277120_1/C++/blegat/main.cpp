#include <cstdio>
#include <cassert>
#include <cstring>
#include <algorithm>
#include <utility>
#include <stack>

using namespace std;

#define ABS(x) (((x) < 0) ? (-(x)) : (x))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))

long d[100];

long C, D, V;

int main (void) {
  int T;
  scanf("%d", &T);
  for (int currentcase = 1; currentcase <= T; ++currentcase) {
    scanf("%ld %ld %ld\n", &C, &D, &V);
    for (int i = 0; i < D; i++) {
      scanf("%d\n", &(d[i]));
    }
    std::sort(d, d+D);
    long max = 0;
    int i = 0;
    int best = 0;
    while (max < V) {
      if (i < D && d[i] <= max+1) {
        max += C * d[i];
        i++;
      } else {
        best++;
        max += C * (max+1);
      }
    }
    printf("Case #%d: %d\n", currentcase, best);
  }
  return 0;
}
