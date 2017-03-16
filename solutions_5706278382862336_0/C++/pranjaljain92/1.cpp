#include<vector>
#include<stack>
#include<set>
#include<map>
#include<queue>
#include<deque>
#include<string>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cassert>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<string>

using namespace std;

#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%lf",&n)
#define ss(n) 					scanf("%s",n)
#define sc(n)                   {char temp[4]; ss(temp); n=temp[0];}
#define INF						(int)1e9
#define LINF					(long long)1e18
#define EPS						1e-9
#define MAX(a,b)				((a)>(b)?(a):(b))
#define MIN(a,b)				((a)<(b)?(a):(b))
#define ABS(x)					((x)<0?-(x):(x))

typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VII;
typedef vector<TRI> VT;

LL gcd(LL a,LL b)
{
    if(a==0)
    return(b);

    return gcd(b%a,a);
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int i,t,x,n;
    LL p,q,g,qq,ans;
    char str[1000];
    s(t);
    for(x=1;x<=t;x++)
    {
        scanf("%s",str);
        n=strlen(str);
        p=0;
        for(i=0;i<n;i++)
        {
            if(str[i]=='/')
            break;
            p=10*p+(str[i]-'0');
        }
        i++;
        q=0;
        for(;i<n;i++)
        {
            q=10*q+(str[i]-'0');
        }
        //printf("%lld %lld\n",p,q);
        g=gcd(p,q);
        p/=g;
        q/=g;

        qq=q;
        while(qq%2==0)
        qq/=2;

        if(qq!=1)
        {
            printf("Case #%d: impossible\n",x);
            continue;
        }

        ans=1;
        while(2*p<q)
        {
            ans++;
            p*=2;
        }
        printf("Case #%d: %lld\n",x,ans);
    }
    return(0);
}

