#include <bits/stdc++.h>

using namespace std;

long long p2[50];

void init()
{
	p2[0]=1;
	for(int i=1;i<=32;i++)
		p2[i]=p2[i-1]*2;
}

void out(long long x,long long y)
{
	int que[35],l=0;
	while(x)
	{
		que[++l]=(x&1);
		x>>=1;
	}
	for(int i=l;i>=1;i--)
		printf("%d",que[i]);
	l=0;
	while(y)
	{
		que[++l]=(y&1);
		y>>=1;
	}
	for(int i=2;i<=10;i++)
	{
		long long ans=0;
		for(int j=l;j>=1;j--)
		{
			ans*=i;
			if(que[j]==1)
				ans+=1;

		}
		printf(" %lld",ans);
	}
	puts("");
}

void solve(int l,int num)
{
	int cnt=num;
	for(int a=2,b=l-1;a<b;a++,b--)
	{
		for(int mid=0;mid<p2[a-2];mid++)
		{
			long long x=mid*2+p2[a-1]+1;
			long long y=1+p2[b-1];
			long long ans=x*y;
			if(cnt)
			{
				out(ans,x);
				cnt--;
			}
			else
				return;
		}
	}
}

int main()
{

	freopen("C-small-attempt0.in","r",stdin);
	freopen("out","w",stdout);

	init();

	int cases=0,n,j;

	while(scanf("%d",&cases)!=EOF)
	{
		for(int t=1;t<=cases;t++)
		{
			scanf("%d%d",&n,&j);
			printf("Case #%d:\n",t);
			solve(n,j);
		}
	}
}
