#include<cstdio>
#include<map>
#include<cstring>
#include<iostream>
using namespace std;
int br[25000];
void solve()
{
    memset(br,0,sizeof(br));
    int n,i,j,a,l=0;
    cin>>n;
    for(i=1;i<2*n;++i)
        for(j=0;j<n;++j)
        {
            cin>>a;
            ++br[a];
        }
    for(i=0;i<25000;++i)
    {
        if(br[i]%2!=0)
        {
            if(l)cout<<" ";
            cout<<i;
            l=1;
        }
    }
    cout<<'\n';
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
