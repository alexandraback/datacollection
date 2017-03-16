#include<stdio.h>
#include<stdlib.h>
int max(int a,int b)
{
	return ((a)<(b)?(a):(b));
}
int comp(const void *a,const void *b)
{
	return *(int *)a-*(int *)b;
}
int sove(int A,int in[],int starti,int N)
{
	int i=starti,res=0;
	for(;i<N;i++)
	{
		if(A > in[i])
		{
			A += in[i];
		}
		else if(A == 1)
		{
			res ++ ;
		}
		else
		{
			res+=max(sove(A*2-1,in,i,N)+1,N-i);
			break;
		}
	}
	return res;
}
int main()
{
	int T,t,A,a,N,n,in[100];
	scanf("%d",&T);
	for(t=0;t<T;t++)
	{
		scanf("%d%d",&A,&N);
		for(n=0;n<N;n++)
			scanf("%d",&in[n]);
		qsort(in,N,sizeof(int),comp);
		printf("Case #%d: %d\n",t+1,sove(A,in,0,N));
	}
}
