#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef long double ldouble;

int n, k, ks[220], os[220], col[220], sz[220], all[220][220];
bitset<(1 << 20)> bad;
bool used[220];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);

	int ts; scanf("%d", &ts);
	for (int tst = 0; tst < ts; tst++)
	{
		scanf("%d%d", &k, &n);
		fill(ks, ks + 200, 0);
		for (int i = 0; i < k; i++)
		{
			int x; scanf("%d", &x); ks[x - 1]++;
		}
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d", &col[i], &sz[i]), col[i]--;
			for (int j = 0; j < sz[i]; j++)
				scanf("%d", &all[i][j]), all[i][j]--;
		}
		for (int i = 0; i < (1 << n); i++)
		{
			bad[i] = false;
			for (int j = 0; j < 200; j++)
				os[j] = ks[j];
			for (int j = 0; j < n; j++)
				if (!((i >> j) & 1))
				{
					os[col[j]]--;
					for (int ii = 0; ii < sz[j]; ii++)
						os[all[j][ii]]++;
				}
			for (int j = 0; j < 200; j++)
				if (os[j] < 0) bad[i] = true;
			int bd = 0;
			for (int j = 0; j < n; j++)
				if ((i >> j) & 1)
				{
					if (os[col[j]] == 0) bd++;
					else bd += bad[i ^ (1 << j)];
				}
				else bd++;
			bad[i] = bad[i] | (bd == n && i != 0);
		}
		printf("Case #%d:", tst + 1);
		if (bad[(1 << n) - 1]) { printf(" IMPOSSIBLE\n"); continue; }
		fill(used, used + n, false);
		int msk = (1 << n) - 1;
		for (int i = 0; i < 200; i++)
			os[i] = ks[i];
		for (int i = 0; i < n; i++)
		{
			int cur = 0;
			while (true)
			{
				if (used[cur] || bad[msk ^ (1 << cur)]) { cur++; continue; }
				if (os[col[cur]] == 0) { cur++; continue; }
				break;
			}
			os[col[cur]]--;
			for (int ii = 0; ii < sz[cur]; ii++)
				os[all[cur][ii]]++;
			printf(" %d", cur + 1); used[cur] = true; msk ^= (1 << cur);
		}
		printf("\n");
	}
	
	return 0;
}