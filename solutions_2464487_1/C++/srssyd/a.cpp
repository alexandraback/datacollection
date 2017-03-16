#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
typedef long long ll;
int main()
{
    freopen("A-large.in","r",stdin);
    freopen("out.out","w",stdout);
    int T;
    int casno=0;
    scanf("%d",&T);
    while(T--)
    {
        casno++;
        ll r,t;
        cin>>r>>t;
        long double delta=(long double)(2*r-1)*(2*r-1)+4*2*t;
        long double ans=((1-2*r)+sqrt(delta))/4;
        ll res=floor(ans);
        cout<<"Case #"<<casno<<": ";
        cout<<res<<endl;
    }
    return 0;
}
