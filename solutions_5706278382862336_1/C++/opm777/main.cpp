#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<string>
#include<algorithm>
#define ll long long
using namespace std;
ll p,q;

ll gcd(ll m,ll n)
{
    ll t;
	while(n)
	{  t=m%n;   m=n;   n=t; }
	return m;
}

int main()
{
    //freopen("in.in","r",stdin);
    freopen("out.out","w",stdout);
    int n,i;
    cin>>n;

    for(i=1;i<=n;i++)
    {
        char c;
        ll gc;
        cin>>p>>c>>q;

        printf("Case #%d: ",i);
        gc=gcd(p,q);
        p/=gc;
        q/=gc;

        int flag=0;
        ll tmp=q;
        while(tmp)
        {
            if(tmp==1) break;
            if(tmp%2==0) tmp>>=1;
            else
            {
                flag=1;
                break;
            }
        }

        if(flag)
        {
            puts("impossible");
            continue;
        }
        int t=1;

        //cout<<p<<" "<<q<<endl;
        while(1)
        {
            if(p*2>=q) break;
            t++;
            p*=2;
        }
        cout<<t<<endl;
    }
    return 0;
}
