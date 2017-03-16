#include <functional>
#include <algorithm>
#include <strstream>
#include <iostream>
#include <numeric>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 10010000;

int rev(int x)
{
	int r = 0;
	while (x > 0)
	{
		r = r * 10 + x % 10;
		x /= 10;
	}
	return r;
}

int ans[maxn];
int tst[maxn];

const int inf = 1000000000;

int main()
{
	ios_base::sync_with_stdio(0);
	/*
	fill(ans, ans + maxn, inf);
	set<pair<int, int>> st;

	st.insert(make_pair(1, 1));
	while (!st.empty())
	{
		auto p = *st.begin();
		st.erase(st.begin());
		int u = p.first;
		int c = p.second;
		if (ans[u] != inf)
			continue;
		ans[u] = c;
		if ( u + 1 < maxn && ans[u + 1] == inf)
			st.insert(make_pair(u + 1, c + 1));
		int v = rev(u);
		if ( v < maxn && ans[v] == inf)
			st.insert(make_pair(v, c + 1));

	}
	*/

	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);

	fill(tst, tst + maxn, inf);
	tst[1] = 1;
	for (int i = 2; i < maxn; ++i)
	{
		tst[i] = min(tst[i], tst[i - 1] + 1);
		int j = rev(i);
		if (j < maxn)
		{
			if (j < i && tst[i] + 1 < tst[j])
				cout << "BAD: " << i << ' ' << j << endl;
			if( j > i )
				tst[j] = tst[i] + 1;
		}
	}
	/*
	for (int i = 1; i <= maxn / 10; ++i)
		if (ans[i] != tst[i])
		cout << i << ' ' << ans[i] << ' ' << tst[ i ] << endl;
		*/

	int t;
	cin >> t;
	for (int tt = 1; tt <= t; ++tt)
	{
		int n;
		cin >> n;
		cout << "Case #" << tt << ": " << tst[n] << endl;
	}
	return 0;
}