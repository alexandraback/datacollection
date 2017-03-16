#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;
int f[2000000];
bool b[30];
int key[30];
int q[30][50];
int numst[50],num[50],s1[50],s2[50];
int Test,K,N,x,len;
bool pd(int x,int y,int z)
{
	len=0;
	while (x)
	{s1[++len]=f[x];x=x-(1<<(f[x]-1));}
	x=y;s2[1]=z;
	for (int i=2;i<=len;i++)
	{s2[i]=f[x];x=x-(1<<(f[x]-1));}
	for (int i=len;i;i--)
	{
		if (s1[i]<s2[i])return false;
		if (s1[i]>s2[i])return true;
	}
	return false;
}
int main()
{
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	scanf("%d",&Test);
	for (int tt=1;tt<=Test;tt++)
	{
		scanf("%d%d",&K,&N);
		memset(numst,0,sizeof(numst));
		for (int i=1;i<=K;i++)scanf("%d",&x),numst[x]++;
		for (int i=1;i<=N;i++)
		{
			scanf("%d",&key[i]);
			scanf("%d",&q[i][0]);
			for (int j=1;j<=q[i][0];j++)
			scanf("%d",&q[i][j]);
		}
		memset(f,128,sizeof(f));
		f[0]=0;
		for (int i=0;i<1<<N;i++)
		if (f[i]>=0)
		{
			for (int j=1;j<=N;j++)
			b[j]=i&(1<<(j-1));
			memcpy(num,numst,sizeof(num));
			for (int j=1;j<=N;j++)
			if (b[j])
			{
				for (int k=1;k<=q[j][0];k++)num[q[j][k]]++;
				num[key[j]]--;
			}
			for (int j=1;j<=N;j++)
			if (!b[j]&&num[key[j]])
			{x=i|(1<<(j-1));if (f[x]<0||pd(x,i,j))f[x]=j;}
		}
		x=(1<<N)-1;
		if (f[x]<0)printf("Case #%d: IMPOSSIBLE\n",tt);
		else
		{
			printf("Case #%d:",tt);
			len=0;
			while (x)
			{s1[++len]=f[x];x=x-(1<<(f[x]-1));}
			for (int i=len;i;i--)printf(" %d",s1[i]);
			printf("\n");
		}
	}
}
