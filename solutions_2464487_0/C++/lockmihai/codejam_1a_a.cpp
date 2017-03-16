#include <stdio.h>

#include <math.h>

const double pi = 3.1415926535897932384626433832795;

int main ()
{
	freopen ("input.in", "r", stdin);
	freopen ("output.out", "w", stdout);
	
	int tt;
	scanf ("%d", &tt);
	long long rinit, suma;
	for (int t = 1; t <= tt; t ++)
	{
		printf ("Case #%d: ", t);
		scanf ("%lld %lld", &rinit, &suma);
		
		long long st = 1, dr = 1000000000, m, sol = 1, s;
		
		if (1000000000ll * 3000000000ll / rinit < dr)
			dr = 1000000000ll * 3000000000ll / rinit;
		while (st <= dr)
		{
			m = (st + dr) >> 1;
			s = 2 * m * rinit + m + 2 * (m - 1) * m;
			if (s <= suma)
			{
				st = m + 1;
				sol = m;
			}
			else
				dr = m - 1;
		}
		printf ("%lld\n", sol);
	}
	return 0;
}
