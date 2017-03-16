#include <cstdio>
#include <cstring>
#define eps 1e-6
int N, T;
int num[210];
double ans[210];
int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <=T; cas++) {
        scanf("%d", &N);
        double sum = 0;
        for (int i = 0; i < N; i++) {
            scanf("%d", num + i);
            sum += num[i];
        }
        double l = 0, r = sum* 2, mid;
        for (int t = 0; t < 200; t++) {
            mid = (l + r) / 2.0;
            bool ok = 1;
            double t = 0;
            for (int i = 0; i < N; i++) {
                ans[i] = (mid - num[i]) / sum;
                if (ans[i] < 0) ans[i] = 0;
                if (ans[i] > 1) r = mid, ok = 0;
                t += ans[i];
            }
            if (!ok) continue;
            if (t < 1.0) l = mid;
            else if (t > 1.0) r = mid;
        }
        printf("Case #%d:", cas);
        sum = 0;
        for (int i = 0; i < N; i++) {
            sum += ans[i];
            printf(" %.6lf", ans[i] * 100);
        }
        printf("\n");
    }
}
