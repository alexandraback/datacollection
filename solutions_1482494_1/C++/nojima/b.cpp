#include <cstdio>
#include <cstring>
using namespace std;

int a[1010], b[1010];
int rate[1010];

int main() {
  int T; scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    memset(rate, 0, sizeof(rate));

    int N; scanf("%d", &N);
    for (int i = 0; i < N; ++i) { scanf("%d%d", a+i, b+i); }

    int star = 0, ans = 0;
    for (;;) {
      int k = -1, r = -1;
      for (int i = 0; i < N; ++i) {
        if (rate[i] < 2 && b[i] <= star) {
          k = i;
          r = 2;
          break;
        } else if (rate[i] < 1 && a[i] <= star) {
          if (k == -1 || b[i] > b[k]) {
            k = i;
            r = 1;
          }
        }
      }
      if (k == -1) { break; }
      star += r - rate[k];
      rate[k] = r;
      ++ans;
    }
    if (star == 2*N) {
      printf("Case #%d: %d\n", t, ans);
    } else {
      printf("Case #%d: Too Bad\n", t);
    }
  }
}
