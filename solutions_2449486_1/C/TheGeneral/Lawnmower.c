#include<stdio.h>

int process(int ,int ,int a[][100]);

int main()
{
	int t,n,m;
	int i,j,k;
	int a[100][100];
	int flag;

	scanf("%d",&t);
	for(i=0;i<t;i++)
	{
		scanf("%d%d",&n,&m);
		for(j=0;j<n;j++)
			for(k=0;k<m;k++)
				scanf("%d",&a[j][k]);
		flag = process(n,m,a);
		if (flag ==1)
			printf("Case #%d: YES\n",i+1);
		else 
			printf("Case #%d: NO\n",i+1);
	}
	return 0;
}

int process(int n,int m,int a[100][100])
{
	int i,j,k;
	int b[100],c[100];

	for(i=0;i<n;i++)
	{
		b[i] = a[i][0];
		for(j=1;j<m;j++)
			if (b[i] < a[i][j])
				b[i] = a[i][j];
	}
	for(i=0;i<m;i++)
	{
		c[i] = a[0][i];
		for(j=1;j<n;j++)
			if (c[i] <a[j][i])
				c[i] = a[j][i];
	}

	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			if (a[i][j] < b[i] &&a[i][j]<c[j])
				return 0;
		}
	return 1;
}


