#include <stdio.h>
#include <algorithm>
#include <utility>
#include <vector>
#include <string.h>
using namespace std;

int main()
{
	long long int A[2501], T, i, c = 0, num, j, N;

	scanf("%lld", &T);

	while(T--)
	{
		c++;
		scanf("%lld", &N);
		for(i = 0; i < 2501; i++)
		{
			A[i] = 0;
		}

		for(i = 1; i <= 2 * N - 1; i++)
		{
			for(j = 0; j < N; j++)
			{
				scanf("%lld", &num);
				A[num]++;
			}
		}
		printf("Case #%lld: ", c);
		for(i = 1; i <= 2500; i++)
		{
			if(A[i] % 2 != 0)
			{
				printf("%lld ", i);
			}
		}
		printf("\n");
	}
	return 0;
}