#include<stdio.h>
#include<stdlib.h>
#include <string.h>
const int MAX = 100;
bool vis[3000000];
int s,cnt;
bool fg,flg;
int cmp(const void *a, const void *b)
{
	return *(int*)a - *(int*)b;
}
void fullCombination(int num[], int rcd[], int cur, int begin, int n)
{
	if(fg)
		return;
	int i;
	int sum=0;
	for(i=0; i<cur; ++i)
		sum+=rcd[i];
	if(!vis[sum])
		vis[sum]=1;
	else
	{
		s=sum;
		fg=1;
		return ;
	}
	for(i=begin; i<n; ++i)
	{
		rcd[cur] = num[i];
		if(!fg)
			fullCombination(num, rcd, cur+1, i+1, n);
	}
}
void fullCombination1(int num[], int rcd[], int cur, int begin, int n)
{
	int i,sum=0;
	if(flg)
		return;
	for(i=0; i<cur; ++i)
		sum+=rcd[i];
	if(sum==s && cnt<2)
	{
		for(i=0; i<cur; ++i)
			printf("%d ", rcd[i]);
		printf("\n");
		cnt++;
	}
	if(cnt>=2)
	{
		flg=1;
		return;
	}
	for(i=begin; i<n; ++i)
	{
		rcd[cur] = num[i];
		fullCombination1(num, rcd, cur+1, i+1, n);
	}
}
int main()
{
	//	freopen("d:\\gcj\\c1.in","r",stdin);
	//	freopen("d:\\gcj\\c1.out","w",stdout);
	int num[MAX], rcd[MAX], i, n,t,j,num1[MAX], rcd1[MAX];
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		fg=0;
		cnt=0;
		flg=0;
		s=0;
		memset(vis,0,sizeof(vis));
		scanf("%d", &n);
		for(j=0; j<n; ++j)
			scanf("%d",&num[j]);
		for(j=0;j<n;j++)
			num1[j]=num[j];
		qsort(num, n, sizeof(num[0]), cmp);
		fullCombination(num, rcd, 0, 0, n);
		printf("Case #%d:\n",i);
	//	printf("%d\n",s);
		if(!fg)
		{
			puts("Impossible");
			continue;
		}
		fullCombination1(num1, rcd1, 0, 0, n);
	}
	return 0;
}