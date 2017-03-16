#include <iostream>
#include <cstdio>
using namespace std;
#define MAXSP 10000000
#define MAXL 14
long long sp[MAXSP] = {0};
int spN = 0;
int p[MAXL] = {0};
int p2[MAXL] = {0};
void fill(int d, int l)
{
	if (d == ((l+1) >> 1))
	{
		long long pn = 0;
		int base = 1;
		for (int i = 0; i < d; i++)
		{
			pn += p[i] * base;
			base *= 10;
		}
		for (int i = d-1; i >= 0; i--)
		{
			if (l-1-i == i)
				continue;
			pn += p[i] * base;
			base *= 10;
		}
		long long pn2 = pn * pn;
		// printf("l=%d P=%lld P2=%lld\n", l, pn, pn2);
		// cout << "P: " << pn << " P2: " << pn2 << endl;
		int l2 = 0;
		long long pn2_ = pn2;
		for (l2 = 0; pn2_ > 0; l2++)
		{
			p2[l2] = pn2_ % 10;
			pn2_ /= 10;
		}
		bool ok = true;
		for (int i = 0; i < (l2 >> 1) && ok; i++)
			ok = (p2[i] == p2[l2-1-i]);
		if (ok)
		{
			sp[spN++] = pn2;
			// printf("OK!\n");
		}
	}
	else
	{
		if (d > 0)
		{
			p[d] = 0;
			fill(d+1, l);
		}
		for (p[d] = 1; p[d] <= 9; p[d]++)
			fill(d+1, l);
	}
}
// long long spf[] = {1, 2, 3, 4, 5};
int biSearch(long long x)
{
	int l = 0, r = spN;
	while (l < r)
	{
		int m = (l + r) >> 1;
		if (sp[m] < x)
			l = m + 1;
		else
			r = m;
	}
	return l;
}
int main()
{
	for (int l = 1; l <= ((MAXL+1) >> 1); l++)
		fill(0, l);
/*
	for (int i = 0; i < spN; i++)
		clog << sp[i] << endl;
*/
	// clog << biSearch(0) << biSearch(1) << biSearch(2) << biSearch(3) << biSearch(4) << biSearch(5) << biSearch(6) << endl;
	int T = 0;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		long long A, B;
		scanf("%lld %lld", &A, &B);
		int pA = biSearch(A);
		int pB = biSearch(B+1);
		printf("Case #%d: %d\n", t+1, pB-pA);
	}
	return 0;
}

