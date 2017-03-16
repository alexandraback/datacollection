#include <stdio.h>

int main(){
    int t;
    scanf("%d",&t);
    int n,j;
    scanf("%d%d",&n,&j);
    printf("Case #1:\n");
    for(int i = 0; i < j; i++){
        printf("11");
        for(int k = 0; k < n / 2 - 2; k++){
            int w = (i >> k) & 1;
            printf("%d%d",w,w);
        }
        printf("11");
        for(int i = 2; i <= 10; i++){
            printf(" %d",i + 1);
        }
        printf("\n");
    }
}
