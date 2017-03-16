#include <bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef unsigned long long ull;

int main() {_;
  int T;
  ull B, M;
  ull j;
  scanf("%d", &T);

  for (int t=1; t<=T; t++) {
    scanf("%lld %lld", &B, &M);
    printf("Case #%d: ", t);
    if (M <= (1ULL << (B-2))) {
      printf ("POSSIBLE\n");
      for (ull i=0; i<B-1; i++) {
        for (j=0; j<=i; j++) {
          printf("0");
        }
        for (; j<B-1; j++) {
          printf("1");
        }
        if (M == (1ULL << (B-2))) {
          printf("1");
        } else {
          if (i==0){
            printf("0");
          } else {
            if (M & (1 << (i-1))) {
              printf("1");
            } else {
              printf("0");
            }
          }
        }
        printf("\n");
      }
      for (ull i=0; i<B; i++) {
        printf("0");
      }
      printf("\n");
    } else {
      printf ("IMPOSSIBLE\n");
    }
  }
  return 0;
}
