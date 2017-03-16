#include <stdio.h>
#include <math.h>
#include <memory.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define _(a, b) memset(a, b, sizeof(a))

typedef long long lint;
typedef unsigned long long ull;

const int INF = 1000000000;
const lint LINF = 4000000000000000000ll;
const double eps = 1e-9;

void prepare()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int TEST = 0;

int h[500];
int h1[500];
const int off = 250;

//day, str, left, right
vector< pair< pair<int, int>, pair<int, int> > > atk;

bool solve()
{
	_(h, 0);
	atk.clear();

	int ans = 0;

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int d, k, w, e, s, dd, dp, ds;

		scanf("%d%d%d%d%d%d%d%d", &d, &k, &w, &e, &s, &dd, &dp, &ds);

		for (int j = 0; j < k; j++)
		{
			atk.pb( mp( mp(d, s), mp(w + off, e + off) ) );

			d += dd;
			w += dp;
			e += dp;
			s += ds;
		}
	}
	
	sort(atk.begin(), atk.end());

	for (int i = 0; i < atk.size(); i++)
	{
		int cur = i;

		memcpy(h1, h, sizeof(h));

		int day = atk[i].first.first;
		while (i < atk.size() && atk[i].first.first == day) i++;

		for (int j = cur; j < i; j++)
		{
			bool ok = false;
			for (int pos = atk[j].second.first; pos < atk[j].second.second && !ok; pos++)
				if (h[pos] < atk[j].first.second)
					ok = true;

			if (ok)
			{
				ans++;
				for (int pos = atk[j].second.first; pos < atk[j].second.second; pos++)
					h1[pos] = max(h1[pos], atk[j].first.second);
			}
		}

		memcpy(h, h1, sizeof(h));

		i--;
	}

	TEST++;
	printf("Case #%d: %d\n", TEST, ans);

	return false;
}

int main()
{
	prepare();
	int tn;
	for (scanf("%d", &tn); tn; tn--)
		solve();
	return 0;
}