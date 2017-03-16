#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <iterator>
#include <list>
#include <set>
#include <queue>
#include <numeric>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

typedef long long lli;
typedef long li;

template <class T>
T Maximize (T &v, T nv) { if (nv > v) v = nv; return v; }

template <class T>
T Minimize (T &v, T nv) { if (nv < v) v = nv; return v; }

const lli INFLL = numeric_limits<lli>::max();
const li INF = numeric_limits<li>::max(), N = 11;

string ss[N];
li n, sumLength;
vector <li> pos['z' + 1];
bool u[N];

li dfs (li v, li index)
{
	bool ok = 1;
	for (li j = 0; j < ss[v].length(); ++ j)
	{
		char c = ss[v][j];
		if (pos[c].empty() || pos[c].back() + 1 == index + j)
		{
			pos[c].push_back(index + j);
			//cout << "push " << c << " " << index + j << "\n";
		}
		else
		{
			//cout << "fail: " << c << " " << pos[c].back() << " != "  << index + j << "\n";
			ok = 0;
			break;
		}
	}

	if (!ok)
	{
		//cout << "!ok\n";
		for (li c = 'a'; c <= 'z'; ++ c)
		{
			while (!pos[c].empty() && pos[c].back() >= index)
			{
				//cout << "pop " << c << " " << pos[c].back() << "\n";
				pos[c].pop_back();
			}
		}
		return 0;
	}

	li newIndex = index + ss[v].length();
	if (newIndex == sumLength) return 1;

	u[v] = 1;
	li res = 0;
	for (li i = 0; i < n; ++ i)
	{
		if (!u[i])
		{
			res += dfs(i, newIndex);
		}
	}

	u[v] = 0;
	for (li c = 'a'; c <= 'z'; ++ c)
	{
		while (!pos[c].empty() && pos[c].back() >= index)
		{
			//cout << "pop " << c << " " << pos[c].back() << "\n";
			pos[c].pop_back();
		}
	}

	return res;
}

void solve ()
{
	ios::sync_with_stdio(0);

	li tests;
	cin >> tests;

	for (li test = 1; test <= tests; ++ test)
	{
		cin >> n;
		sumLength = 0;
		for (li i = 0; i < n; ++ i)
		{
			cin >> ss[i];
			sumLength += ss[i].length();
		}

		li res = 0;
		for (li i = 0; i < n; ++ i)
		{
			res += dfs(i, 0);
		}

		cout << "Case #" << test << ": ";
		cout << res;
		cout << "\n";
	}
}

void init ()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
}

int main()
{
	init();
	solve();
	return 0;
}
