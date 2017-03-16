#include <stdio.h>
#include <string.h>
#include <math.h>

using namespace std;

int B;
long long M;

int A[51][51];

inline void init()
{
	scanf("%d %lld", &B, &M);
	memset(A, 0, sizeof(A));
}

inline void solve()
{
	if (B == 2)
	{
		if (M == 1)
		{
			printf("POSSIBLE\n");
			printf("01\n00\n");
		}
		else
			printf("IMPOSSIBLE\n");
		return;
	}

	if (pow(2.0, B - 2) < M)
	{
		printf("IMPOSSIBLE\n");
		return;
	}

	printf("POSSIBLE\n");

	int i, j;

	for (i = B - 1; i > 1; i--)
		for (j = i + 1; j <= B; j++)
			A[i][j] = 1;

	int pos = B - 1;

	M--;

	while (M)
	{
		if (M % 2)
			A[1][pos] = 1;
		pos--;
		M /= 2;
	}

	A[1][B] = 1;

	for (i = 1; i <= B; i++)
	{
		for (j = 1; j <= B; j++)
			printf("%d", A[i][j]);
		puts("");
	}
}

int main()
{
	int i, T;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &T);

	for (i = 1; i <= T; i++)
	{
		printf("Case #%d: ", i);
		init();
		solve();
	}

	return 0;
}