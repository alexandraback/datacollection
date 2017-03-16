#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int d;
int p[1024];

int minSplits(int v) {
  int op = 0;
  for (int i = 0; i < d; ++i) {
    op += (p[i] - 1) / v;
  }
  return op;
}

int main() {
  int t, T;
  scanf("%d", &T);
  for (t = 1; t <= T; ++t) {
    scanf("%d", &d);
    for (int i = 0; i < d; ++i) {
      scanf("%d", &p[i]);
    }
    int ans = (1 << 20);
    for (int v = 1; v <= 2000; ++v) {
      ans = min(ans, v + minSplits(v));
    }
    printf("Case #%d: %d\n", t, ans);
  }
  return 0;
}
