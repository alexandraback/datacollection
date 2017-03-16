#include <stdio.h>

int main()
{
    int cases;
    scanf("%d", &cases);
    for (int i = 1; i <= cases; i++){
        printf("Case #%d:", i);
        int K, C, S;
        scanf("%d %d %d", &K, &C, &S);
        if (C == 1){
            if (S == K){
                for (int i = 1; i <= K; i++)
                    printf(" %d", i);
                puts("");
            }
            else{
                puts(" IMPOSSIBLE");
            }
        }
        else{
            if (S == K){
                for (int i = 1; i <= K; i++)
                    printf(" %d", i);
                puts("");
            }
            else if (S == K - 1){
                for (int i = 2; i <= K; i++)
                    printf(" %d", i);
                puts("");
            }
            else{
                puts(" IMPOSSIBLE");
            }            
        }
    }
}
