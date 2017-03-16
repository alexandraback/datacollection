#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll gcd(ll a, ll b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    int t,u;
    cin>>t;
    u=t;
    while(t--)
    {
        ll p,q,g,flag=1;
        scanf("%lld/%lld",&p,&q);
        int ans=0,loop=40;
        g=gcd(p,q);
        p=p/g;
        q=q/g;
        while(loop--)
        {
            p=p*2;
            g=gcd(p,q);
            p=p/g;
            q=q/g;
            if(p>=q&&flag)
            {
                ans=40-loop;
                flag=0;
            }
            if(p>q)
            {
                p=p-q;
            }
        }
        cout<<"Case #"<<u-t<<": ";
        if(p==1&&q==1)
            cout<<ans<<endl;
        else
            cout<<"impossible\n";
    }
    return 0;
}