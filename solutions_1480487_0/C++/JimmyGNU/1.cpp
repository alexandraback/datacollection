#include<cstdio>
#include<cstring>
#include<cmath>
int s[210];
double a[210];
bool v[210];
int main()
{
	int T;
	scanf ("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase)
	{
		int n;
		scanf ("%d", &n);
		int sum = 0;
		for (int i = 0; i < n; ++i)
		{
			scanf ("%d", &s[i]);
			a[i] = 0.0;
			sum += s[i];
		}
		for (int k = 0; k < sum; ++k)
		{
			double low = 1e9;
			for (int i = 0; i < n; ++i)
			{
				if (low > s[i] + a[i])
				{
					low = s[i] + a[i];
				}
			}
			//memset(v,0,sizeof(v));
			int cnt = 0;
			for (int i = 0; i < n; ++i)
			{
				if (fabs (s[i] + a[i] - low) < 1e-5)
				{
					v[i] = true;
					++cnt;
				}
			}
			for (int i = 0; i < n; ++i)
			{
				if (v[i])
				{
					a[i] += 1.0 / cnt;
					v[i] = false;
				}
			}
		}
		printf ("Case #%d:", nCase);
		for (int i = 0; i < n; ++i)
		{
			printf (" %f", 100.0 * a[i] / sum);
		}
		printf ("\n");
	}
	return 0;
}
