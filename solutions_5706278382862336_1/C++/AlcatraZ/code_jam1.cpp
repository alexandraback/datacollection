#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#include<cctype>
#include<queue>
#define inf 99999999
#define siz 10002
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

ll f(ll a)
{
    ll p=1;
    while(a>1)
    {
        a=a>>1;
        p=p<<1LL;
    }
    return p;


}

ll po(ll a)
{
    ll c;
    while(a>0)
    {
        a=a>>1;

        c++;
    }
    return c;
}


bool chec(ll b)
{
    while(b>1)
    {
        if(b%2==0)
        b=b>>1;
        else break;

    }
    if(b>1) return 0;
     return 1;
}
int main()
{

    freopen("in1.txt","r",stdin);
    freopen("out.txt","w",stdout);
	int i,j,k,n,test,t,l,q,pos;char c;
	ll a,b,mina,maxb,ans,p;
	scanf("%d",&t);
	for(test=1;test<=t;test++)
	{
        ans=1;
		scanf("%lld%c%lld",&a,&c,&b);
        p=gcd(a,b);
        a/=p;
        b/=p;
		printf("Case #%d: ",test);

        if(!chec(b)) {printf("impossible\n");continue;}
        b=b>>1;
		while(a<b)
        {
            b=b>>1;
            ans++;

        }

        //printf("%lld %lld\n",a,b);
        printf("%lld\n",ans);






	}
	return 0;
}
