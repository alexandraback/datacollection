#include <stdio.h>
int K, C, S;
int main(){
    int T;
    scanf("%d", &T);
    for(int t = 1; t <= T; t++){
       scanf("%d%d%d", &K, &C, &S);
       if (S < K) printf("Case #%d: IMPOSSIBLE\n", t);
       else {
         printf("Case #%d:", t);
         for (int i = 0; i < K; i++) printf(" %d", i + 1);
         printf("\n");
       } 
    }
}
