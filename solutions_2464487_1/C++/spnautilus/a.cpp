#include <stdio.h>

typedef long long ll;

int TT;
ll R, T;

int main()
{
	int tt;
	scanf("%d", &TT);
	for(tt = 1; tt <= TT; ++tt)
	{
		scanf("%I64d %I64d", &R, &T);

		ll res = 1;
		ll l = 2;
		ll h = T;

		while(l <= h)
		{
			ll m = (l + h) >> 1;
			ll t1 = T / m;
			ll a = 2 * R + 2 * m - 1;

			if(a <= t1)
			{
				res = m;
				l = m + 1;
			}
			else
				h = m - 1;
		}

		printf("Case #%d: %I64d\n", tt, res);
	}

	return 0;
}
