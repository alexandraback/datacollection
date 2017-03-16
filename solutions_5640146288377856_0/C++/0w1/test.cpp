#include <cstdio>
int main(){
    int T;
    scanf("%d", &T);
    for(int kase = 1; kase <= T; ++kase){
        int R, C, W;
        scanf("%d %d %d", &R, &C, &W);
        int ans = C / W * R;
        ans += W;
        if(C % W == 0) --ans;
        printf("Case #%d: %d\n", kase, ans);
    }
    return 0;
}