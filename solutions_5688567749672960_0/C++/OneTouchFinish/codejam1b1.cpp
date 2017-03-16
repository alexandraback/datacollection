#include<bits/stdc++.h>
#define rep(i,s,n) for((i)=(s);(i)<=(n);(i)++)
#define getint(x) scanf("%d",&x)
#define getlong(x) scanf("%lld",&x)
#define putint(x) printf("%d",x)
#define putintln(x) printf("%d\n",x)
#define putlong(x) printf("%lld",x)
#define putlongln(x) printf("%lld\n",x)
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
int nodi(ll x)
{
	int res=0;
	while(x>0)
	{
		res++;
		x/=10;
	}
	return res;
}

ll power(int nod)
{
	if(nod==0)
		return 1;
	if(nod==1)
		return 10;
	ll f=power(nod/2);
	f*=f;
	if(nod%2==1)
		f*=10;
	return f;
}

ll rev(ll x)
{
	ll res=0;
	while(x>0)
	{
		ll r=x%10;
		res=res*10+r;
		x/=10;
	}
	return res;
}

ll ar[1000005];
void solve()
{
	int i;
	rep(i,0,19)
		ar[i]=i;
	rep(i,20,1000000)
	{
		if(i%10==0)
			ar[i]=ar[i-1]+1;
		else
		{
			ll r=rev(i);
			if(r>=i)
				ar[i]=ar[i-1]+1;
			else
				ar[i]=min(ar[i-1],ar[r])+1;
		}
	}	
}

int main()
{
	int t,ind,i;
	getint(t);
	ll n;
	solve();
	rep(ind,1,t)
	{
		getlong(n);
		printf("Case #%d: %lld\n",ind,ar[n]);
	}
}