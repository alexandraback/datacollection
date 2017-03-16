#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;
int Test,N,M,Min,flag,kx,ky;
int a[200][200];
bool b[200][200];
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d",&Test);
	for (int tt=1;tt<=Test;tt++)
	{
		scanf("%d%d",&N,&M);
		for (int i=1;i<=N;i++)
		for (int j=1;j<=M;j++)
		scanf("%d",&a[i][j]);
		memset(b,true,sizeof(b));
		for (int ii=1;ii<=N+M;ii++)
		{
			Min=2e9;
			for (int i=1;i<=N;i++)
			for (int j=1;j<=M;j++)
			if (b[i][j]&&Min>a[i][j])
			{
				Min=a[i][j];
				kx=i;ky=j;
			}
			if (Min==2e9)break;
			flag=1;
			for (int i=1;i<=N;i++)
			if (b[i][ky]&&a[i][ky]!=Min)
			{flag=0;break;}
			if (!flag)
			{
				flag=2;
				for (int j=1;j<=M;j++)
				if (b[kx][j]&&a[kx][j]!=Min)
				{flag=0;break;}
			}
			if (!flag)break;
			if (flag==1)for (int i=1;i<=N;i++)b[i][ky]=false;
			if (flag==2)for (int j=1;j<=M;j++)b[kx][j]=false;
		}
		if (!flag)printf("Case #%d: NO\n",tt);
		else printf("Case #%d: YES\n",tt);
	}
}
