#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <unordered_map>
#include <map>
#include <cassert>
#include <vector>
#include <set>
#include <ctime>
#pragma comment (linker, "/STACK:1000000000")

int main()
{
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int cnt1 = 1;
	int t;
	scanf("%d\n", &t);
	while (t--)
	{
		char c[1002];
		int q;
		scanf("%d ", &q);
		scanf("%s\n", &c);
		int cnt[1001];
		for (int i = 0; i <= q; i++)
			cnt[i] = c[i] - '0';
		int cur = 0;
		int add = 0;
		for (int i = 0; i <= q; i++)
		{
			if (cnt[i] > 0)
			{
				if (i > add + cur)
					add += (i - cur - add);
				cur += cnt[i];
			}				
		}
		printf("Case #%d: %d\n", cnt1, add);
		cnt1++;
	}
	return 0;
}