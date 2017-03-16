#include <stdio.h>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <memory.h>
#include <algorithm>
#include <cassert>
#include <math.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define _(a, b) memset(a, b, sizeof(a))

typedef long long lint;
typedef unsigned long long ull;

const double eps = 1e-9;
const int INF = 1000000000;
const lint LINF = 4000000000000000000ll;

void prepare()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#else
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int n, m;
pair<lint, int> toys[105];
pair<lint, int> boxes[105];

map<lint, int> tid, bid;

vector<int> off;

lint ans;

void go(int k, int from)
{
	if (k == n)
	{
		lint val = 0ll;

		int last = -1;
		lint lastcc = 0ll;
		for (int i = 0; i < n; i++)
		{
			lint left = toys[i].first;

			for (int j = last; j <= off[i]; j++)
			{
				if (j != last)
				{
					last = j;
					lastcc = boxes[j].first;
				}

				if (boxes[j].second == toys[i].second)
				{
					lint diff = min(left, lastcc);
					left -= diff;
					lastcc -= diff;
					val += diff;
				}
			}
		}

		ans = max(ans, val);

		return;
	}

	for (int i = from; i < m; i++)
	{
		off.pb(i);
		go(k + 1, i);
		off.pop_back();
	}
}

bool solve()
{
	tid.clear();
	bid.clear();

	scanf("%d%d", &n, &m);
	//n = 100;
	//m = 100;

	vector<lint> xc;
	xc.pb(0);

	tid[0] = -1;
	bid[0] = -1;

	lint sum = 0ll;
	for (int i = 0; i < n; i++)
	{
		scanf("%lld%d", &toys[i].first, &toys[i].second);
		//toys[i].first = (123 * (lint)rand() * (lint)rand() * (lint)rand() ^ rand());
		//toys[i].second = rand() % 5;

		sum += toys[i].first;
		tid[sum] = toys[i].second;
	}

	lint a = sum;

	sum = 0ll;
	for (int i = 0; i < m; i++)
	{
		scanf("%lld%d", &boxes[i].first, &boxes[i].second);
		//boxes[i].first = (123 * (lint)rand() * (lint)rand() * (lint)rand() ^ rand());
		//boxes[i].second = rand() % 5;

		sum += boxes[i].first;
		bid[sum] = boxes[i].second;
	}

	ans = 0ll;
	go(0, 0);

	static int TT = 0;
	printf("Case #%d: ", ++TT);
	printf("%lld\n", ans);

	return false;
}

int main()
{
	prepare();
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
		solve();
	return 0;
}