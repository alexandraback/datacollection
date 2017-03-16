
#include <cstdio>

int main(int argc, char *argv[]) {
  int Z;
  scanf("%d", &Z);
  for (int z=1;z<=Z;z++) {
    printf("Case #%d:\n", z);
    int n, k;
    scanf("%d %d", &n, &k);
    n -= 2;
    for (int i=0;k && i<(1<<n);i++) {
      int s = 0;
      for (int j=0;j<n;j++) {
        if (i & (1<<j)) {
          s += j % 2 ? 1 : -1;
        }
      }
      if (s) continue;
      printf("1");
      for (int j=0;j<n;j++) printf("%d", (i>>j)&1);
      printf("1 3 4 5 6 7 8 9 10 11\n");
      k--;
    }
  }
  return 0;
}
