#include <cstdio>
#include <bitset>

int main() {
  int t, a, b, k;
  scanf("%d", &t);
  for (int c = 1; c <= t; c++) {
    scanf("%d %d %d", &a, &b, &k);
    int p = 0;
    for (int i = 0; i < a; i++) {
      for (int j = 0; j < b; j++) {
        std::bitset<16> ba(i), bb(j), l = (ba &= bb);
        for (int kk = 0; kk < k; kk++) {
          if (kk == l.to_ulong()) {
            p++;
          }
        }
      }
    }
    printf("Case #%d: %d\n", c, p);
  }
  return 0;
}
