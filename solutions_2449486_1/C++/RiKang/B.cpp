#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace::std;

int n,m,ca,la;
int a[105][105];
int m1[105];
int m2[105];

void input()
{
	int i,j;
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
}
void process()
{
	int i,j,k,o,p;
	la=0;
	for(i=1;i<=n;i++)
		m1[i]=-2140000000;
	for(i=1;i<=m;i++)
		m2[i]=-2140000000;
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(m1[i]<a[i][j])
				m1[i]=a[i][j];
			if(m2[j]<a[i][j])
				m2[j]=a[i][j];
		}
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			if(a[i][j]<m1[i] && a[i][j]<m2[j])
				la=1;
		}
	}
}
void output()
{
	if(la==0)
		printf("Case #%d: YES\n",ca);
	else
		printf("Case #%d: NO\n",ca);
}

int main()
{
	int i,t;
	freopen("B-large.in","rt",stdin);
	freopen("B-large.out","wt", stdout);
	scanf("%d",&t);
	while(t--)
	{
		ca++;
		input();
		process();
		output();
	}
	return 0;
}