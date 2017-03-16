#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
int a[1010], s[1010], T, x, y, z, n, mm, k, ans, w, tmp;
int main()
{
	a[0] = 1;
	for (int i = 1; i <= 1000; i++) a[i] = 4 * i;
	s[0] = a[0];
	for (int i = 1; i <= 1000; i++) s[i] = s[i - 1] + a[i];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d%d", &n, &mm, &k);
		ans = 2 * (n + mm) - 4;
		x = y = tmp = 0;
		if (n > mm) swap(n, mm);
		if (k <= mm) ans = min(ans, k);
		for (int m = n; m <= mm; m++)
		{
			tmp = n >> 1;
			x = tmp * (tmp + 1) * 2;
			y = 0;
			z = (2 * (n + m) - 8 * tmp + 4 * (tmp - 1));
			if ((n & 1) == 0)
			{
				y = 2;
				x = tmp * tmp * 2;
				z += 2;
			}
			//printf("%d %d %d %d\n", tmp, x, y, z);
			while (x + k > n * m)
			{
				x -= tmp;
				z++;
				if (y == 3) y = 0, tmp--;
				else y++;
			}
			if (z < ans) ans = z;
			for (int i = 0; i <= 1000; i++)
			{
				x = i * 2 + 1;
				if (x > n) break;
				if (k <= s[i])
				{
					if (ans > a[i]) ans = a[i];
					break;
				}
				tmp = (k - s[i]) / x;
				if ((k - s[i]) % x) tmp++;
				y = tmp;
				if (y + x > m) continue;
				if (y * 2 + a[i] < ans) ans = y * 2 + a[i];
			}
		}
		if (k == 1) ans = 1;
		printf("Case #%d: %d\n", ++w, ans);
	}
	return 0;
}