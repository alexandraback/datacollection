#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

#define MAXN 1001
#define eps 1e-12

int n;
int a[MAXN];
int s;
bool ok;
int b[MAXN];

inline void rec(int v, int s1, int s2, int s)
{
	if (ok) return;
	if (s1 > s2 + s) return;
	if (s2 > s1 + s) return;
	if (v == n)
	{
		if (s1 && s2 && s1 == s2)
			ok = 1;
		return;
	}
	b[v] = 0;
	rec(v + 1, s1, s2, s - a[v]);
	if (ok) return;
	b[v] = 0;
	b[v] = 1;
	rec(v + 1, s1 + a[v], s2, s - a[v]);
	if (ok) return;
	b[v] = 0;
	b[v] = 2;
	rec(v + 1, s1, s2 + a[v], s - a[v]);
	if (ok) return;
	b[v] = 0;
}

inline void solve(int cas)
{
	s = 0;
	ok = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		b[i] = 0;
		s += a[i];
	}
	rec(0, 0, 0, s);
	printf("Case #%d:\n", cas + 1);
	if (!ok)
	{
		printf("Impossible\n");
		return;
	}
	for (int i = 0, j = 0; i < n; ++i)
		if (b[i] == 1)
		{
			if (j) printf(" ");
			printf("%d", a[i]);
			++j;
		}
	printf("\n");
	for (int i = 0, j = 0; i < n; ++i)
		if (b[i] == 2)
		{
			if (j) printf(" ");
			printf("%d", a[i]);
			++j;
		}
	printf("\n");
}

int main()
{
	int tt;
   scanf("%d", &tt);
	for (int t = 0; t < tt; ++t)
	{
		solve(t);
	}
	return 0;
}
