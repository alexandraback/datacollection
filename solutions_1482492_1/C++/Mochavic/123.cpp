#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;
double t[2010], p[2010];
int main(){
    int T, ri = 1, n, m, i;
    double d, x, y, v, a, ans, tt, l, r, z;
    freopen("B-large (1).in", "r", stdin);
    freopen("out.txt", "w", stdout);
    scanf("%d", &T);
    while (T--){
        scanf("%lf%d%d", &d, &n, &m);
        for (i = 0; i < n; i++){
            scanf("%lf%lf", &t[i], &p[i]);
        }
        printf("Case #%d:\n", ri++);
        if (p[0] > d - 1e-8){
            while (m--){
                scanf("%lf", &a);
                printf("%.8f\n", sqrt(2 * d / a));
            }
            continue;
        }
        for (i = n - 1; i >= 0; i--){
            if (p[i] < d - 1e-8) break;
        }
        n = i + 2;
        x = p[i + 1];
        y = t[i + 1];
        p[i + 1] = d;
        t[i + 1] = t[i] + (d - p[i]) / ((x - p[i]) / (y - t[i]));
        while (m--){
            scanf("%lf", &a);
            x = v = 0;
            for (i = 1; i < n; i++){
                tt = t[i] - t[i - 1];
                y = x + (v * tt + a * tt * tt / 2);
                v += a * tt;
                if (y > p[i] + 1e-8){
                    y = p[i];
                    if (p[i] - x - tt * tt * a / 2 > 0){
                        v = p[i] - x - tt * tt * a / 2 / tt + a * tt;
                    }else{
                        v = sqrt(2 * (p[i] - x) / a) * a;
                    }
                }
                x = y;
            }
            ans = t[n - 1];
            if (y < d - 1e-8){
                l = 0;
                r = 1000;
                while (l + 1e-8 < r){
                    z = (l + r) / 2;
                    if (v * z + a / 2 * z * z > d - y + 1e-8) r = z;
                    else l = z;
                }
                ans += r;
            }
            printf("%.8f\n", ans);
        }
    }
    return 0;
}
