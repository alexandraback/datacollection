#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, j;
int a[10];
ll Shift(ll n,int x,int y)
{
	ll res=0, b=1;
	while(n)
	{
		res+=(n%x)*b;
		n/=x;
		b*=y;
	}
	return res;
}
ll prime(ll x)
{
	for(ll i=2;i*i<=x;i++) if(x%i==0) return i;
	return 0;
}
int ok(ll x)
{
	for(int i=2;i<11;i++)
	{
		ll xx=Shift(x,2,i);
		a[i-2]=prime(xx);
		if(!a[i-2]) return 0;
	}
	return 1;
}
void print0(ll x)
{
	printf("%lld",Shift(x,2,10));
	for(int i=0;i<9;i++) printf(" %d",a[i]);
	puts("");
}
void print(ll x)
{
	ll xx=Shift(x,2,10);
	ll a;
	for(int r=1;;r++)
	{
		a=Shift(r<<1|1,2,10);
		if(a>=xx) return ;
		if(xx%a==0) break;
	}
	j--;
	printf("%lld",xx);
	for(int i=2;i<11;i++) printf(" %lld",Shift(a,10,i));
	puts("");
}
void print2(ll x)
{
	ll xx=x, cnt=0;
	for(int i=1;xx;i=-i, xx>>=1)  if(xx&1) cnt+=i;
	if(cnt%11) return ;
	j--;
	for(int i=n;i;i--) printf("%d",x>>i-1&1);
	for(int i=2;i<11;i++) printf(" %d",i+1);
	puts("");
}
void run12()
{
	ll a=1LL<<n-1|1;
	for(int i=0;j && i< 1LL<<n-2;i++)
		if(ok(i<<1|a)) j--, print0(i<<1|a);
}
void run16()
{
	ll a=1LL<<n-1|1;
	for(int i=0;j && i< 1LL<<n-2;i++) print(i<<1|a);
}
void brun()
{
	ll a=1LL<<n-1|1;
	for(int i=0;j && i< 1LL<<n-2;i++) print2(i<<1|a);
}
int main()
{
	//freopen("C-small-attempt0.in","r",stdin);
	//freopen("C-large.in","r",stdin);
	//freopen("out.txt","w",stdout);
	int T, cas=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&j);
		printf("Case #%d:\n",++cas);
		if(n<13) run12();
		else if(n<17) run16();
		else brun();
	}
	return 0;
}

