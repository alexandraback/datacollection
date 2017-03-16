#include <stdio.h>
#include <algorithm>

void solve()
{
	static int P[200], C[101];
	int n, s = 0;
	scanf("%d", &n);
	std::fill(C, C + 101, 0);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &P[i]);
		C[P[i]]++;
		s += P[i];
	}
	for (int i = 0; i < n; i++)
	{
		int j;
		int m = 0;
		int c = 0;
		for (j = 0; j <= P[i]; j++)
		{
			m += C[j] * (P[i] - j);
			c += C[j];
		}
		if (m >= s)
		{
			printf(" %.5f", 0.0);
			continue;
		}
		for (j = P[i]; m + c <= s; j++)
		{
			m += c;
			if (j < 100)
				c += C[j + 1];
		}
		printf(" %.5f", (double(s - m) / c + (j - P[i])) / s * 100);
	}
	putchar('\n');
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		printf("Case #%d:", i);
		solve();
	}
}