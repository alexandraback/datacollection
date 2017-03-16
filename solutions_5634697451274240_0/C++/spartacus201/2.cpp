#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;
ll int mark[2000];
char str[5000007];
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
    ll int t,n,i,ans,minus,flag,k;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin>>t;
    for(k=1;k<=t;k++)
    {
        cout<<"Case #"<<k<<": ";

        cin>>str;
        n = strlen(str);
        minus=flag = 0;
        if(str[0] == '-')
            flag = 1;
        for(i=1;i<n;i++)
        {

            if(str[i] == '-' && str[i-1] == '+')
                minus++;
        }
        ans = minus * 2 + flag;
        cout<<ans<<"\n";
    }
    return 0;
}
