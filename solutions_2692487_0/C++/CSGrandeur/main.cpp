#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn = 1000111;
int siz[maxn];
int dp[111][111];
int ori, m;
void CalNum(int a, int b, int &kk, int &pp)
{
    int cnt = 0;
    while(a <= b)
        a += a - 1, cnt ++;
    kk = cnt;
    pp = a + b;
}
int main()
{
    int t, ca, i, j, k, ans;
    freopen("A-small-attempt2.in", "r", stdin);
    freopen("A-small-attempt2.out", "w", stdout);
    for(scanf("%d", &t), ca = 1; ca <= t; ca ++)
    {
        scanf("%d%d", &ori, &m);
        for(i = 1; i <= m; i ++)
            scanf("%d", &siz[i]);
        if(ori == 1)
        {
            printf("Case #%d: %d\n", ca, m);
            continue;
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = ori;
        sort(siz + 1, siz + m + 1);
        int kk, pp;
        for(i = 1; i <= m; i ++)
        {
            j = i - 1;
            for(k = 0; k < 111; k ++)
            {
                if(dp[j][k])
                {
                    CalNum(dp[j][k], siz[i], kk, pp);
                    dp[i][k + kk] = max(dp[i][k + kk], pp);
                    dp[i][k + 1] = max(dp[i][k + 1], dp[j][k]);
                }
            }
        }
        for(i = 0; i < 111; i ++) if(dp[m][i]) {ans = i; break;}
        printf("Case #%d: %d\n", ca, ans);
    }
    return 0;
}
