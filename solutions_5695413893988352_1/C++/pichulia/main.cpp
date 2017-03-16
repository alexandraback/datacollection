#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
using namespace std;

char x[9999];
char y[9999];

long long int rd;
bool rf;
bool flip;
char rx[9999];
char ry[9999];
char w[9999];
char z[9999];
long long int diff;
bool res;
int n;
void dfs_big(int dep, bool is_same)
{
	if (dep == n)
	{

		long long int diff = 0;
		int i;
		for (i = 0; i < n; i++)
		{
			diff *= 10;
			diff += (z[i] - w[i]);
		}
//		printf("%lld %s %s\n", diff, z, w);
		if (rd == 0 || rd > diff)
		{
			rf = flip;
			for (i = 0; i < n; i++)
			{
				rx[i] = z[i];
				ry[i] = w[i];
			}
			rd = diff;
		}
		else if (rd == diff)
		{
			for (i = 0; i < n; i++)
			{
				if (rx[i] > z[i])
					break;
				if (rx[i] < z[i]) {
					i = n+9; break;
				}
			}
			if (i < n)
			{
				rf = flip;
				for (i = 0; i < n; i++)
				{
					rx[i] = z[i];
					ry[i] = w[i];
				}
			}
			else if (i == n)
			{
				for (i = 0; i < n; i++)
				{
					if (ry[i] > w[i])
						break;
					if (ry[i] < w[i]) {
						i = n + 9; break;
					}
				}
				if (i < n)
				{
					rf = flip;
					for (i = 0; i < n; i++)
					{
						rx[i] = z[i];
						ry[i] = w[i];
					}
				}
			}
		}
	}
	else
	{
		if (x[dep] == '?')
		{
			if (y[dep] == '?')
			{
				if (is_same)
					w[dep] = '0';
				else
					w[dep] = '9';
			}
			else
				w[dep] = y[dep];
			//
			if (is_same)
			{
				z[dep] = w[dep];
				dfs_big(dep + 1, is_same);
				z[dep] = w[dep] + 1;
				if (z[dep] < '9')
					dfs_big(dep + 1, false);
			}
			else
			{
				z[dep] = '0';
				dfs_big(dep + 1, false);
			}
		}
		else
		{
			z[dep] = x[dep];
			if (y[dep] == '?')
			{
				if (is_same)
				{
					w[dep] = x[dep];
					dfs_big(dep + 1, is_same);
					w[dep] = x[dep] - 1;
					if (w[dep] >= '0')
						dfs_big(dep + 1, false);
				}
				else
				{
					w[dep] = '9';
					dfs_big(dep + 1, false);
				}
			}
			else
			{
				w[dep] = y[dep];
				if (is_same && z[dep] < w[dep]) return;
				dfs_big(dep + 1, is_same && (z[dep] == w[dep]));
			}
		}
	}
}
int main()
{
//	freopen("B-small-attempt0.in", "rt",stdin);
//	freopen("B-small-attempt0.out", "wt",stdout);
	freopen("B-large.in", "rt", stdin);
	freopen("B-large.out", "wt", stdout);

	int t;
	int tv;
	tv = 1;
	scanf("%d", &t);
	while (t--)
	{
		int i, j, k;
		scanf("%s %s", x, y);
		for (n = 0; x[n]; n++);
		res = false;
		for (i = 0; i < n; i++)
		{
			rx[i] = x[i];
			ry[i] = y[i];
			z[i] = x[i];
			w[i] = y[i];
		}
		rx[n] = ry[n] = z[n] = w[n] = 0;
		//same
		rf = false;
		if (!res)
		{
			for (i = 0; i < n; i++)
			{
				if (x[i] != '?' && y[i] != '?' && x[i] != y[i])
					break;
			}
			if (i == n)
			{
				res = true;
				for (i = 0; i < n; i++)
				{
					if (x[i] == '?')
					{
						if (y[i] == '?')
						{
							ry[i] = '0';
						}
						else
						{
							ry[i] = y[i];
						}
						rx[i] = ry[i];

					}
					else
					{
						rx[i] = x[i];
						ry[i] = rx[i];
					}
				}
			}
		}
		rd = 5000000000000000000LL;

		// x > y
		if (!res)
		{
			flip = false;
			dfs_big(0, true);
		}
		// y > x
		if (!res)
		{
			flip = true;
			for (i = 0; i < n; i++)
			{
				z[i] = x[i];
				x[i] = y[i];
				y[i] = z[i];
			}
			dfs_big(0, true);

		}

		printf("Case #%d: ", tv);
		{
			if(rf)
				printf("%s %s", ry, rx);
			else
				printf("%s %s", rx, ry);
		}
		printf("\n");
		tv++;
	}
}