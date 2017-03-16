#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1100;
int v[maxn];
int a[maxn];
int cur, n;
void dfs1(int x, int d, int& maxd)
{
    v[x] = d;
    if (d > maxd)
        maxd = d;
    for (int i = 1; i <= n; i++)
        if (v[i] == -1 && a[i] == x)
            dfs1(i, d + 1, maxd);
}

void dfs2(int x, int be, int d)
{
    v[x] = d;
    if (v[a[x]] == -1)
        dfs2(a[x], be, d + 1);
    else
    {
        if (a[x] == be)
        {
            if (d - v[a[x]] + 1 > cur)
                cur = d - v[a[x]] + 1;
        }
    }
}


int main()
{
    int t, ca = 1;
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
    scanf("%d",&t);
    while (t--)
    {
        cur = 0;
        scanf("%d",&n);
        for (int i = 1; i <= n; i++)
            scanf("%d",&a[i]);
        for (int i = 1; i <= n; i++)
        {
            memset(v, -1, sizeof(v));
            dfs2(i, i, 1);
        }
        int ans = 0,temp1,temp2;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (a[i] == j && a[j] == i)
                {
                    memset(v, -1, sizeof(v));
                    temp1 = 0;
                    temp2 = 0;
                    v[i] =1;
                    v[j] = 1;
                    dfs1(i, 1, temp1);
                    dfs1(j, 1, temp2);
                    ans += temp1 + temp2;
                }
            }
        }
        ans=max(ans,cur);
        printf("Case #%d: %d\n",ca++,ans);
    }
    return 0;
}
