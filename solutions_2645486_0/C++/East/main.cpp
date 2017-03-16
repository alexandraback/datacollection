#include<stdio.h>

int memo[10][100];

int optimize(int e,int current, int r, int n, int v[])
{
	if(n<=0)
		return 0;
	if(memo[current][n]!=-1)
		return memo[current][n];
	int max = -1;
	for(int i=0;i<=current;i++)
	{
		int ne = current-i+r;
		if(ne>e) ne = e;
		int gain = i*v[n-1] + optimize(e, ne, r, n-1, v);
		if(gain>max)
			max = gain;
	}
	return memo[current][n]=max;
}

int main()
{
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int e,r,n,v[100];
	int T;
	scanf("%d",&T);
	for(int c=1;c<=T;c++)
	{
		scanf("%d %d %d", &e, &r, &n);
		for(int i=0;i<n;i++)
			scanf("%d",&v[i]);
		for(int i=0;i<=e;i++)
			for(int j=0;j<=n;j++)
				memo[i][j]=-1;
		printf("Case #%d: %d\n",c,optimize(e,e,r,n,v));
	}
	return 0;
}