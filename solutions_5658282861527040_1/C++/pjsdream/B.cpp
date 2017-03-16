#include <stdio.h>
#include <memory.h>

long long a, b, k;

int as[64];
int bs[64];
int ks[64];

long long d[64];

long long sres[64][2][2][2];

long long solve (int d, int a, int b, int c)
{
	if (d==-1) return 1;
	if (sres[d][a][b][c]!=-1)
		return sres[d][a][b][c];

	long long res = 0;

	res += solve (d-1, a | as[d], b | bs[d], c | ks[d]);
	if (a || as[d]) res += solve (d-1, a, b | bs[d], c | ks[d]);
	if (b || bs[d]) res += solve (d-1, a | as[d], b, c | ks[d]);
	if ((c || ks[d]) && (a || as[d]) && (b || bs[d])) res += solve (d-1, a, b, c);
	return sres[d][a][b][c] = res;
}

int main()
{
	freopen ("input.txt", "r", stdin);
	freopen ("output.txt", "w", stdout);

	int t, tt=0;
	scanf ("%d", &t);
	while (t--) {
		printf ("Case #%d: ", ++tt);

		scanf ("%lld%lld%lld", &a, &b, &k);
		a--; b--; k--;

		long long ans = 0 ;
		for (int i=0; i<32; i++) {
			as[i] = (a>>i) & 1;
			bs[i] = (b>>i) & 1;
			ks[i] = (k>>i) & 1;
		}

		memset(sres, -1, sizeof(sres));
		printf ("%lld\n", solve (32, 0, 0, 0));
	}
	return 0;
}
