#include<cstdio>
#include<map>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
void solve()
{
    long long n,a,mi,i,b[1000001],co=0,p;
    cin>>a>>n;
    for(i=0;i<n;i++)
    cin>>b[i];
    mi=n;
    sort(b,b+n);
    if(a==1)
    {
        cout<<n<<endl;
        return;
    }
    for(i=0;i<n;i++)
    {
        mi=min(mi,n-i+co);
        while(a<=b[i])
        {
            co++;
            a+=a-1;
        }
        a+=b[i];
    }
    mi=min(mi,n-i+co);
    cout<<mi<<endl;
}
int main()
{
    int t,i;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
}
