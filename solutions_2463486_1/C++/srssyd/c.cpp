#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
ll make(ll i,int flag)
{
    ll tmp=i;
    int d=0;
    while(tmp!=0)
    d++,tmp/=10;
    if(flag==0)
    {
        ll ans=i;
        i/=10;
        for(int j=0;j<d-1;j++)
        {
            ans=ans*10+i%10;
            i/=10;
        }
        return ans;
    }
    else
    {
        ll ans=i;
        for(int j=0;j<d;j++)
        {
            ans=ans*10+i%10;
            i/=10;
        }
        return ans;
    }
}
bool isP(ll t)
{
    char s[100]={0};
    int i=0;
    while(t!=0)
    {
        s[i++]=t%10;
        t/=10;
    }
    for(int j=0,t=i-1;j<t;j++,t--)
    if(s[j]!=s[t])
    return 0;
    return 1;
}
ll solve(ll a)
{
    ll total=0;
    for(ll i=1;i*i<=a;i++)
    {
        ll t=make(i,0);
        if(t*t<=a && isP(t*t))
        total++;
        if(t*t>a)
        break;
        ll t2=make(i,1);
      //  cout<<i<<" "<<t<<" "<<t2<<" "<<endl;
        if(t2*t2<=a && isP(t2*t2))
        total++;
    }
    return total;
}
int main()
{
   // freopen("C-large-1.in","r",stdin);
    //freopen("C-large-1.out","w",stdout);
    int T;
    cin>>T;
    int casno=0;
    while(T--)
    {
        casno++;
        ll a,b;
        cin>>a>>b;
        cout<<"Case #"<<casno<<": ";
        cout<<solve(b)-solve(a-1)<<endl;
    }
    return 0;
}
