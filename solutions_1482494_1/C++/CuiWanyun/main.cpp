#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<vector>
#include<list>
#include<cmath>
#include<cstdlib>

using namespace std;
const int maxn=3000;
int info[maxn][3],info1[maxn][3],info2[maxn][3];
int zt[maxn];//0,1,2
int n;
void init()
{
	int i;
	scanf("%d",&n);
	for (i=1;i<=n;i++)
		scanf("%d%d",&info[i][1],&info[i][2]);
}
void work()
{
	int i,j,temp,top1,top2,now,ans;
	memset(zt,0,sizeof(zt));
	for (i=1;i<=n;i++)
	{
		info1[i][0]=i;info1[i][1]=info[i][1];
		info2[i][0]=i;info2[i][1]=info[i][2];
	}
	for (i=1;i<n;i++)
		for (j=i+1;j<=n;j++)
		{
			if (info1[i][1]>info1[j][1])
			{
				temp=info1[i][1];
				info1[i][1]=info1[j][1];
				info1[j][1]=temp;
				temp=info1[i][0];
				info1[i][0]=info1[j][0];
				info1[j][0]=temp;
			}
			if (info2[i][1]>info2[j][1])
			{
				temp=info2[i][1];
				info2[i][1]=info2[j][1];
				info2[j][1]=temp;
				temp=info2[i][0];
				info2[i][0]=info2[j][0];
				info2[j][0]=temp;
			}
		}
	top1=1;top2=1;
	now=0;ans=0;
	while (top2<=n)
	{
		if (info2[top2][1]<=now)
		{
			ans++;
			if (zt[info2[top2][0]]==0) now+=2;
			else now+=1;
			zt[info2[top2][0]]=2;
			top2++;
			continue;
		}
/*		if (top1>n||info1[top1][1]>now)
		{
			printf("Too Bad\n");
			return;
		}
		if (zt[info1[top1][0]]!=0)
		{
			top1++;
			continue;
		}
		now++;
		ans++;
		zt[info1[top1][0]]=1;
		top1++;*/
		int tmax=-1,t;
		for (i=1;i<=n;i++)
			if (zt[i]==0&&info[i][1]<=now&&info[i][2]>tmax)
			{
				tmax=info[i][2];
				t=i;
			}
		if (tmax==-1)
		{
			printf("Too Bad\n");
			return;
		}
		ans++;now++;
		zt[t]=1;
	}
	printf("%d\n",ans);
}
int main()
{
	freopen("blargein.txt.","r",stdin);
	freopen("blargeout.txt","w",stdout);
	int cas,ii;
	scanf("%d",&cas);
	for (ii=1;ii<=cas;ii++)
	{
		init();
		printf("Case #%d: ",ii);
		work();
	}
	return 0;
}