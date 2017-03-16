#include <stdio.h>
int K, C, S;
#define ll long long

int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
       scanf("%d%d%d", &K, &C, &S);
       ll a = 0, b = 0; 
       if (S * C < K) printf("Case #%d: IMPOSSIBLE\n", t);
       else {
         printf("Case #%d:", t);
         int n = (K + C - 1) / C;
         for (int i = 0; i < n; i++) {
             ll ret = 0;
             ll base = 1;
             for(int j = 0; j < C; j++) {
                if (C * i + j < K) {
                  ret += base * (C * i + j);
                }
                base = base * K;
             }
             printf(" %lld", ret + 1);
         }
         printf("\n");
       } 
    }
}
