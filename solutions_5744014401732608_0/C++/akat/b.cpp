#include<cstdio>
#include<map>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
void solve()
{
    long long n,m,x,i,j;
    cin>>n>>m;
    x=1ll<<(n-2);
    if(x<m)
    {
        cout<<"IMPOSSIBLE\n";
        return;
    }
    cout<<"POSSIBLE\n";
    if(x==m)
    {
        for(i=1;i<=n;++i)
        {
            for(j=1;j<=n;++j)
            {
                if(j>i)cout<<1;
                else cout<<0;
            }
            cout<<endl;
        }
        return;
    }
    for(i=1;i<=n;++i)
        {
            for(j=1;j<n;++j)
            {
                if(j>i)cout<<1;
                else cout<<0;
            }
            if(i!=1 && ((1ll<<(i-2))&m)>0)cout<<1;
            else cout<<0;
            cout<<endl;
        }
}
int main()
{
    int t,i;
    cin>>t;
    for(i=1;i<=t;++i)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
}
