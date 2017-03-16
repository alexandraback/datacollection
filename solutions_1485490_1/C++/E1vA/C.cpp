#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

unsigned long long dp(int x,int y);
unsigned long long a[105],b[105];
unsigned long long f[105][105];
bool bb[105][105];
int A[105],B[105];
int n,m;
int T;

int getnext(int x,bool y)
{
	if(y==0)
	{
		for(int i=x+1;i<n;i++)
			if(A[i]==A[x])
				return i;
		return n;
	}
	else
	{
		for(int i=x+1;i<m;i++)
			if(B[i]==B[x])
				return i;
		return m;
	}
}

unsigned long long dp2(int x,int y,unsigned long long ta,unsigned long long tb)
{
	if(ta)
	{
		int ny=getnext(y,1);
		if(ny==m)
			return dp(x+1,y+1);
		if(ta>=b[ny])
			return max(b[ny]+dp2(x,ny,ta-b[ny],tb),dp(x+1,y+1));
		return max(ta+dp2(x,ny,0,b[ny]-ta),dp(x+1,y+1));
	}
	else
	{
		int nx=getnext(x,0);
		if(nx==n)
			return dp(x+1,y+1);
		if(tb>=a[nx])
			return max(a[nx]+dp2(nx,y,ta,tb-a[nx]),dp(x+1,y+1));
		return max(tb+dp2(nx,y,a[nx]-tb,0),dp(x+1,y+1));
	}
}
unsigned long long dp(int x,int y)
{
	if(x==n||y==m)
		return 0;
	if(!bb[x][y])
	{
		bb[x][y]=true;
		f[x][y]=0;
		if(A[x]!=B[y])
			f[x][y]=max(dp(x,y+1),dp(x+1,y));
		else
		{
			unsigned long long ta=a[x];
			unsigned long long tb=b[y];
			unsigned long long t=min(ta,tb);
			f[x][y]+=t;
			ta-=t;
			tb-=t;
			f[x][y]+=dp2(x,y,ta,tb);
		};
	}
	return f[x][y];
}

int main()
{
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	scanf("%d",&T);
	for(int test=1;test<=T;test++)
	{
		memset(bb,0,sizeof(bb));
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
			scanf("%I64u%d",&a[i],&A[i]);
		for(int i=0;i<m;i++)
			scanf("%I64u%d",&b[i],&B[i]);
		printf("Case #%d: %I64u\n",test,dp(0,0));
	}
	return 0;
}

