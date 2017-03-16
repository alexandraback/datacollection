#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
ll int mark[2000];
ll int markdig(ll int n)
{

    ll int dig,i;
    while(n>0)
    {
        dig= n%10;
        n = n/10;
        mark[dig] = 1;
    }
    for(i=0;i<10;i++)
    {
        if(mark[i] == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    ll int t,n,i,k,test,c,s;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin>>t;
    for(test=1;test<=t;test++)
    {
        cout<<"Case #"<<test<<": ";
        cin>>k>>c>>s;
        for(i=1;i<=k;i++)
            cout<<i<<" ";
        cout<<"\n";
    }
    return 0;
}
