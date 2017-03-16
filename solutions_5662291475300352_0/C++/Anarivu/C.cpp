#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<set>
#include<map>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<iostream>
#include<unordered_map>
using namespace std;

long long nod(long long a, long long b)
{
	while (b)
	{
		a %= b;
		swap(a, b);
	}
	return a;
}

int main()
{
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);

	int TT;
	scanf("%d", &TT);
	for (int T = 0; T < TT; T++)
	{
		printf("Case #%d: ", T + 1);

		vector<pair<long long, int> > a;
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			int pos;
			scanf("%d", &pos);
			int h;
			scanf("%d", &h);
			long long m;
			scanf("%lld", &m);
			for (int i = 0; i < h; i++)
				a.push_back(make_pair((m + i), pos));
		}
		sort(a.begin(), a.end());

		int res = 0;
		if (a.size() > 1)
		{
			//long long nok = (a[0].first * a[1].first) / nod(a[0].first, a[1].first);
			//long long dst = 360 * nok;
			//a[0].second *= nok;
			//a[1].second *= nok;
			long long t0 = (360 - a[0].second + 360) * a[0].first;
			long long t1 = (360 - a[1].second) * a[1].first;
			if (t0 <= t1)
				res = 1;
		}
		printf("%d\n", res);
	}

	return 0;
}