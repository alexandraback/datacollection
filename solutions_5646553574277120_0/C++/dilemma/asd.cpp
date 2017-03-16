#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<math.h>
#include<algorithm>
using namespace std;
const int maxn=1010;
const int INF=1<<28;
int a[105];
int c[105];
int d[105];
int A[105];
bool use[105];
int n,m,nn,cur,now;
bool dfs(void);
bool can(void);
int main(void)
{
	int i,j,pi,qi,ans,C;
	bool OK;
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	scanf("%d",&pi);
	for(qi=1;qi<=pi;qi++)
	{
		scanf("%d%d%d",&C,&n,&m);
		for(i=1;i<=m;i++)
		{
			use[i]=false;
		}
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			c[i]=a[i];
			use[a[i]]=true;
		}
		nn=n;
		OK=can();
		if(OK==true)
		{
			ans=0;
		}
		else
		{
			OK=false;
			ans=5;
			for(i=1;i<=4;i++)
			{
				now=i;
				A[0]=0;
				cur=1;
				nn=now+n;
				OK=dfs();
				if(OK==true)
				{
					ans=i;
					break;
				}
			}
		}
		printf("Case #%d: %d\n",qi,ans);
	}
	return 0;
}
bool dfs(void)
{
	int i;
	bool OK;
	if(cur>now)
	{
		for(i=1;i<=n;i++)
		{
			c[i]=a[i];
		}
		for(i=1;i<=now;i++)
		{
			c[n+i]=A[i];
		}
		OK=can();
		return OK;
	}
	else
	{
		for(i=A[cur-1]+1;i<=m;i++)
		{
			if(use[i]==false)
			{
				use[i]=true;
				A[cur]=i;
				cur++;
				OK=dfs();
				if(OK==true)
				{
					return true;
				}
				cur--;
				use[i]=false;
			}
		}
		return false;
	}
}
bool can(void)
{
	int i,j;
	for(i=1;i<=m;i++)
	{
		d[i]=0;
	}
	d[0]=1;
	for(i=1;i<=nn;i++)
	{
		for(j=m;j>=c[i];j--)
		{
			d[j]=(d[j]|d[j-c[i]]);
		}
	}
	for(i=1;i<=m;i++)
	{
		if(d[i]==0)
		{
			return false;
		}
	}
	return true;
}