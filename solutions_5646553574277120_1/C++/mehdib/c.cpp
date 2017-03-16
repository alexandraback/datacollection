#include <cstdio>
#include <algorithm>

using namespace std;

int main(void) {

  int T;
  scanf("%d", &T);

  for (int t = 1; t <= T; t++) {

    int C, D, V;
    scanf("%d%d%d", &C, &D, &V);

    int den[D];
    for (int d = 0; d < D; d++)
      scanf("%d", &den[d]);

    int res = 0;

    int mp = 0;
    int d = 0;
    for (int v = 1; v <= V; v++)
      if (v > mp) {
        if (d < D && den[d] <= v) {
          mp += den[d] * C;
          d++;
        } else {
          mp += v * C;
          res++;
        }
        v = mp - 1;
      }

    printf("Case #%d: %d\n", t, res);
  }

  return 0;
}
