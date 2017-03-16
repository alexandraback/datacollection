#include <stdio.h>
#include <stdlib.h>

int main()
{
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
	int it, i, t, n, a[10], tt;
	scanf ("%d", &t);
	int MXC = 2000000;
 
	for (it = 0; it< t; ++it) {
		scanf ("%d", &n);
		long long res = n;
		tt = 1;
		for (i = 0; i < 10; ++i)
			a[i] = 0;
		int seen = 0;
		do {
			res = n * 1ll * tt;
			while (res) {
				int c = res % 10;
				res /= 10;
				if (!a[c]) {
					a[c]++;
					seen++;
				}
			}
		} while (seen < 10 && tt++ < MXC);

		if (tt < MXC)
			printf ("Case #%d: %lld\n", it + 1, n * 1ll * tt);
		else
			printf ("Case #%d: INSOMNIA\n", it + 1);
	}
}
