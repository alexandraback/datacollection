#include <cstdio>

const int N = 1010;

int tn, t, n, i;
char s[N];

int main()
{
	scanf("%d", &tn);

	for (t = 1; t <= tn; t++)
	{
		int m = 0, k = 0;
		scanf("%d%s", &n, s);
		for (i = 0; i < n; i++)
		{
			k += s[i] - 48;
			if (k < i + 1)
			{
				m += i + 1 - k;
				k = i + 1;
			}
		}
		printf("Case #%d: %d\n", t, m);
	}

	return 0;
}