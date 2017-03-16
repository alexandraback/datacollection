#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 100010;
double p[MAXN];
double dd[MAXN];

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("1.out", "w", stdout);

	int a, b;

	int csnum, cs;
	double m1, m2, m3;
	double d0, d1;

	scanf ("%d", &csnum);
	for (cs = 1; cs <= csnum; cs++)
	{
		scanf ("%d %d", &a, &b);
		
		for (int i = 1; i <= a; i++)
			scanf ("%lf", &p[i]);
		
		p[0] = 1.0;
		dd[0] = 1.0;
		for (int i = 1; i <= a; i++)
			dd[i] = p[i] * dd[i - 1];

		d0 = 1;
		double mx = 1000000;
		
		for (int i = 1; i <= a; i++)
		{
			m2 = 0;
			double t = 0;
			for (int j = 1; j <= a - i; j++)
			{
				t += dd[j - 1] * (1.0 - p[j]);
			}
			m2 += t * (double)(2 * i + b - a + 1 + b + 1);
			
			t = 0;
			for (int j = a - i + 1; j <= a; j++)
			{
				t += dd[j - 1] * (1.0 - p[j]);
			}
			t += dd[a];
			m2 += t * (double)(2 * i + b - a + 1);
			if (m2 < mx) mx = m2;
		}
		
		d0 = dd[a];
		m3 = b + 2;
		m1 = d0 * (b - a + 1.0) + (1.0 - d0) * (2.0 * b + 2.0 - a);

		if (m3 < mx)
		   mx = m3;
	    if (m1 < mx)
		   mx = m1;
	   //	printf ("m1=%.6lf m2=%.6lf m3=%.6lf\n", m1, m2, m3);

		printf ("Case #%d: %.6lf\n", cs, mx);
	}

	return 0;	

}
