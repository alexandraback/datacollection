//freopen("A-small-attempt0.in","r",stdin);
//freopen("A-small-attempt0.out","w",stdout);
#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<iostream>
#include<vector>
#include<map>
using namespace std;
typedef __int64 ll;
const int INF = 1000000007;
const int N = 51;
char s[N][N];
int dp[N][N*N],nxt[N][N*N],a[N];
int dfs(int x,int y)
{
	if(!y){dp[x][y]=0;return 0;}
	if(dp[x][y]!=-1)return dp[x][y];
	dp[x][y]=INF;
	for(int i=2;i<=x&&i<=y;i++)
	{
		int tmp=dfs(i,y-i)+1;
		if(dp[x][y]>tmp)
		{
			nxt[x][y]=i;
			dp[x][y]=tmp;
		}
	}
}
int main()
{
    freopen("C-large.in","r",stdin);
    freopen("C-large.out","w",stdout);
	int T,i,j,ca=1;
	memset(dp,-1,sizeof(dp));
	for(i=0;i<N;i++)
	{
		for(j=0;j<N*N;j++)dfs(i,j);
	}
	scanf("%d",&T);
	while(T--)
	{
		int R,C,M;
		scanf("%d%d%d",&R,&C,&M);
		printf("Case #%d:\n",ca++);
		if(R*C-M==1)
		{
			for(i=1;i<=R;i++)
			{
				for(j=1;j<=C;j++)
				{
					if(i==1&&j==1)putchar('c');
					else putchar('*');
				}
				puts("");
			}
			continue;
		}
		if(R==1||C==1)
		{
			int k=M;
			for(i=0;i<R;i++)
			{
				for(j=0;j<C;j++)
				{
					if(k){s[i][j]='*';k--;}
					else s[i][j]='.';
				}
			}
			s[R-1][C-1]='c';
			for(i=0;i<R;i++)
			{
				for(j=0;j<C;j++)putchar(s[i][j]);
				puts("");
			}
			continue;
		}
		if(R*C-M<4){puts("Impossible");continue;}
		int k=R*C-M,fg=0;
		for(int st=2;st<=k/2&&st<=C;st++)
		{
			int mi=dp[st][k-2*st];
			if(mi<=R-2)
			{
				a[0]=a[1]=st;
				int x=st,y=k-2*st;
				for(i=0;i<mi;i++)
				{
					a[i+2]=nxt[x][y];
					x=nxt[x][y];
					y-=x;
				}
				for(i=0;i<R;i++)for(j=0;j<C;j++)s[i][j]='*';
				for(i=0;i<mi+2;i++)
				{
					for(j=0;j<a[i];j++)s[i][j]='.';
				}
				s[0][0]='c';
				for(i=0;i<R;i++)
				{
					for(j=0;j<C;j++)putchar(s[i][j]);
					puts("");
				}
				fg=1;
				break;
			}
		}
		if(!fg)puts("Impossible");
	}
	return 0;
}
