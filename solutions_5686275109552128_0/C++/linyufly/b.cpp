#include <cstdio>

const int maxd = 10000;

int p[maxd];

int main() {
  int tt;
  scanf("%d", &tt);

  int d;
  for (int t = 1; t <= tt; t++) {
    printf("Case #%d: ", t);

    scanf("%d", &d);

    int max_p = 0;
    for (int i = 0; i < d; i++) {
      scanf("%d", &p[i]);
      if (p[i] > max_p) {
        max_p = p[i];
      }
    }

    int ans = 0x7fffffff;
    for (int level = 1; level < ans && level <= max_p; level++) {
      int sum = 0;
      for (int i = 0; i < d; i++) {
        if (p[i] > level) {
          sum += (p[i] - level - 1) / level + 1;
        }
      }
      if (level + sum < ans) {
        ans = level + sum;
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}

