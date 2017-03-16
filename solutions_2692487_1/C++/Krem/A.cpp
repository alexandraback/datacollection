#include<cstdio>
#include<algorithm>

#define MAX 100

int sizes[MAX];

int main()
{
	int T; scanf("%d",&T);
	for(int ii = 0; ii < T; ii++)
	{
		int A, N; scanf("%d %d", &A, &N);
		for(int i = 0; i < N; i++)
			scanf("%d",sizes+i);
		std::sort(sizes,sizes+N);
		int min = N, count = 0;
		for(int i = 0; i < N; i++)
		{
			if(A <= 1) break;
			while(A <= sizes[i])
			{
				count++;
				A += A-1;
			}
			A += sizes[i];
			if(count+N-i-1 < min)
				min = count+N-i-1;
		}
		printf("Case #%d: %d\n", ii+1, min);
	}
	return 0 ;
}
