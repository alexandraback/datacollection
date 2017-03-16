#include <stdio.h>

int T, n;
int v[20];
int sol[100000 * 21];

void work()
{
	static int ttt = 0;
	printf("Case #%d:\n", ++ttt);
	scanf("%d", &n);
	for (int i = 0; i < 100000 * 21; ++i) sol[i] = -1;
	for (int i = 0; i < n; ++i) scanf("%d", &v[i]);
	for (int msk = 0; msk < (1 << n); ++msk) {
		int cur = 0;
		for (int i = 0; i < n; ++i) if (msk & (1 << i))
			cur += v[i];
		if (sol[cur] != -1) {
			for (int i = 0; i < n; ++i) if (msk & (1 << i)) printf("%d ", v[i]);
			printf("\n");
			for (int i = 0; i < n; ++i) if (sol[cur] & (1 << i)) printf("%d ", v[i]);
			printf("\n");
			return;
		}
		sol[cur] = msk;
	}
	printf("Impossible\n");
}

int main()
{
	scanf("%d", &T);
	while (T--) work();
}
	