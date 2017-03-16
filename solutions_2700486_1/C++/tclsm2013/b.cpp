#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
#include <string.h>
using namespace std;

const int maxn = 2007;
    
int f[maxn];
int n, x, y, run;
long double g[maxn*2][maxn*2];

void solve()
{
    scanf("%d%d%d", &n, &x, &y);
    int H;
    for (H = 1000; H >= 1; H--)
        if (f[H] <= n)
        {
            n -= f[H];
            break;
        }
    if (abs(x)+abs(y) <= (H-1)*2)
    {
        printf("Case #%d: %.12f\n", run, 1.0);
        return;
    }
    if (abs(x)+abs(y) > H*2 || y == H*2 || n == 0)
    {
        printf("Case #%d: %.12f\n", run, 0.0);
        return;
    }
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= H*2 && j <= i; j++) g[i][j] = 0;
    g[0][0] = 1.0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= H*2 && j <= i; j++)
        {
            int L = i-j;
            if (L > H*2) continue;
            if (L == H*2) g[i+1][j+1] += g[i][j];
            else
                if (j == H*2) g[i+1][j] += g[i][j];
                else
                {
                    g[i+1][j] += g[i][j]/2;
                    g[i+1][j+1] += g[i][j]/2;
                }
        }
    long double res = 0;
    for (int j = y+1; j <= H*2 && j <= n; j++) res += g[n][j];
    printf("Case #%d: %.12f\n", run, (double)res);
}

int main()
{
    freopen("B-large.in", "r", stdin);
    freopen("B-large.ans", "w", stdout);
    f[1] = 1;
    for (int i = 2; i <= 1000; i++) f[i] = f[i-1]+i*4-3;   
    int test;
    scanf("%d", &test);
    for (run = 1; run <= test; run++) solve();
    return 0;
}
