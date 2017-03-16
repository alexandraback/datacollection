#include <bits/stdc++.h>

using namespace std;

void solve()
{
    long double C, F, X;
    cin>>C>>F>>X;
    if(C>X || abs(C-X)<=1e-9)
    {
        printf("%.7Lf\n", X/2.0);
        return;
    }
    long double ans=X/2.0;
    long double sum=0.0;
    for(int i=1; i<=200000; i++)
    {
        sum+=C/(2.0+(i-1)*F);
        ans=min(ans, sum+X/(2.0+i*F));
    }
    printf("%.7Lf\n", ans);
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++)
    {
        printf("Case #%d: ", i);
        solve();
    }

    return 0;
}
