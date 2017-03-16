#include <stdio.h>

int n;
int x, y;
const int MAXX = 10000, MINX = -10000, MAXY = 10000;
bool d[MAXX - MINX + 1][MAXY + 1];

double dfs(int dep)
{
	if (dep == n) return d[x - MINX][y] ? 1 : 0;
	if (!d[0 - MINX][0]) {
		d[0 - MINX][0] = true;
		double ret = dfs(dep + 1);
		d[0 - MINX][0] = false;
		return ret;
	}
	int i = 0;
	while (d[0 - MINX][i]) i += 2;
	if (d[-1 - MINX][i - 1] && d[1 - MINX][i - 1]) {
		d[0 - MINX][i] = true;
		double ret = dfs(dep + 1);
		d[0 - MINX][i] = false;
		return ret;
	}
	double p = 0; int q = 0;
	if (!d[-1 - MINX][i - 1]) {
		int j = 0, k = i;
		while (k && !d[j - MINX][k]) --j, --k;
		if (d[j - MINX][k]) ++j, ++k;
		d[j - MINX][k] = true;
		p += dfs(dep + 1);
		++q;
		d[j - MINX][k] = false;
	}
	if (!d[1 - MINX][i - 1]) {
		int j = 0, k = i;
		while (k && !d[j - MINX][k]) ++j, --k;
		if (d[j - MINX][k]) --j, ++k;
		d[j - MINX][k] = true;
		p += dfs(dep + 1);
		++q;
		d[j - MINX][k] = false;
	}
	return p / q;
}

int main()
{
	int dat;
	scanf("%d", &dat);
	for (int k = 1; k <= dat; ++k) {
		scanf("%d%d%d", &n, &x, &y);
		printf("Case #%d: %lf\n", k, dfs(0));
	}
}
