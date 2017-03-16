#include <stdio.h>

int d[10000];

int main(){
    int t;
    scanf("%d",&t);
    for(int tw = 1; tw <= t; tw++){
        int n;
        scanf("%d", &n);
        for(int i = 0; i < 10000; i++){
            d[i] = 0;
        }
        for(int i = 0; i < n * 2 - 1; i++){
            for(int j = 0; j < n; j++){
                int w;
                scanf("%d",&w);
                d[w]++;
            }
        }
        printf("Case #%d:", tw);
        for(int i = 0; i < 10000; i++){
            if(d[i] % 2 != 0){
                printf(" %d", i);
            }
        }
        printf("\n");
    }
}

