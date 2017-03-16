#include<bits/stdc++.h>
using namespace std;
#define sd(x) scanf("%lld",&x)
#define slld(x) scanf("%lld",&x)
#define ss(x) scanf("%s",x)
#define ll long long
#define mod 1000000007
#define bitcount    __builtin_popcountll
#define pb push_back
ll n,n3,n4,diff;
char a[22],b[22];
void f(ll n1,ll n2,ll i)
{
    if(i==n)
    {
        if(abs(n1-n2)<diff)
        {
            n3=n1;n4=n2;
            diff=abs(n1-n2);
        }
        if(abs(n1-n2)==diff&&n1<=n3&&n2<=n4)
        {
            n3=n1;n4=n2;
        }
        return;
    }
    if(a[i]=='?'&&b[i]=='?')
    {
        f(n1*10,n2*10,i+1);
        f(n1*10+1,n2*10,i+1);
        f(n1*10,n2*10+1,i+1);
        f(n1*10+9,n2*10,i+1);
        f(n1*10,n2*10+9,i+1);
    }
    else if(a[i]=='?')
    {
        f(n1*10+b[i]-'0',n2*10+b[i]-'0',i+1);
        f(n1*10+(b[i]-'0'+1)%10,n2*10+b[i]-'0',i+1);
        f(n1*10+(b[i]-'0'+9)%10,n2*10+b[i]-'0',i+1);
        f(n1*10+9,n2*10+b[i]-'0',i+1);
        f(n1*10,n2*10+b[i]-'0',i+1);
    }
    else if(b[i]=='?')
    {
        f(n1*10+a[i]-'0',n2*10+a[i]-'0',i+1);
        f(n1*10+a[i]-'0',n2*10+(a[i]-'0'+1)%10,i+1);
        f(n1*10+a[i]-'0',n2*10+(a[i]-'0'+9)%10,i+1);
        f(n1*10+a[i]-'0',n2*10+9,i+1);
        f(n1*10+a[i]-'0',n2*10,i+1);
    }
    else
        f(n1*10+a[i]-'0',n2*10+b[i]-'0',i+1);
}
int main()
{
    freopen("codejamclosein.txt","r",stdin);
    freopen("codejamcloseinout.txt","w",stdout);
    ll t,x,i,j,k,c,s1[22],s2[22],n1,n2;
    sd(t);
    for(x=1;x<=t;x++)
    {
        ss(a);
        ss(b);
        n=strlen(a);
        diff=1;
        for(i=0;i<=n;i++)
            diff*=10;

        f(0,0,0);
        i=n;
        n1=n3;n2=n4;
        while(i--)
        {
            s1[i]=n1%10;
            s2[i]=n2%10;
            n2/=10;
            n1/=10;
        };
        while(n1!=0)
        {
            n1/=10;
            j++;
        }
        printf("Case #%lld: ",x);
        for(i=0;i<n;i++)
            printf("%lld",s1[i]);
        printf(" ");
        for(i=0;i<n;i++)
            printf("%lld",s2[i]);
        printf("\n");
    }
    return 0;
}
