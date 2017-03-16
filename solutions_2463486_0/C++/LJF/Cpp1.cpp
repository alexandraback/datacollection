#include<stdio.h>
#include<math.h>
#define ll __int64
ll ans;
int arr[100];
bool yy(ll a)
{
	int len=0;
	do 
	{
		arr[len++]=a%10;
		a/=10;
	} while (a!=0);
	int i;
	for(i=0;i<len/2;i++)
	{
		if(arr[i]!=arr[len-i-1]) return 0;
	}
	return 1;
}
void fun(ll a,ll b)
{
	ll i,aa,bb,cc;
	aa=sqrt(a);
	if(aa>1) aa--;
	bb=sqrt(b);
	bb++;

	for(i=aa;i<=bb;i++)
	{
		cc=i*i;
		if(cc>=a&&cc<=b)
		{
			if(!yy(i)) continue;
			if(yy(cc)) ans++;
		}
	}
}
int main()
{
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int T,cas;
	ll a,b;
	scanf("%d",&T);
	for(cas=1;cas<=T;cas++)
	{
		scanf("%I64d%I64d",&a,&b);
		ans=0;
		fun(a,b);
		printf("Case #%d: %I64d\n",cas,ans);
	}
}