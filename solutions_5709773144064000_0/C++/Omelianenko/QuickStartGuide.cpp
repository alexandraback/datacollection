#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<set>
#include<map>

using namespace std;

#define ll long long

int num, t, i;
double k, r1, r2, ans, C, F, X;

double f(int x)
{
    double k=2;
    double ans=0;
    for(int i=0; i<x; i++)
    {
        ans=ans+C/k;
        k+=F;
    }
    ans=ans+(X/k);
    return ans;
}

int main()
{
    cin.tie(0);
    cin.precision(8);
    ios_base::sync_with_stdio(0);
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attepmt1.out","w",stdout);
    cin>>t;
    while(t--)
    {
        num++;
        cin>>C>>F>>X;
        /*l=0;
        r=100000;
        while(r-l>2)
        {
            int m1=l+(r-l)/3;
            int m2=r-(r-l)/3;
            if(f(m1)>f(m2))l=m1;
                      else r=m2;
        }
        ans=f(l);
        for(i=l+1; i<=r; i++)
            ans=min(ans, f(i));
        cout<<fixed<<ans<<endl;*/

        k=2;
        r1=0;
        r2=0;
        ans=0;
        for(i=1; ; i++)
        {
            r1=ans+(X/k);
            r2=ans+(C/k)+(X/(k+F));
            if(r1<=r2)
            {
                cout<<"Case #"<<num<<": "<<fixed<<r1<<endl;
                break;
            }
            ans=ans+(C/k);
            k+=F;
        }
    }
}
