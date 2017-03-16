#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>

using namespace std;

#define s(n) scanf("%d",&n)
#define sl(n) scanf("%ld",&n)
#define sll(n) scanf("%lld",&n)
#define p(n) printf("%d ",n)
#define pl(n) printf("%ld ",n)
#define pll(n) printf("%lld\n",n)
#define fo(i,a,b) for(i=a;i<b;i++)
#define rf(i,a,b)	for(i=a;i>=b;i--)
# define toint(n)	(n-'0')
typedef long long ll;


int main()
{
	//freopen("AB.in","r",stdin);
    //freopen("AB.out","w",stdout);
    int t,z;
    int w,r,c,i,temp;
    ll ans;
    
    s(t);
    fo(z,1,t+1)
   	{
   		ans=0;
		s(r); s(c); s(w);

		temp=c/w;
		ans+=temp;

		temp*=w;
		c-=temp;
		if(c>0)
			ans+=w;
		else
			ans+=(w-1);

		printf("Case #%d: %lld\n",z,ans);
	}
	return 0;
}