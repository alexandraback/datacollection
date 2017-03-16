#include <stdio.h>
int c[110];
int main(){
    int T, ri = 1, n, s, p, ans, x;
    freopen("B-small-attempt0 (1).in", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    while (T--){
        ans = 0;
        scanf("%d%d%d", &n, &s, &p);
        while (n--){
            scanf("%d", &x);
            if (x < p) continue;
            if (p * 3 - 2 <= x) ans++;
            else if (p * 3 - 4 <= x && s){
                s--;
                ans++;
            }
        }
        printf("Case #%d: %d\n", ri++, ans);
    }
    return 0;
}
