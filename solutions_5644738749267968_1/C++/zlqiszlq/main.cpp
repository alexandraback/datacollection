#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
#define MAXN 1100

double A[MAXN],B[MAXN];
int T,N;

int main()
{
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	int i,j,k;
	scanf("%d",&T);
	for (int cases=1;cases<=T;cases++)
	{
		scanf("%d",&N);
		for (i=0;i<N;i++)
		{
			scanf("%lf",&A[i]);
		}
		for (i=0;i<N;i++)
		{
			scanf("%lf",&B[i]);
		}
		sort(A,A+N);
		sort(B,B+N);
		for (k=0;k<=N;k++)
		{
			bool yes = true;
			for (i=0;i<N-k;i++)
			{
				if (A[i + k] < B[i])
				{
					yes = false;
					break;
				}
			}
			if (yes)
			{
				break;
			}
		}
		printf("Case #%d: %d ",cases,N-k);
		j = 0;
		k = 0;
		for (i=0;i<N;i++)
		{
			while (j < N && B[j] < A[i])
			{
				j++;
			}
			if (j < N)
			{
				j ++;
				k ++;
			}
			else
			{
				break;
			}
		}
		printf("%d\n",N-k);
	}
    return 0;
}
