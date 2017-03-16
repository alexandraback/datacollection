#include <stdio.h>

const int maxn=10;

int num[maxn],need[maxn],ok[1<<maxn];
bool fin;
int i,j,k,m,n,r,t,tt,tot;


void make(int now,int sum)
{
	if (now>n)
	{
		ok[sum]=tot;
		return;
	}
	make(now+1,sum);
	make(now+1,sum*num[now]);
}

bool check()
{
	int i,j;

	tot++;
	make(1,1);
	for (i=1;i<=k;i++)
		if (ok[need[i]]!=tot)
			return false;
	return true;
}

void search(int now,int la)
{
	int i;

	if (now>n)
	{
		if (check())
			fin=true;
		return;
	}
	for (i=la;i<=m;i++)
	{
		num[now]=i;
		search(now+1,i);
		if (fin)
			return;
	}
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&t);
	printf("Case #1:\n");
	scanf("%d%d%d%d",&r,&n,&m,&k);
	for (i=1;i<=r;i++)
	{
		for (j=1;j<=k;j++)
			scanf("%d",&need[j]);
		fin=false;
		search(1,2);
		for (j=1;j<=n;j++)
			printf("%d",num[j]);
		printf("\n");
	}
	return 0;
}
