#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 200;
const double eps = 1e-9;

int n;
int score[N];

void solve()
{
	int sum = 0;
	for (int i = 0; i < n; i++) sum += score[i];

	for (int i = 0; i < n; i++)
	{
		double l = 0, r = 1.0;
		while (r - l > 1e-9)
		{
			double m = (l + r) * 0.5;
			double sigma = 0;
			bool has = false;
			for (int j = 0; j < n; j++)
			{
				if (i == j) continue;
				double lower = (double)(score[i] - score[j]) / sum + m;
				if (lower > -eps)
				{
					has = true;
					sigma += max(0.0, lower);
				}
			}
			if (!has || sigma < 1.0 - m - eps)
			{
				// Y0 not acceptable
				l = m;
			}
			else
			{
				r = m;
			}
		}
		printf(" %.7lf", r * 100);
	}
	printf("\n");
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		printf("Case #%d:", t + 1);
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d", score + i);
		}
		solve();
	}
}