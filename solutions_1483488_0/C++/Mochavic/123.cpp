#include <stdio.h>
int ten;
void pd(int x){
    ten = 1;
    while (x){
        ten *= 10;
        x /= 10;
    }
    ten /= 10;
}
int f(int x){
    int t = x % 10;
    return t * ten + x / 10;
}
int main(){
    int T, ri = 1, x, y, ans, i, t;
    freopen("C-small-attempt0 (1).in", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    while (T--){
        scanf("%d%d", &x, &y);
        ans = 0;
        for (i = x; i <= y; i++){
            pd(i);
            t = f(i);
            while (t != i){
                if (t < i && t >= x && t <= y && t >= ten) ans++;
                t = f(t);
            }
        }
        printf("Case #%d: %d\n", ri++, ans);
    }
    return 0;
}
