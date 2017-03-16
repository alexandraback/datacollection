#include <stdio.h>
#include <algorithm>
#include <assert.h>

void solve()
{
	static char T[2000001];
	static int S[20];
	const int n = 20;
	scanf("%d", &S[0]);
	assert(S[0] == n);
	std::fill(T, T + sizeof(T), 0);
	for (int i = 0; i < n; i++)
		scanf("%d", &S[i]);
	for (unsigned m = 1; m != 1 << n; m++)
	{
		int s = 0;
		for (int i = 0; i < n; i++)
			if (m & (1 << i))
				s += S[i];
		T[s] = (T[s] << 1) | 1;
	}
	putchar('\n');
	int x = -1;
	for (unsigned m = 1; m != 1 << n; m++)
	{
		int s = 0;
		for (int i = 0; i < n; i++)
			if (m & (1 << i))
				s += S[i];
		if (s == x || (x == -1 && (T[s] & 2)))
		{
			bool first = true;
			for (int i = 0; i < n; i++)
				if (m & (1 << i))
				{
					if (first)
						first = false;
					else
						putchar(' ');
					printf("%d", S[i]);
				}
			putchar('\n');
			if (x != -1)
				break;
			x = s;
		}
	}
	if (x == -1)
		puts("Impossible");
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d: ", i);
		solve();
	}
}