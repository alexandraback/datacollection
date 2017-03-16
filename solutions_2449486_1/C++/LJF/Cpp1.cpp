#include<stdio.h>
int arr[110][110];
int brr1[110],brr2[110];
bool fun(int n,int m)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		for(brr1[i]=0,j=0;j<m;j++)
		{
			if(arr[i][j]>brr1[i]) brr1[i]=arr[i][j];
		}
	}
	for(i=0;i<m;i++)
	{
		for(brr2[i]=0,j=0;j<n;j++)
		{
			if(arr[j][i]>brr2[i]) brr2[i]=arr[j][i];
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(arr[i][j]!=brr1[i]&&arr[i][j]!=brr2[j]) return 0;
		}
	}return 1;
}
int main()
{
	freopen("B-large.in","r",stdin);
	freopen("B-large.out","w",stdout);
	int T,cas;
	int n,m,i,j;
	scanf("%d",&T);
	for(cas=1;cas<=T;cas++)
	{
		scanf("%d%d",&n,&m);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				scanf("%d",&arr[i][j]);
			}
		}
		printf("Case #%d: ",cas);
		if(!fun(n,m)) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
