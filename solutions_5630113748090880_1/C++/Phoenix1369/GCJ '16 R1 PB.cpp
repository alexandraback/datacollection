#include <cstdio>
#include <cstring>
#define MEM(x, y) memset((x), (y), sizeof(x))

const int MAXP = 3E3;
int count[MAXP]{ };
int M, N, P, T;

int main()
{
	scanf("%d", &T);
	for(int _T = 1; _T <= T; ++_T)
	{
		scanf("%d", &N);
		int M = N * (N << 1) - N;
		MEM(count, 0);
		while(M--)
		{
			scanf("%d", &P);
			++count[P];
		}
		printf("Case #%d:", _T);
		for(int i = 1; i <= 2500; ++i)
			if(count[i] & 1)
				printf(" %d", i);
		putchar('\n');
	}
	return 0;
}