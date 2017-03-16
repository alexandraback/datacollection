#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 100000+5, MAXM = 12*16+5;
const int INF = 0x3f3f3f3f;
int T, A, B;
double p[MAXN];
double d[MAXN][2];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        scanf("%d%d", &A, &B);
        d[0][1] = 1;
        double ans = A+B+1;
        for (int i = 1; i <= A; i++)
        {
            scanf("%lf", &p[i]);
            d[i][1] = d[i-1][1]*p[i];
            d[i][0] = 1-d[i][1];
            ans = min(ans, d[i][1]*(A-i+B-i+1)+d[i][0]*(A-i+B-i+1+B+1));
        }
        ans = min(ans, (double)(1+B+1));
        printf("Case #%d: %.6lf\n", cas, ans);
    }
    return 0;
}
