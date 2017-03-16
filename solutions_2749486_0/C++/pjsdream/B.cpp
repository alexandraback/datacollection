#include <stdio.h>

long long x, y;

bool in_diamond (long long s, long long x, long long y)
{
	if (x+y >= s/2 && x+y <= s + s/2 && 
		y-x <= s/2 && y-x >= -s/2 &&
		((s/2)&1) == ((x+y)&1))
		return true;
	return false;
}

char ans[1000010];

int main()
{
	freopen ("b.in", "r", stdin);
	freopen ("b.out", "w", stdout);

	int t, tt=0;
	scanf ("%d", &t);
	while (t--) {
		scanf ("%lld%lld", &x, &y);

		long long s = 0;

		int n;
		for (n=1; ; n++) {
			s += n * 2;
			x += n;
			y += n;

			if (in_diamond(s, x, y))
				break;
		}

		ans[n] = 0;
		while (n>0) {
			s -= n*2;
			if (in_diamond(s, x, y-n)) y -= n, ans[n-1] = 'W';
			else if (in_diamond(s, x-2*n, y-n)) y -= n, x -= 2*n, ans[n-1] = 'E';
			else if (in_diamond(s, x-n, y)) x -= n, ans[n-1] = 'S';
			else if (in_diamond(s, x-n, y-2*n)) x -= n, y -= 2*n, ans[n-1] = 'N';

			n--;
		}

		printf ("Case #%d: ", ++tt);
		printf ("%s\n", ans);
	}

	return 0;
}
