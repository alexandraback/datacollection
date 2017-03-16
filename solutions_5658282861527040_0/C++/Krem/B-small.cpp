#include<cstdio>

int main()
{
	int T; scanf("%d", &T);
	for(int ii = 0; ii < T; ii++)
	{
		int A, B, K; scanf("%d%d%d", &A, &B, &K);
		long long res = 0;
		for(int i = 0; i < A; i++)
			for(int j = 0; j < B; j++)
				if((i&j)<K) res++;
		printf("Case #%d: %lld\n", ii+1, res);
	}
	return 0;
}
