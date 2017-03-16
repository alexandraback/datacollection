#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	long long int n;
	int t;
}node;

int N,M;
node a[105],b[105];
long long int L[105][105];

long long int max(long long int a, long long int b)
{
	if(a>b)
		return a;
	else
		return b;
}

long long int subprob(int i,int j,long long int c1,long long int c2)
{
		if(i==N||j==M)
			L[i][j]=0;
		else{
			if(a[i].t==b[j].t)
			{
				if(c1>c2)
					L[i][j] = max(c2 + subprob(i,j+1,c1-c2,b[j+1].n),L[i][j]);
				else
					L[i][j] = max(L[i][j],c1 + subprob(i+1,j,a[i+1].n,c2-c1));
			}
			else
					L[i][j] = max(L[i][j],max(subprob(i+1,j,a[i+1].n,c2),subprob(i,j+1,c1,b[j+1].n) ));
		}
	return L[i][j];
}

int main()
{
	int f=1,g;
	scanf("%d",&g);
	while(f<=g)
	{
		int i,j;
		scanf("%d %d",&N,&M);
		for(i=0;i<N;i++)
			scanf("%lld %d",&a[i].n,&a[i].t);
		for(i=0;i<M;i++)
			scanf("%lld %d",&b[i].n,&b[i].t);
		for(i=0;i<=100;i++)
			for(j=0;j<=100;j++)
				L[i][j]=-1;

		subprob(0,0,a[0].n,b[0].n);
		printf("Case #%d: %lld\n",f,L[0][0]);
		f++;
	}
	return 0;
}
