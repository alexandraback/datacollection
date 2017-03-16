#include <bits/stdc++.h>
using namespace std;
#define long int64_t
#define mp make_pair
#define mt make_tuple

int n, x, y, n_test;

int main ()
{
	freopen("D.inp", "r", stdin);
	freopen("D.out", "w", stdout);

	scanf("%d", &n_test);
	for (int i = 1; i <= n_test; ++i)
	{
		scanf("%d%d%d", &n, &x, &y);
		printf("Case #%d: ", i);

		if (n == 1) puts("GABRIEL");
		else
		if (n == 2)
			if ((x * y) % 2 == 0) puts("GABRIEL");
			else
				puts("RICHARD");
		else
		if (n == 3)
			if ((x == 3 && y > 1) || (y == 3 && x > 1)) puts("GABRIEL");
			else
				puts("RICHARD");
		else
			if ((x == 4 && y > 2) || (x > 2 && y == 4)) puts("GABRIEL");
			else
				puts("RICHARD");
	}

	return 0;
}