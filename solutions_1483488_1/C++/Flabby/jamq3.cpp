#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

const int MAXN = 2000010;
int a, b;
map<pair<int,int>, int> mp;
int flg[MAXN];
int ans[MAXN];

int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("1.out", "w", stdout);

	int csnum;
	int cs;

	scanf ("%d", &csnum);
	for (cs = 1; cs <= csnum; cs++)
	{
		scanf ("%d %d", &a, &b);

		int ret = 0;
	//	mp.clear();
		memset(flg, 0, sizeof(flg));

		for (int i = a; i < b; i++)
		{
			int k = i;
			int t, x;
			int cnt = 0;
			for (x = 1; x <= k; x *= 10)
				cnt++;

		//	printf ("cnt=%d\n", cnt);

			for (int d = 10; d <= k; d *= 10)
			{
				x /= 10;
				t = k / d + (k % d) * x;	
				if (t <= b && t > k && flg[t] != k)
				{
					ret++;
					flg[t] = k;
		//			if (mp.find(make_pair(k, t)) != mp.end())
		//				printf ("(%d, %d)----> %d\n", k, t, mp[make_pair(k, t)]);
		//			else
		//				mp[make_pair(k, t)] = ret;
				}
			}
		}

		printf ("Case #%d: %d\n", cs, ret);
	}

	return 0;
}
