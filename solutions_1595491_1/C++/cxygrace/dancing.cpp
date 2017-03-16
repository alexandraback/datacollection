#include<iostream>
#include<stdio.h>
using namespace std;
const int maxn = 110;
int dat[maxn], n, s, p;
int h[maxn][maxn];
int maxcount()
{
    int i, j;
    for (i=0; i<=s; i++) h[0][i] = 0;
    for (i=1; i<=n; i++)
        for (j=0; j<=s; j++)
        {
            h[i][j] = h[i-1][j]+((dat[i]+2)/3>=p);
            if (j==0) continue;
            if (dat[i]%3==0 && dat[i]/3-1>=0) h[i][j] = max(h[i][j], h[i-1][j-1]+(dat[i]/3+1>=p));
            else if (dat[i]%3==2) h[i][j] = max(h[i][j], h[i-1][j-1]+(dat[i]/3+2>=p));
        }
    return h[n][s];
}
int main()
{
    freopen("1.in", "r", stdin);
    int t, test;
    cin >> t;
    for (test=1; test<=t; test++)
    {
        scanf("%d%d%d", &n, &s, &p);
        for (int i=1; i<=n; i++) scanf("%d", dat+i);
        printf("Case #%d: %d\n", test, maxcount());
    }
    return 0;
}
