#include <bits/stdc++.h>
using namespace std;
int t, n, j;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		scanf("%d%d", &n, &j);
		n >>= 1;
		n -= 3;
		printf("Case #%d:\n", tt);
		for (int i = 1; i <= j; i++)
		{
			putchar('1'), putchar('1');
			for (int k = n; k >= 0; k--) putchar('0' + ((i >> k) & 1)), putchar('0' + ((i >> k) & 1));
			putchar('1'), putchar('1'), putchar(' ');
			for (int k = 2; k <= 10; k++) printf("%d ", k + 1);
			puts("");
		}
	}
	return 0;
}