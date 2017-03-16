#include<cstdio>

int main(void){
    int A, B, K, T;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        int res = 0;
        printf("Case #%d: ", i);
        scanf("%d%d%d", &A, &B, &K);
        for(int j = 0; j < A; j++)
            for(int k = 0; k < B; k++){
                //printf("%d %d %d %d\n", j, k, j&k, K);

                if((j&k) < K) res++;
            }
        printf("%d\n", res);
    }
    return 0;
}
