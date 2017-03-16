#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long ddp[105][105];
long long sma[105][105];
long long smb[105][105];
struct node
{
	long long xt,xv;
}aa[105],bb[105];
long long maxx(long long a,long long b)
{
	return a>b?a:b;
}
long long minn(long long a,long long b)
{
	return a<b?a:b;
}
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int i,j,ii,jj,k,tcase,n,m,casenum=0;
	long long ans;
	scanf("%d",&tcase);
	while(tcase--)
	{
		memset(sma,0,sizeof(sma));
		memset(smb,0,sizeof(smb));
		scanf("%d%d",&n,&m);
		for (i=0;i<n;i++)
		{
			scanf("%lld%lld",&aa[i].xv,&aa[i].xt);
			sma[aa[i].xt][i+1]=aa[i].xv;
		}
		for (i=0;i<n;i++)
			for (k=0;k<=100;k++)
				sma[k][i+1]+=sma[k][i];
		for (i=0;i<m;i++)
		{
			scanf("%lld%lld",&bb[i].xv,&bb[i].xt);
			smb[bb[i].xt][i+1]=bb[i].xv;
		}
		for (i=0;i<m;i++)
			for (k=0;k<=100;k++)
				smb[k][i+1]+=smb[k][i];
		memset(ddp,0,sizeof(ddp));
		for (i=1;i<=n;i++)
			for (j=1;j<=m;j++)
			{
				if (aa[i-1].xt!=bb[j-1].xt)
				{
					ddp[i][j]=maxx(ddp[i-1][j],ddp[i][j-1]);
				}
			else
			{
				for (ii=0;ii<i;ii++)
					for (jj=0;jj<j;jj++)
						ddp[i][j]=maxx(ddp[i][j],ddp[ii][jj]+minn(sma[aa[i-1].xt][i]-sma[aa[i-1].xt][ii],smb[bb[j-1].xt][j]-smb[bb[j-1].xt][jj]));
			}
		}
		ans=0;
		for (i=0;i<=n;i++)
			for (j=0;j<=m;j++)
				ans=maxx(ans,ddp[i][j]);
			printf("Case #%d: %lld\n",++casenum,ans);
		}
		return 0;
}
