#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include <fstream>
using namespace std;

#define all(o) (o).begin(), (o).end()
#define allr(o) (o).rbegin(), (o).rend()
#define INF 2147483647
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<long long , int> li;
template <class T> int size(T x) { return x.size(); }

li* boxes;
li* toys;
int n, m;

struct state
{
	int b;
	long long bd;
	int t;
	long long td;

	state(int b_, long long bd_, int t_, long long td_)
	{
		b = b_;
		bd = bd_;
		t = t_;
		td = td_;
	}
};

bool operator <(const state& l, const state& r)
{
	if (l.b != r.b) return l.b < r.b;
	if (l.bd != r.bd) return l.bd < r.bd;
	if (l.t != r.t) return l.t < r.t;
	return l.td < r.td;
}

map<state, long long> mem;

long long cnt(int b, long long bd, int t, long long td)
{
	if (b >= n || t >= m) return 0;

	state cur(b, bd, t, td);
	map<state, long long>::const_iterator it = mem.find(cur);
	if (it != mem.end()) return it->second;

	if (boxes[b].second == toys[t].second)
	{
		long long m = min(boxes[b].first - bd, toys[t].first - td);

		if (boxes[b].first == m + bd) b++, bd = -m;
		if (toys[t].first == m + td) t++, td = -m;

		return mem[cur] = m + cnt(b, m + bd, t, m + td);
	}
	else
	{
		return mem[cur] = max(cnt(b + 1, 0, t, td), cnt(b, bd, t + 1, 0));
	}
}

int main()
{
	int ts;
	scanf("%d\n", &ts);

	for (int t = 0; t < ts; t++)
	{
		mem.clear();
		scanf("%d %d\n", &n, &m);
		boxes = new li[n];
		toys = new li[m];

		for (int i = 0; i < n; i++)
			cin >> boxes[i].first >> boxes[i].second;
		
		for (int i = 0; i < m; i++)
			cin >> toys[i].first >> toys[i].second;

		cout << "Case #" << t + 1 << ": " << cnt(0, 0, 0, 0) << endl;
	}

	return 0;
}