#include <cstdio>
#include <cassert>
#include <cstring>

int main (void) {
  int T;
  int scanned = scanf("%d", &T);
  for (int currentcase = 1; currentcase <= T; ++currentcase) {
    int a, b, k, count = 0;
    scanf("%d %d %d", &a, &b, &k);
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
        if ((i & j) < k) {
          count++;
        }
      }
    }
    printf("Case #%d: %d\n", currentcase, count);
  }
  return 0;
}
