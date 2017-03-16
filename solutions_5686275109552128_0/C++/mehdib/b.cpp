#include<cstdio>
#include<algorithm>

using namespace std;

int P[1001];

int main() {

  int T;

  scanf("%d", &T);

  for (int t = 1; t <= T; t++) {

    int D;
    scanf("%d", &D);

    int best = 0;
    for (int d = 0; d < D; d++) {
      scanf("%d", &P[d]);
      best = max(best, P[d]);
    }

    for (int rem = 1; rem < best; rem++) {
      int sco = rem;
      for (int d = 0; d < D && sco < best; d++)
        sco += (P[d] - 1) / rem;
      best = min(best, sco);
    }

    printf("Case #%d: %d\n", t, best);
  }

  return 0;
}
