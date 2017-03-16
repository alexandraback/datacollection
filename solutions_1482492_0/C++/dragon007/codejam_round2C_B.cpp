#include <cstdio>
#include <cmath>

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B1.out","w",stdout);
    int T, N, A, cas = 1;
    double D, a, t[10], x[10];
    double ans[10];
    scanf("%d", &T);
    while (T --)
    {
        scanf("%lf %d %d", &D, &N, &A);
       // printf("%lf %d %d\n", D, N, A);
        for (int i = 0; i < N; i ++)
            scanf("%lf %lf", &t[i], &x[i]);
        for (int i = 0; i < A; i ++)
        {
            scanf("%lf", &a);
            if (N == 1)
            {
                ans[i] = sqrt(2*D/a);
            }
            else if (N == 2){
                double v = (x[1] - x[0]) / (t[1] - t[0]);
                double deltat = (D - x[0]) / v;
                ans[i] = sqrt(2*D/a);
                if (ans[i] >= deltat)
                    continue;
                else {
                    ans[i] = deltat;
                }
            }
        }
        printf("Case #%d:\n", cas ++);
        for (int i = 0; i < A; i ++)
            printf("%lf\n", ans[i]);
    }
    return 0;
}
