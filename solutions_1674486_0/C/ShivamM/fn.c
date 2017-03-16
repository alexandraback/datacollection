#include <stdio.h>
int a[100][100];
int c[100];
int n;
void fn (int i)
{
	int j;
	c[i]++;
	for (j = 0; j < n; j++) {
		if (a[i][j] == 1) {
			fn (j);
		}
	}
}

int main()
{
	int i;
	int j;
//	int n;
	int m;
	int k;
	int t;
	int p;
	int f;
	int b[100];

	scanf ("%d", &t);

	p = 1;

	while (p <= t) {

	scanf ("%d", &n);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			a[i][j] = 0;
		}
	}

	for (i = 0; i < n; i++) {
		scanf ("%d", &m);

		for (j = 0; j < m; j++) {
			scanf ("%d", &k);
			k = k - 1;

			a[i][k] = 1;
		}
	}

	for (i = 0; i < n; i++) {
		b[i] = 0;
	}

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (a[i][j] == 1) {
				b[j]++;
			}
		}
	}
	f = 0;

	printf ("Case #%d: ", p);
	for (i = 0; i < n && f == 0; i++) {
		if (b[i] == 0) {

			for (j = 0; j < n; j++) {
				c[j] = 0;
			}

			fn (i);

			for (j = 0; j < n; j++) {
				if (c[j] > 1) {
					printf ("Yes\n");
					f = 1;
					break;
				}
			}
		}
	}

	if (f == 0) {
		printf ("No\n");
	}
	p++;
	}

	return 0;
}
