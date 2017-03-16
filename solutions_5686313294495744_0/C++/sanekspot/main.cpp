#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <utility>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <climits>
#include <cstring>
#include <cmath>
#include <queue>
#include <functional>
#include <cstdio>
#include <cassert>
#include <stack>
#include <unordered_set>

#define mp make_pair
#define mt(x,y,z) mp((x), mp((y), (z)))
#define ZERO(x) memset((x), 0, sizeof(x))
#define NEGATE(x) memset((x), 255, sizeof(x))
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

// globals starts here

const int MAX_N = 1050;
int _globid;
map<string, int> stoid;
string idtos[MAX_N * 2];
ii topic[MAX_N];
int n;
int best;

bool checkmask(int mask)
{
	vector<int> good;
	vector<int> bad;
	for (int i = 0; i < n; ++i)
	{
		if ((mask >> i) & 1)
		{
			bad.push_back(i);
		}
		else
		{
			good.push_back(i);
		}
	}

	set<int> firsts;
	set<int> seconds;
	for (int g : good)
	{
		firsts.insert(topic[g].first);
		seconds.insert(topic[g].second);
	}

	for (int b : bad)
	{
		if (firsts.count(topic[b].first) == 0 || seconds.count(topic[b].second) == 0)
		{
			return false;
		}
	}

	return true;
}

int ones(int mask)
{
	int cnt = 0;
	
	while (mask > 0)
	{
		if (mask & 1)
		{
			++cnt;
		}

		mask >>= 1;
	}

	return cnt;
}

void solvestupid()
{
	_globid = 0;
	stoid.clear();
	best = 0;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string f, s;
		cin >> f >> s;

		if (stoid.count(f) == 0)
		{
			stoid[f] = _globid;
			idtos[_globid] = f;
			++_globid;
		}
		topic[i].first = stoid[f];

		if (stoid.count(s) == 0)
		{
			stoid[s] = _globid;
			idtos[_globid] = s;
			++_globid;
		}
		topic[i].second = stoid[s];

	}

	for (int i = 0; i < (1 << n); ++i)
	{
		if (checkmask(i))
		{
			best = max(best, ones(i));
		}
	}

	cout << best << endl;
}

void solve()
{
	

}

int main()
{
#ifdef XXX
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#elif defined(CONTEST)
	freopen(CONTEST ".in", "r", stdin);
	freopen(CONTEST ".out", "w", stdout);
#endif

	cin.sync_with_stdio(false);
	int tests;
	cin >> tests;

	for (int tc = 1; tc <= tests; ++tc)
	{
		cout << "Case #" << tc << ": ";
		solvestupid();
	}

	return 0;
}