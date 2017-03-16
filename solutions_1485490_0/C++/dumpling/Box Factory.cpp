#include <iostream>
using namespace std;

typedef unsigned long long uint64;

int T, n, m;
int a[128], b[128];
uint64 ca[128], cb[128];
uint64 f[128][128];

void Init(int n, int m)
{
	for(int i = n; i >= 1; --i)
		scanf("%llu%d", &ca[i], &a[i]);
	for(int i = m;i >= 1; --i)
		scanf("%lllu%d", &cb[i], &b[i]);
}

uint64 max2(uint64 a1, uint64 a2)
{
	return a1 > a2 ? a1 : a2;
}

uint64 DP(int i, int j, uint64 ci, uint64 cj)
{
	if(i > n || j > m)
		return 0;
	if(a[i] == b[j])
	{
		if(ci < cj)
			f[i][j] = max2(f[i][j], DP(i + 1, j, ca[i + 1], cj - ci) + ci);
		else if(ci == cj)
			f[i][j] = max2(f[i][j], DP(i + 1, j + 1, ca[i + 1], cb[j + 1]) + ci);
		else
			f[i][j] = max2(f[i][j], DP(i, j + 1, ci - cj, cb[j + 1]) + cj);
	}
	else
		f[i][j] = max2(f[i][j], max2(DP(i + 1, j, ca[i + 1], cj), DP(i, j + 1, ci, cb[j + 1])));
	return f[i][j];
}

int main()
{
	freopen("C-small-attempt9.in", "r", stdin);
	freopen("C-small-attempt9.out", "w", stdout);
	scanf("%d", &T);
	for(int t = 1; t <= T; ++t)
	{
		memset(f, 0, sizeof(f));
		scanf("%d%d",&n, &m);
		Init(n, m);
		uint64 value = DP(1, 1, ca[1], cb[1]);
		printf("Case #%d: %llu\n", t, value);
	}
	return 0;
}