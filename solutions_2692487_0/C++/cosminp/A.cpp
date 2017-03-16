#include <cstdio>
#include <fstream>
#include <cmath>

using namespace std;

#define MAX_SIZE	101
#define MAX_VALUE	101
#define MAX_BOUND	102

long		a[MAX_SIZE];
long		best[MAX_BOUND];
long		n;
long		armin_mote;


int cmp_less (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}


int solve()
{	
	qsort(a, n, sizeof(long), cmp_less);

	for (int i = 1; i <= MAX_VALUE; i++)
	{
		best[i] = (i > a[n-1]) ? 0 : 1;
	}

	if (n == 1) return best[armin_mote];

	for (int i = n - 2; i >= 0; i--)
	{
		for (int mote = 1; mote <= MAX_VALUE; mote++)
		{
			if (mote > a[i])
			{
				best[mote] = best[ min(mote + a[i], (long)MAX_VALUE) ];
			}
			else
			{
				int best_remove = 1 + best[mote];
				int best_add = 0;
				int new_mote = mote;
				
				if (new_mote == 1)
				{
					best[new_mote] = best_remove;
					continue;
				}

				while (new_mote <= a[i])
				{
					new_mote = 2*new_mote - 1;
					best_add++;
				}

				best_add += best[ min(new_mote + a[i], (long)MAX_VALUE) ];

				best[mote] = min(best_add, best_remove);
			}
		}
	}

	return best[armin_mote];
}


int main()
{
	fstream			f, g;
	int				T;

	f.open("in.txt",  ios :: in);
	g.open("out.txt", ios :: out);

	f >> T;
	for (int test = 1; test <= T; test++)
	{
		f >> armin_mote >> n;

		for (int i = 0; i < n; i++)
		{
			f >> a[i];
		}

		g << "Case #" << test << ": " << solve() << endl;
	}

	f.close();
	g.close();

	return 0;
}