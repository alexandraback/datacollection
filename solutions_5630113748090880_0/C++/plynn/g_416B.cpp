#include <cstdio>
using namespace std;

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);
	int T, N;
	scanf("%d", &T);
	for (int i = 1; i <= T; ++i)
	{
		
		int table[2501] = { 0 };
		int n;
		scanf("%d", &N);
		for (int p = 0; p < 2 * N - 1; ++p) {
			for (int q = 1; q <= N; ++q)
			{
				scanf("%d", &n);
				table[n]++;
			}
		}

		printf("Case #%d:", i);
		for (int q = 1; q <= 2500; ++q)
			if(table[q]%2 != 0)
				printf(" %d", q);
		printf("\n");
	}
}