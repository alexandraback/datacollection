#include<iostream>
#include<stdio.h>
#include<cmath>
#include<cstring>
#include<stdlib.h>
#include<algorithm>
#include<limits.h>
#include<stack>
using namespace std;

/*printing definitions*/
#define pi(x) printf("%d\n",(x))
#define pii(x,y) printf("%d %d\n",(x),(y))
#define pl(x) printf("%lld\n",(x))
#define pll(x,y) printf("%lld %lld\n",(x),(y))
#define pil(x,y) printf("%d %lld\n",(x),(y))
#define pli(x,y) printf("%lld %d\n",(x),(y))
#define plf(x) printf("%lf\n",(x))
#define plflf(x,y) printf("%lf %lf\n",(x),(y))

/*scanning definitions*/
#define si(x) scanf("%d",&x)
#define sii(x,y) scanf("%d %d",&x,&y)
#define sl(x) scanf("%lld",&x)
#define sll(x,y) scanf("%lld %lld",&x,&y)
#define sil(x,y) scanf("%d %lld",&x,&y)
#define sli(x,y) scanf("%lld %d",&x,&y)
#define slf(x) scanf("%lf",&x)
#define slflf(x,y) scanf("%lf %lf",&x,&y)

/*looping definitions */
#define for(x,y,z) for(x=y;x<z;x++)
#define forr(x,y,z) for(x=y;x<z;x--)
//  CREATED BY: ATUL SEHGAL
long long int gcd(long long int u, long long int v)
{
     if(v==0) return u;
     else return gcd(v,u%v);
}
long long int isp(long long int q)
{
    while(q)
    {
        if(q&1 && q>2)
            return 0;
        q/=2;
    }
    return 1;
}
int main()
{
    freopen("input-Alarge.txt","r",stdin);
    freopen("output-Alarge.txt","w",stdout);
	long long int T=1,t,i,j,n,p,q,ans,f;
	sl(t);
	while(t--)
	{
	    f=0;
	    ans=0;
		scanf("%lld/%lld",&p,&q);
		while(gcd(p,q)!=1)
        {
            j=gcd(p,q);
            p/=j;
            q/=j;
        }
		while(!(p/q))
        {
            if(q&1)
                break;
            q/=2;
            ans++;
        }
        //if((1+p/q)/2 ==P)
		printf("Case #%lld: ",T++);
	    if(!isp(q))
            printf("impossible\n");
        else
            pl(ans);
	}
	return 0;
}
