#include<stdio.h>
int main(){
    int T, i, R, C, W;
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for(i=1; i<=T; i++){
        scanf("%d %d %d", &R, &C, &W);
        printf("Case #%d: %d\n", i, W+(C-1)/W);
    }
    return 0;
}

