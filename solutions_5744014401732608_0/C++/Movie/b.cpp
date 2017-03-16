#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <string.h>
 
typedef long long ll;
 
using namespace std;
 
int cmp(const void *_a, const void *_b)
{
	int *a = (int *)_a;
	int *b = (int *)_b;

	return b[0] - a[0];
}

void p (ll x, ll B)
{
	if (B)
	{
		p (x >> 1, B - 1);
		printf ("%lld", x%2);
	}
}

int main(void)
{
	int T;

	scanf ("%d", &T);

	for (int t = 1; t <= T; t++)
	{
		ll B, M;

		bool pos = true;

		scanf ("%lld %lld", &B, &M);

		if (M >= (1LL << (B - 1)))
			pos = false;

		printf ("Case #%d: %sPOSSIBLE\n", t, pos ? "" : "IM");

		if (pos)
		{
			p (M, B); printf ("\n");

			ll x = (1LL << (B - 1)) - 1;

			while (x)
			{
				x >>= 1;
				p (x, B); printf ("\n");
			}
		}
	}
}