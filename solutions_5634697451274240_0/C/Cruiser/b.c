#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
	int it, i, t, n, tt;
	scanf ("%d", &t);
	int MXC = 2000000;
 
	for (it = 0; it < t; ++it) {
		char a[123];
		tt = 0;
		scanf ("%s", a);
		n = strlen (a);
		a[n] = '+';
		for (i = 0; i < n; ++i)
			if (a[i] != a[i + 1])
				++tt;

		printf ("Case #%d: %d\n", it + 1, tt);
	}
}
