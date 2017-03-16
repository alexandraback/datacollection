//Author: Vineet Shah
//IIT Indore
#include<bits/stdc++.h>
#define rep(i,start,lim) for(long long i=start;i<lim;i++)
#define repd(i,start,lim) for(long long i=start;i>=lim;i--)
#define MOD 1000000007
#define scan(x) scanf("%lld",&x)
#define print(x) printf("%lld",x)
#define sz(a) int((a).size())
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define present(c,x) ((c).find(x) != (c).end())
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define br printf("\n")
#define bit(x,i) (x&(1<<i))
using namespace std;
typedef long long lld;
lld powm(lld base,lld exp)
{
	lld ans=1;
	while(exp)
	{
		if(exp&1) ans=(ans*base);
		exp>>=1,base=(base*base);
	}
	return ans;
}
int main()
{
	freopen("D-small-attempt0.in","r",stdin);
	freopen("D-small-attempt0.out","w",stdout);
	lld t,k,c,s;
	scan(t);
	rep(ttt,1,t+1)
	{
		scan(k),scan(c),scan(s);
		if(s==k)
		{
			printf("Case #%lld: ",ttt);
			lld addd=powm(k,c-1),bada=powm(k,c);
			for(lld tt=0;tt<bada;tt+=addd)
				printf("%lld ",tt+1);
			br;
		}
	}
	return 0;
}


