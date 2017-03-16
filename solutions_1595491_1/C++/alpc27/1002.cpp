#include <stdio.h>

int t;
int n,m,p;
int a[110];

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("output.txt","w",stdout);
    int i,j,k;
    int x,y;
    scanf("%d", &t);
    for (k = 1;k <= t;k++)
    {
        scanf("%d%d%d", &n, &m, &p);
        x = p * 3 - 2;
        y = p * 3 - 4;
        if (p == 1)
            y = 1;
        int ct = 0;
        int ans = 0;
        for (i = 0;i < n;i++)
        {
            scanf("%d", &a[i]);
            if (a[i] >= x)
                ans++;
            else if (a[i] >= y)
                ct++;
        }
        if (ct > m)
            ans += m;
        else
            ans += ct;
        printf("Case #%d: %d\n", k, ans);
    }
    return 0;
}
