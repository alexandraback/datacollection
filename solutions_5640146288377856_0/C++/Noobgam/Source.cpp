#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <set>
#include <cstdio>
#include <queue>
#include <map>
#include <cmath>
using namespace std;

int main()
{
	int t;
	::ios_base::sync_with_stdio(false);
	cin.tie(false);
	freopen("inp.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int r, c, w;
	cin >> t;
	for (int i = 1; i <= t; i++)
	{
		cin >> r >> c >> w;
		if (w == 1 || w == c)
		{
			printf("CASE #%d: %d\n", i, c);
			continue;
		}
		int cur = 0;
		int result = 0;
		for (int q = 1; q <= c - w; q++)
		{
			int last = 0;
			int cnt = 0;
			int cur = 0;
			bool got = false;
			bool gor = false;
			while (cnt < w)
			{
				if (!got)
					cur++, last = last + w;
				if (last >= q && last <= q + w)
				{
					got = true;
					if (q == last - w - 1)
						result = max(result, cur + w - 1);
					else
						result = max(result, cur + w);
					break;
				}
			}
		}
		printf("CASE #%d: %d\n", i, result);
	}
	return 0;
}	