#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int n,curb;
double a[301],sum,b[301];

void solve()
{
    scanf("%d", &n);
    sum = 0;
    for (int i=1;i<=n;i++)
    {
        scanf("%lf",&a[i]);
        sum+=a[i];
        b[i] = a[i];
    }
    sort(b+1,b+n+1);
    for (int i=1;i<=n;i++)
    {
        double ans = 2 / (double)n - a[i] / sum;
        
        double tmp = ans * sum + a[i];
        curb = n;
        int tn = n-1;
        int tsum = sum - a[i];
        while (b[curb] > tmp && curb > 1)
        {
            tsum -= b[curb];
            curb--;
            tn--;
            ans = (-tn * a[i] + tsum + sum)/((tn + 1) * sum);
            tmp = ans * sum + a[i];
        }
        
        ans *= 100;
        if (ans < 0) ans = 0;
        if (i != n) printf("%.6lf ", ans);
        else printf("%.6lf\n", ans);
    }
}

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int T;
    scanf("%d",&T);
    for (int i=1;i<=T;i++)
    {
        printf("Case #%d: ",i);
        solve();
    }
    return 0;
}
