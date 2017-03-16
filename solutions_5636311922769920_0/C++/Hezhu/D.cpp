#include <cstdio>

int main()
{
	int T;
	scanf("%d", &T);
	for (int kase = 1; kase <= T; ++kase)
	{
		int K, C, S;
		scanf("%d %d %d", &K, &C, &S);
		printf("Case #%d:", kase);
		for (int i = 1; i <= S; ++i)
			printf(" %d", i);
		puts("");
	}
	return 0;
}
