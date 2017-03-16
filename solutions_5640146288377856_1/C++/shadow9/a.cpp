#include<cstdio>

int main(){
    int T, R, C, W;
    int cnt = 0;
    scanf("%d", &T);
    while(T--){
        scanf("%d%d%d", &R, &C, &W);
        int ans = (R-1)*(C/W);
        if(C % W == 0){
            ans += C/W + W - 1;
        }
        else{
            ans += C/W + W;
        }
        printf("Case #%d: %d\n", ++cnt, ans);
    }
    return 0;
}
