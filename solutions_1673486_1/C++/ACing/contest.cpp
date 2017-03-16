#include <cstdio>
#include <algorithm>
#define MaxN 100010
using namespace std;

double p[MaxN], pre[MaxN];

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("A-large.out", "w", stdout);
    int T, cas = 0, A, B;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &A, &B);
        for (int i = 0; i < A; ++i) scanf("%lf", &p[i]);
        pre[0] = p[0];
        for (int i = 1; i < A; ++i) pre[i] = pre[i-1] * p[i];
        double ans = B + 2;
        for (int i = 0; i < A; ++i) ans = min(ans, 2*B-A+2-pre[A-1-i]*(B+1)+2*i);
        printf("Case #%d: %.6f\n", ++cas, ans);
    }
    return 0;
}
