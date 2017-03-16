#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <cassert>
#include <sstream>
#include <functional>
#include <algorithm>
#include <map>
#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int nt;
int m, n;
int keys[200];
int preset[200];
int postset[200][200];
int d[1 << 20];

int all;

int solve(int mask)
{
	if (mask == all) return 0;

	int &res = d[mask];

	if (res != -1) return res;

	res = -2;

	for(int i = 0; i < n; i++)
	{
		if (mask & (1 << i)) continue;

		int key = preset[i];
		int cnt = keys[key];

		for(int j = 0; j < n; j++)
		if (mask & (1 << j))
		{
			if (preset[j] == key) cnt--;
			cnt += postset[j][key];
		}

		// enabled
		if (cnt > 0)
		{
			if (solve(mask + (1 << i)) != -2) return res = i;
		}
	}

	return res;
}

void print(int mask)
{
	if (mask == all) return;
	int which = solve(mask);

	printf(" %d", which + 1);
	print(mask + (1 << which));
}

int main()
{
	int nt;
	scanf("%d", &nt);
	for(int tt = 1; tt <= nt; tt++)
	{
		fprintf(stderr, "test = %d\n", tt);
		printf("Case #%d:", tt);
		
		scanf("%d %d", &m, &n);
		all = 1 << n;
		all--;

		memset(keys, 0, sizeof keys);
		memset(postset, 0, sizeof postset);
		memset(d, -1, sizeof d);

		for(int i = 0; i < m; i++)
		{
			int x;
			scanf("%d", &x); x--;
			keys[x]++;
		}
		
		for(int i = 0; i < n; i++)
		{
			int x, y;
			scanf("%d %d", &x, &y);
			preset[i] = x - 1;
			for(int j = 0; j < y; j++)
			{
				int z;
				scanf("%d", &z);
				postset[i][z - 1]++;
			}
		}

		if (solve(0) != -2)
		{
			print(0); puts("");
		}
		else puts(" IMPOSSIBLE");
	}
	return 0;
}