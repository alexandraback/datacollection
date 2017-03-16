#include <stdio.h>
#include <math.h>
int myabs(int x){
    if (x < 0) return -x;
    return x;
}
double f(int n, int k){
    double re = 1;
    int i;
    for (i = 0; i < k; i++) re = re * (n - i) / (i + 1) / 2;
    for (i = k; i < n; i++) re /= 2;
    return re / 2;
}
int main(){
    int T, ri = 1, n, x, y, d, i;
    freopen("B-small-attempt0(1).in", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    while (T--){
        scanf("%d%d%d", &n, &x, &y);
        printf("Case #%d: ", ri++);
        d = myabs(x) + myabs(y);
        if (d % 2){
            printf("0.00000000\n");
            continue;
        }
        d /= 2;
        int m = (d * 2 + 1) * (d * 2 + 2) / 2;
        if (n >= m){
            printf("1.00000000\n");
            continue;
        }
        m = (d * 2 - 1) * (d * 2) / 2;
        if (n <= m){
            printf("0.00000000\n");
            continue;
        }
        n -= m;
        if (y + 1 > n){
            printf("0.00000000\n");
            continue;
        }
        if (y == d * 2){
            printf("0.00000000\n");
            continue;
        }
        double ans = 0;
        for (i = y + 1; i <= n; i++){
            if (i >= y + 1 + d * 2) break;
            ans += f(i - 1, y);
        }
        if (y + 1 + d * 2 <= n){
            for (i = d * 2; i <= n && i < y + 1 + d * 2; i++){
                ans += f(i - 1, d * 2 - 1);
            }
        }
        printf("%.8f\n", ans);
    }
    return 0;
}
