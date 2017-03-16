#include<iostream>
#include<cstdio>

using namespace std;

const int maxn=11000;
int num,n,x,y,ca;
double ans;
double f[maxn][maxn];
int calc(int x)
{
	return (x+1)*x/2;
}

void deal(int x,int y)
{
	f[0][0]=1;
	for (int i=0; i<=x; i++)
		for (int j=0; j<=x; j++)
			if ((i+j<=y) && ((i!=0) || (j!=0)))
			{
				f[i][j]=0;
				if (i-1>=0)
					if (j==x) f[i][j]+=f[i-1][j]; else f[i][j]+=f[i-1][j]*0.5;
				
				if (j-1>=0) 
					if (i==x) f[i][j]+=f[i][j-1]; else f[i][j]+=f[i][j-1]*0.5;

			}
			
}
void solve()
{
	x=abs(x); y=abs(y);
	printf("Case #%d: ",++ca);		
	
	int sum=x+y+1;
	if (calc(sum)<=n) 
	{
		printf("1.0000000\n");
		return;
	}

	if (calc(sum-2)>=n)
	{
		printf("0.0000000\n");
		return;
	}


	int k=n-calc(sum-2);
	deal(sum-1,k);
	ans=0;
	for (int i=y+1; i<=sum-1; i++)
		if (k-i>=0) ans+=f[i][k-i];
	printf("%.7lf\n",ans);
	
}
void init()
{
	scanf("%d",&num);
	while (num--)
	{
		scanf("%d%d%d",&n,&x,&y);
		solve();
	}
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	init();
	return 0;
}
