#include <cstdio>
#include <cstring>

#define MAX_HEIGHT 2500

int count[MAX_HEIGHT+5];

int main()
{
	int T;
	int N;
	scanf("%d\n", &T);

	for (int i=0; i<T; ++i)
	{
		scanf("%d", &N);
		printf("Case #%d:", i+1);
		memset(count, 0, sizeof(count));
		for (int i=0; i < 2*N - 1; ++i)
		{
			for (int j=0; j < N; ++j)
			{
				int h;
				scanf("%d", &h);
				++count[h];
			}
		}
		for (int i=1; i <= MAX_HEIGHT; ++i)
			if (count[i]&1)
				printf(" %d", i);
		printf("\n");
	}
	return 0;
}
