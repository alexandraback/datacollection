#include<cstdio>

int main(){
    int T, R, C, W;
    int cnt = 0;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d", &R, &C, &W);
        printf("Case #%d: ", ++cnt);
        if(C % W == 0){
            printf("%d\n", C/W + W - 1);
        }
        else{
            printf("%d\n", C/W + W);
        }
    }
    return 0;
}
