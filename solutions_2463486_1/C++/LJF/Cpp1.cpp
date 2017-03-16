#include<stdio.h>
#include<math.h>
#define ll __int64
ll ans[40];
int len_a;
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
			if(yy(cc)) ans[len_a++]=cc;
		}
	}
}
int main()
{
	len_a=0;
	fun(1,100000000000000);
	freopen("C-large-1.in","r",stdin);
	freopen("C-large-1.out","w",stdout);
	int T,cas;
	ll a,b;
	int i;
	scanf("%d",&T);
	for(cas=1;cas<=T;cas++)
	{
		scanf("%I64d%I64d",&a,&b);
		int num=0;
		for(i=0;i<39;i++)
		{
			if(ans[i]>=a&&ans[i]<=b) num++;
		}
		printf("Case #%d: %d\n",cas,num);
	}
}