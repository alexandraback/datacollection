#include <cstdio>

int tx, ty;

int main() {
  int cas = 0;
  int T; scanf("%d", &T);
  while (T--) {
    scanf("%d%d", &tx, &ty);
    printf("Case #%d: ", ++cas);
    for (int i = 0; i < tx; ++i) {
      printf("WE");
    }
    for (int i = 0; i > tx; --i) {
      printf("EW");
    }
    for (int j = 0; j < ty; ++j) {
      printf("SN");
    }
    for (int j = 0; j > ty; --j) {
      printf("NS");
    }
    puts("");
  }
  return 0;
}
