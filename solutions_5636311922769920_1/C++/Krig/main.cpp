
#include <cstdio>

int main(int argc, char *argv[]) {
  int Z;
  scanf("%d", &Z);
  for (int z=1;z<=Z;z++) {
    printf("Case #%d: ", z);
    int k, c, s;
    scanf("%d %d %d", &k, &c, &s);
    int min_s = k - (c-1); min_s = min_s > 0 ? min_s : 1;
    if (s < min_s) printf("IMPOSSIBLE\n");
    else {
      long long pos = 0;
      for (int i=0;i<k-min_s;i++) {
        pos = pos * k + i +1;
      }
      while(min_s--) {
        printf("%lld ", ++pos);
      }
      printf("\n");
    }
  }
  return 0;
}
