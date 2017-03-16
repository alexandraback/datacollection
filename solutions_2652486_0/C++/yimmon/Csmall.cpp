/*========================================================================
#   FileName: Csmall.cpp
#     Author: YIMMON
#      Email: yimmon.zhuang@gmail.com
#   HomePage: http://qr.ae/8DMzu
# LastChange: 2013-04-27 11:03:10
========================================================================*/
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define N 105

int T, r, n, m, k, a[N], b[N];

int dfs(int v)
{
    if(v > n)
    {
        int p = 1;
        for(int i = 1; i <= n; ++i)
            p *= b[i];
        int flag = 1;
        for(int i = 1; i <= k; ++i)
            if(p%a[i] != 0)
            {
                flag = 0;
                break;
            }
        return flag;
    }
    for(int i = 2; i <= m; ++i)
    {
        b[v] = i;
        if(dfs(v+1))
            return 1;
    }
    return 0;
}

int main(int argc, char **argv)
{
    scanf("%d", &T);
    for(int cas = 1; cas <= T; ++cas)
    {
        printf("Case #%d:\n", cas);
        scanf("%d%d%d%d", &r, &n, &m, &k);
        while(r--)
        {
            for(int i = 1; i <= k; ++i)
                scanf("%d", a+i);
            dfs(1);
            for(int i = 1; i <= n; ++i)
                printf("%d", b[i]);
            puts("");
        }
    }

    return 0;
}
