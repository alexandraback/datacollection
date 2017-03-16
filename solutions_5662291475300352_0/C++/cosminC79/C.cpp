#include <cstdio>
#include <algorithm>
#define pii pair <int, int>
#define pdd pair <double, double>
#define mp make_pair
#define x first
#define y second
#define NMAX 51
#define eps 1e-8
using namespace std;
int tests, n, r;
pdd A[NMAX];

int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	
	scanf("%d", &tests);
	for (int test_no = 1; test_no <= tests; test_no++)
	{
		printf("Case #%d: ", test_no);
		
		scanf("%d", &n);
		double di, hi, mi;
		r = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%lf%lf%lf", &di, &hi, &mi);
			for (int j = 1; j <= hi; j++)
				A[++r] = mp(di, (double)360 / (mi + j - 1));
		}
		
		if (r == 1)
			printf("0\n");
		else
		{
			sort(A + 1, A + r + 1);
			double d1 = A[1].x, w1 = A[1].y, d2 = A[2].x, w2 = A[2].y;
			
			if (abs(w1 - w2) < eps)
			{
				printf("0\n");
			}
			else
			{
				if (w1 < w2) // 2nd is faster than 1st
				{
					double rem = ((double)360.0 - d1) / w1;
					double inters = ((double)360.0 - d2 + d1) / (w2 - w1);
					if (inters < rem + eps)
					{
						printf("1\n");
					}
					else
					{
						printf("0\n");
					}
				}
				else
				{
					//~ printf("2nd case\n");
					double rem = ((double)360.0 - d2) / w2;
					double inters = (double)(d2 - d1 + 360.0) /  (w1 - w2);
					//~ printf("%lf %lf\n", rem, inters);
					if (inters < rem + eps)
					{
						printf("1\n");
					}
					else
					{
						printf("0\n");
					}
				}
			}
		}
	}
	return 0;
}
