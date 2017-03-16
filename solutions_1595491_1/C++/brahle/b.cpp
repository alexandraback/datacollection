#include <cstdio>

const int MAXN = 110;

int t;
int n, s, p;
int bodovi[MAXN];

int main() {
  scanf("%d", &t);
  for (int III = 0; III < t; ++III) {
    printf("Case #%d: ", III+1);
    scanf("%d%d%d", &n, &s, &p);
    for (int i = 0; i < n; ++i)
      scanf("%d", bodovi+i);

    int cnt = 0;
    //    printf("\nTrazim bar %d, imam %d promjena\n", p, s);
    for (int i = 0; i < n; ++i) {
      //      printf("%d: %d, %d", bodovi[i], (bodovi[i]+2)/3, bodovi[i]%3);
      if ((bodovi[i]+2)/3 >= p) {
        ++cnt;
        //        printf("*\n");
        continue;
      }

      if (bodovi[i] <= 1) {
        //        printf("\n");
        continue;
      }
      if (!s) {
        //        printf("\n");
        continue;
      }

      if ((bodovi[i]+1)/3 + 1 == p) {
        ++cnt;
        --s;
        //        printf("*");
      }
      //      printf("\n");
    }

    printf("%d\n", cnt);
  }
  return 0;
}

