#include<bits/stdc++.h>
#define s(a) scanf("%lld",&a)
using namespace std;
typedef long long int ll;
inline ll gcd(ll a,ll b)
{
	if(a<b)return gcd(b,a);
	if(a%b==0)return b;
	return gcd(b,a%b);
}
bool ispower(ll a)
{
	ll s=1;
	for(ll i=0;i<=12;i++)
		if(s<<i == a)return true;
	return false;	
}
int main()
{
	ll tt,t,P,Q;
	s(t);
	for(tt=1;tt<=t;tt++)
	{
		scanf("%lld/%lld",&P,&Q);
		ll temp = gcd(P,Q);
		P = P/temp;
		Q = Q/temp;
		if(!ispower(Q)){cout<<"Case #"<<tt<<": impossible\n";continue;}
		ll ans = 1;
		while(2*P<Q)
		{
			P=2*P;
			ans++;	
		}	
		cout<<"Case #"<<tt<<": "<<ans<<endl;
	}
	return 0;	
}
