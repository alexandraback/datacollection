#include <iostream>
#include <cstdio>
using namespace std;
#define rep(i,n) for (int i=1,n__=n;i<=n__;i++)
long long gcd(long long x,long long y)
{
    if (x%y==0)
        return y;
    else
        return gcd(y,x%y);
}
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("lar.out","w",stdout);
    int ta;
    cin>>ta;
    rep(tz,ta)
    {
        long long x,y;
        cin>>x;
        cin.ignore();
        cin>>y;
//        cout<<x<<' '<<y<<endl;
        int ans=0;
        long long  k=gcd(x,y);
        x/=k;
        y/=k;
//        cout<<x<<' '<<y<<endl;
        while (x<y)
        {
            ans++;
            if (y%2==1 && y!=1)
                ans=-100000000;
            y/=2;
        }
        while (y>0)
        {
            if (y%2==1 && y!=1)
            {
                ans=-100000000;
//                cout<<y<<endl;
            }
            y/=2;
        }
        if (ans>=0)
            printf("Case #%d: %d\n",tz,ans);
        else
            printf("Case #%d: %s\n",tz,"impossible");
    }
    return 0;
}
