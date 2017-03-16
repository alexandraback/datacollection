#include <bits/stdc++.h>
using namespace std;
int t, n, n1, n2, f[10] = {0}, cnt = 0;
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++)
	{
		scanf("%d", &n);
		printf("Case #%d: ", tt);
		n1 = 0;
		cnt = 0;
		for (int i = 1; i <= 100; i++)
		{
			n1 += n;
			n2 = n1;
			while (n2)
			{
				if (f[n2 % 10] != tt) f[n2 % 10] = tt, cnt++;
				n2 /= 10;
			}
			if (cnt == 10) break;
		}
		if (cnt == 10) printf("%d\n", n1);
		else puts("INSOMNIA");
	}
	return 0;
}