#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <queue>
#include <iostream>
#define maxn 100009
#define maxm
using namespace std;
int tt,n;
long long x;
char s[maxn];
int a[maxn],b[4*maxn];
int mx[5][5]
{
	{0,0,0,0,0},
	{0,1,2,3,4},
	{0,2,-1,4,-3},
	{0,3,-4,-1,2},
	{0,4,3,-2,-1}
};
int mul(int x,int y)
{
	int sg=1;
	if(x<0)
		sg=-sg;
	if(y<0)
		sg=-sg;
	x=abs(x);
	y=abs(y);
	return sg*mx[x][y];
}
int Exp(int a,long long b)
{
	int res=1;
	while(b)
	{
		if(b&1)
			res=mul(res,a);
		a=mul(a,a);
		b>>=1;
	}
	return res;
}
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	scanf("%d",&tt);
	int cot=1;
	while(tt--)
	{	
		scanf("%d%I64d",&n,&x);
		scanf("%s",s+1);
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='i')
				a[i]=2;
			else if(s[i]=='j')
				a[i]=3;
			else if(s[i]=='k')
				a[i]=4;
		}
		int sum=1;
		for(int i=1;i<=n;i++)
		{
			sum=mul(sum,a[i]);
		}
		int ans=Exp(sum,x);
		if(ans!=-1)
		{
			printf("Case #%d: NO\n",cot++);
			continue;
		}
		int tot=0;
		for(int i=1;i<=4;i++)
		{
			for(int j=1;j<=n;j++)
			{
				b[++tot]=a[j];
			}
		}
		int L=-1;
		sum=1;
		for(int i=1;i<=tot;i++)
		{
			sum=mul(sum,b[i]);
			if(sum==2)
			{
				L=i;
				break;
			}
		}
		if(L==-1)
		{
			printf("Case #%d: NO\n",cot++);
			continue;
		}
		int R=-1;
		sum=1;
		for(int i=tot;i>=1;i--)
		{
			sum=mul(b[i],sum);
			if(sum==4)
			{
				R=tot-i+1;
				break;
			}
		}
		if(R==-1)
		{
			printf("Case #%d: NO\n",cot++);
			continue;
		}
		if(L+R>=n*x)
		{
			printf("Case #%d: NO\n",cot++);
			continue;
		}
		printf("Case #%d: YES\n",cot++);
	}
	return 0;
}
