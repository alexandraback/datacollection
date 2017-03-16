#include <stdio.h>

#define llong long long
llong n, m;
bool A[64];

int main() {
   int T;
   scanf("%d", &T);
   for (int t = 1; t <= T; t++) {
     scanf("%lld%lld", &n, &m); 
     llong sum = 1;
     for (int i = 0; i < n; i++) A[i] = false;
     m = m - 1;
     A[0] = true;
     for (int i = 1; i < n - 1; i++) if (m > 0) {
        if (m % 2 == 1) A[i]= true;
         m = m / 2;
     }
     if (m > 0) {
        printf("Case #%d: IMPOSSIBLE\n", t);
     } else {
        printf("Case #%d: POSSIBLE\n", t);
        for (int i = 0; i < n - 1; i++) {
           for (int j = 0; j < i+ 1; j++) printf("0"); 
           for (int j = i + 1; j < n - 1; j++) printf("1"); 
           printf("%d\n", A[i]? 1: 0);
        }
        for (int j = 0; j < n; j++) printf("0");
        printf("\n");
     }
   }
}

