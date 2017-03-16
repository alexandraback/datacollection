#include <iostream>
#include <fstream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <string>
#include <map>
#include <cstring>

using namespace std;

#define NextLine() { char c = getchar(); while (c != 10 && c != EOF) { c = getchar(); } }

int n, s, p;
int pts[110];

void Load()
{
	scanf("%d%d%d", &n, &s, &p);
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &pts[i]);
	}
}

int num[31][11][2];

void FillTriples()
{
	memset(num, 0, sizeof(num));
	int i, j, k;
	for (i = 0; i <= 10; i++)
	{
		for (j = 0; j <= 10; j++)
		{
			for (k = 0; k <= 10; k++)
			{
				int tmin, tmax;
				tmin = min(i, min(j, k));
				tmax = max(i, max(j, k));
				if (tmax - tmin > 2) continue;
				num[i + j + k][tmax][(tmax - tmin == 2) ? 1 : 0]++;
			}
		}
	}
}

int res[110][110];

int Count(int pos, int s)
{
	if (res[pos][s] != -1) return res[pos][s];
	if (pos >= n)
	{
		if (s == 0) res[pos][s] = 0;
		else res[pos][s] = -2;
		return res[pos][s];
	}
	res[pos][s] = -2;
	int i, j;
	for (j = 0; j <= 1; j++)
	{
		if (s == 0 && j == 1) continue;
		for (i = 0; i <= 10; i++)
		{
			if (num[pts[pos]][i][j] > 0)
			{
				int cres = Count(pos + 1, s - j);
				if (cres == -2) continue;
				if (i >= p) cres++;
				res[pos][s] = max(res[pos][s], cres);
			}
		}
	}
	return res[pos][s];
}

void Solve()
{
	memset(res, 0xFF, sizeof(res));
	cout << Count(0, s) << "\n";
}

int main()
{
	FillTriples();
	int nt;
	scanf("%d", &nt);
	NextLine();
	int it;
	for (it = 0; it < nt; it++)
	{
		Load();
		printf("Case #%d: ", it + 1);
		Solve();
	}
	return 0;
}