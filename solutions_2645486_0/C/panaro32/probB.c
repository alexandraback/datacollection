#include <stdio.h>
#include <stdlib.h>

int solve(int*,int,int,int,int,int);

int main()
{
	int T,i,E,R,N,j;
	int *A;
	scanf("%d",&T);
	for(i=0;i<T;i++)
	{
		scanf("%d%d%d",&E,&R,&N);
		A=(int*)malloc(N*sizeof(int));
		for(j=0;j<N;j++) scanf("%d",&A[j]);
		printf("Case #%d: %d\n",i+1,solve(A,N,E,R,E,0));
		free(A);
	}
	return 0;
}

int solve(int *A,int N,int E,int R,int e,int a)
{
	int i,max=0;
	if(a==N-1) return e*A[a];
	int maxE = e;
	int minE = (e+R>E)?e+R-E:0;
	for(i=minE;i<=maxE;i++)
	{
		int t = solve(A,N,E,R,e-i+R,a+1);
		if(A[a]*i+t>max) max=A[a]*i+t;
	}
	return max;
}
