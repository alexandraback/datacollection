#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<iostream>
#include<string>
const int  inf=1000000007;
#define ll long long


using namespace std;

ll a[100],b[100];

ll rev(ll x)
{
	ll y=0,x1=x;
	while(x1>0)
	{
		y=y*10+x1%10;
		x1/=10;
	}
	return y;
}
void task()
{
	ll n,ans=0,l=0,r=0;
	cin>>n;
	ll d[100]={0},p=0;
	while(n)
	{
		d[p++]=n%10;
		n/=10;
	}
	for(int i=(p-1)/2;i>=0;i--)r*=10,r+=d[i];
	for(int i=p-1;i>(p-1)/2;i--)l*=10,l+=d[i];
	ll revl=rev(l);
	for(int i=0;i<p;i++)ans+=b[i];
	if(r==0)
	{
		ll revl1,delta;
		if(revl!=1)
		{
			revl1=rev(l-1);
			delta=revl1+a[(p+1)/2]+(revl1!=1);
		}
		else delta=0;
		ans+=delta;
	}
	else
	{
		ll delta;
		if(revl!=1)delta=revl+r;else delta=r;
		ans+=delta;
	}
	if(l==0)ans--;
	printf("%lld\n",ans);
}
int main()
{
freopen("a.in","r",stdin);
freopen("a-1.out","w",stdout);
	for(int i=1;i<15;i++)a[i]=a[i-1]*10+9;
	b[0]=1,b[1]=9;
	for(int i=2;i<15;i++)
	{
		int s1=i/2;
		int s2=i-s1;
		b[i]=a[s1]+a[s2]+1;
	}
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;i++)
	{
		printf("Case #%d: ",i);
		task();
	}
	
	return 0;
}
