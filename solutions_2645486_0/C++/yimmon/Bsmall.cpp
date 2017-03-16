/*========================================================================
#   FileName: Bsmall.cpp
#     Author: YIMMON
#      Email: yimmon.zhuang@gmail.com
#   HomePage: http://qr.ae/8DMzu
# LastChange: 2013-04-27 10:30:19
========================================================================*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 20

int T, e, r, n, v[N], low;
int dp[N][N];

inline int f(int x, int j)
{
    int ret = -1;
    if(j < e)
    {
        ret = x+r-j;
        if(ret <= x && ret >= 0) return ret;
    }
    else
    {
        ret = x+r-e;
        if(ret > x) return x;
        if(ret >= 0) return ret;
    }
    return -1;
}

int main(int argc, char **argv)
{
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas)
    {
        scanf("%d%d%d", &e, &r, &n);
        for(int i = 1; i <= n; ++i)
            scanf("%d", v+i);
        memset(dp, 0, sizeof(dp));
        low = min(e, r);
        for(int i = low; i <= e; ++i)
        {
            int tmp = f(e, i);
            if(tmp != -1)
                dp[1][i] = tmp*v[1];
        }
        for(int i = 2; i <= n; ++i)
            for(int j = low, tmp; j <= e; ++j)
                for(int k = low; k <= e; ++k)
                    if((tmp = f(k, j)) != -1)
                        dp[i][j] = max(dp[i][j], dp[i-1][k]+v[i]*tmp);
        int ans = 0;
        for(int i = low; i <= e; ++i)
            ans = max(dp[n][i], ans);
        printf("Case #%d: %d\n", cas, ans);
    }

    return 0;
}
