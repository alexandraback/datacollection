#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

int j[210], x, n;
bool vali (int c, double y)
{
	double sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += max((double)(j[c] - j[i]) / x + y, 0.0);
	}
	if (sum > 1 - 1e-12) return true;
	else return false;
}

int main ()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T; scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%d", &n); x = 0;
		for (int i = 0; i < n; i++) scanf("%d", &j[i]), x += j[i];
		printf("Case #%d:", t);
		for (int i = 0; i < n; i++)
		{
			if (vali(i, 0)) printf(" %.6f", 100);
			else
			{
				double st = 0, ed = 1;
				while (ed - st > 1e-11)
				{
					double mid = (st + ed) * 0.5;
					if (vali(i, mid)) ed = mid;
					else st = mid;
				}
				printf(" %.8f", ed * 100);
			}
		}
		printf("\n");
	}
	fclose(stdin), fclose(stdout);
	return 0;
}
