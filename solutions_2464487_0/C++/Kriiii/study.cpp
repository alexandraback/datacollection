#include <stdio.h>

double r,t;

bool good(long long v)
{
	double use = 2 * v * r + v + 2 * v * (v - 1);
	return use <= t;
}

int main()
{
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int T,Case=0;

	scanf ("%d",&T); while (T--){
		scanf ("%lf %lf",&r,&t);

		int l = 0, r = 1000000000, m;
		while (l < r){
			m = (l + r) / 2;
			if (good(m)) l = m + 1;
			else r = m - 1;
		}
		while (!good(m)) m--;
		while (good(m)) m++;
		m--;

		printf ("Case #%d: %d\n",++Case,m);
	}

	return 0;
}