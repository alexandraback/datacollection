#include <cstdio>

int te;

int main()
{
	scanf("%d", &te);
	for (int tn = 1; tn <= te; tn++)
	{
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		int mm = m;
		int cnt = 0;
		do
		{
			++cnt;
			mm -= k;
		}
		while (mm >= k);
		mm += k;
		int d = (mm != k);
		printf("Case #%d: %d\n", tn, cnt * (n - 1) + cnt - 1 + k + d);
	}

	return 0;
}