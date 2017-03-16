#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<vector>
#include<map>

using namespace::std;

int k,n,n1,ca,ip;

map<int,int> ke;

int keke[505];
int ee[25];
int d[1200005][45];
int dp[1200005][45];
int pa[1200005];
int la[505];
int init[505];
int chkey[505];
int getkey[505][207];
int path[505];

void input()
{
	int i,in,j,j1;
	scanf("%d %d",&k,&n);
	n1=0;
	ke.clear();
	for(i=0;i<505;i++)
		init[i]=0;
	for(i=1;i<=k;i++)
	{
		scanf("%d",&in);
		if(ke.find(in)==ke.end())
			ke[in]=++n1;
		init[ke[in]]++;
	}
	pa[0]=-1;
	for(i=0;i<=202;i++)
		d[0][i]=init[i];
	
	for(i=0;i<=n;i++)
		for(j=0;j<202;j++)
			getkey[i][j]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%d %d",&chkey[i],&j1);
			if(ke.find(chkey[i])==ke.end())
				ke[chkey[i]]=++n1;
		for(j=1;j<=j1;j++)
		{
			scanf("%d",&in);
			if(ke.find(in)==ke.end())
				ke[in]=++n1;
			getkey[i][ke[in]]++;
		}
	}
	for(i=1;i<ee[n];i++)
	{
		pa[i]=-1;
		for(j=0;j<=n1;j++)
			d[i][j]=0;
	}
}
void pro(int p,int le,int d1)
{
	int i,j,o;
	int d2=0,d3;
	if(p==0)
	{
		for(i=n-1;i>=0;i--)
		{
			if((ee[i]&d1)!=0)
			{
				d2=(ee[i]^d1);
		//printf("%d %d  %d\n",d1,d2,d[d2][ke[chkey[i+1]]]);
		//getchar();
				if(d[d2][keke[i+1]]>0)
				{
					o=0;
					if(pa[d1]!=-1)
					{
						d3=(ee[pa[d1]-1]^d1);
						for(j=1;j<ip;j++)
						{
							if(dp[d2][j]>dp[d3][j])
							{
								o=1;
								break;
							}
							if(dp[d2][j]<dp[d3][j])
								break;
						}
					}
					if(o==0)
					{
						pa[d1]=i+1;
						for(j=0;j<=n1;j++)
							d[d1][j]=d[d2][j]+getkey[i+1][j];
						for(j=1;j<ip;j++)
							dp[d1][j]=dp[d2][j];
						dp[d1][ip]=i+1;
						d[d1][keke[i+1]]--;
					}
				}
			}
		}
	}
	else
	{
		for(i=le;i<=n-p+1;i++)
		{
			pro(p-1,i+1,d1+ee[i-1]);
		}
	}
}
void process()
{
	int i,o=0;
	for(i=1;i<=n;i++)
	{
		if( ke.find(chkey[i])!=ke.end())
		{
			keke[i]=ke[chkey[i]];
		}
		else 
			o=1;
	}
	if(o==0)
	{
		for(i=1;i<=n;i++)
		{
			ip=i;
			pro(i,1,0);
		}
	}
}
void output()
{
	int i,pa1=0,pai=0;
	ca++;
	printf("Case #%d:",ca);
	if(pa[ee[n]-1]==-1)
		printf(" IMPOSSIBLE\n");
	else
	{
		pa1=ee[n]-1;
		while(pa1!=0)
		{
			la[++pai]=pa[pa1];
			pa1-=ee[pa[pa1]-1];
		}
		for(i=n;i>=1;i--)
			printf(" %d",la[i]);
		printf("\n");
	}
}

int main()
{
	int i,t;
	ee[0]=1;
	for(i=1;i<=21;i++)
		ee[i]=ee[i-1]*2;
	//freopen("input.txt","rt",stdin);
	freopen("D-small-attempt3.in","rt",stdin);
	freopen("D-small-attempt3.out","wt", stdout);
	scanf("%d",&t);
	while(t--)
	{
		input();
		process();
		output();
	}
	return 0;
}