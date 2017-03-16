#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

struct node
{
	int type;
	long long int num;
};

long long int doit(struct node *A, struct node *B,int i, int j, int N, int M)
{
	long long int res = 0;
	//printf("\n%d %d",i,j);
	
	if (A[i].type == B[j].type)
	{
		if (A[i].num == B[j].num)
		{
			res += A[i].num;
			//printf("\nRes : %lld",res);
			if ( (i+1) <=N && (j+1) <=M)
				return (res + doit(A,B,i+1,j+1,N,M));
			else
				return res;
		}
		else if (A[i].num > B[j].num)
		{
			res += B[j].num;
			//printf("\nRes : %lld",res);
			A[i].num -= B[j].num;
			if ((j+1) <=M)
			{
				long long int d = doit(A,B,i,j+1,N,M);
				A[i].num += B[j].num;
				return (res + d);
			}
			else
			{
				A[i].num += B[j].num;
				return res;
			}
		}	
		else
		{
			res += A[i].num;
			//printf("\nRes : %lld",res);
			B[j].num -= A[i].num;
			if ( (i+1) <=N )
			{
				long long int d = doit(A,B,i+1,j,N,M);
				B[j].num += A[i].num;
				return (res + d);
			}
			else 
			{
				B[j].num += A[i].num;
				return res;
			}
		}
	}
	else
	{	
		long long int r1 = 0;
		if ( (i+1) <=N )
			r1 += doit(A,B,i+1,j,N,M);
		long long int r2 = 0;
		if ((j+1) <=M)
			r2 += doit(A,B,i,j+1,N,M);
		//printf("\n L1 L2 %lld %lld",r1,r2);
		return max(r1,r2);
	}
	return res;
}

int main()
{
	int t,N,M;
	scanf("%d",&t);
	for (int tc = 1; tc <=t; tc++)
	{
		long long int res = 0;
		scanf("%d %d",&N,&M);
		struct node A[N+1],B[M+1];
		for (int i = 1; i <= N; i++)
		{
			scanf("%lld %d",&A[i].num,&A[i].type);
		}
		
		for (int i = 1; i <= M; i++)
		{
			scanf("%lld %d",&B[i].num,&B[i].type);
		}
		
		res = doit(A,B,1,1,N,M);
	
		printf("Case #%d: %lld",tc,res);
		printf("\n");
	}

	return 0;
}

