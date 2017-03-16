#include <cassert>
#include <cstring>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

const int N = 1024;

int n, m;
int f[N][N];
int h[N], v[N];

bool solve()
{
	for(int i = 0; i < n; i++)
		h[i] = 0;

	for(int i = 0; i < m; i++)
		v[i] = 0;

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
		{
			h[i] = max(h[i], f[i][j]);
			v[j] = max(v[j], f[i][j]);
		}

	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if(f[i][j] != min(h[i], v[j]))
				return false;

	return true;
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t = 0;
	scanf("%i\n", &t);

	for(int tn = 1; tn <= t; tn++)
	{
		scanf("%i %i\n", &n, &m);

		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				scanf("%i", &f[i][j]);

		printf("Case #%i: %s\n", tn, (solve() ? "YES" : "NO"));
	}

	return 0;
}
