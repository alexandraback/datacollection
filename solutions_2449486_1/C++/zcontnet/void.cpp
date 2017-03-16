#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int a[105][105],col[105],row[105];
int n,m;

int judge()
{
	int i,j;
	for(i=1;i<=n;i++)
	{
		row[i]=0;
		for(j=1;j<=m;j++) row[i]=max(row[i],a[i][j]);
	}
	for(j=1;j<=m;j++)
	{
		col[j]=0;
		for(i=1;i<=n;i++) col[j]=max(col[j],a[i][j]);
	}
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{
			int x=min(row[i],col[j]);
			if(a[i][j]!=x) return 0;
		}
	return 1;
}

int main()
{
	freopen("A.in","r",stdin);
	freopen("ans.txt","w",stdout);
	int T,tc,i,j;
	scanf("%d",&T);
	for(tc=1;tc<=T;tc++)
	{
		scanf("%d%d",&n,&m);
		for(i=1;i<=n;i++)
			for(j=1;j<=m;j++)
				scanf("%d",&a[i][j]);
		if(judge()) printf("Case #%d: YES\n",tc);
		else printf("Case #%d: NO\n",tc);
	}
	return 0;
}
		