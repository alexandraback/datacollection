#include <cstdio>
#include <cstring>
double p[100100];

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int ct, i, n, m, T, x;
    double ans, tmp, ans_t;
    scanf("%d",&T);
    for (ct = 1; ct <= T; ct++) {
        scanf("%d %d", &m, &n);
        for (i = 0; i < m; i++)
            scanf("%lf", p + i);
        ans = (1 + n + 1) * 1.0; 
       // printf("%lf\n",ans);
        tmp = 1.0;
        for (i = m; i >= 0; i--) {
            x = i + n - (m - i) + 1;
            ans_t = x * tmp + (x + n + 1) * (1.0 - tmp);
          //  printf("%lf\n",ans_t);
            if (ans_t < ans) ans = ans_t;
            if (i > 0)tmp *= p[m - i];
        }
        printf("Case #%d: %.6lf\n",ct, ans);    
    }

    return 0;
}