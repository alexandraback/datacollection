#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <set>
#include <unordered_map>
#include <unordered_set>

using namespace std;

#define forsn(i, s, n) for (int i = s; i < n; i++)
#define forn(i, n) forsn(i, 0, n)
#define fore(i, n) forn(i, n.size())

typedef pair <int, int> pii;
#define y first
#define x second

#define popcount __builtin_popcount


namespace Notebook
{
	const int N = 1500;
	const int M = 1500;

	vector <vector <bool>> adj;
	vector <bool> seen;
	vector <int> prev;

	bool dfs(int x)
	{
		if (x == -1) return true;
		if (seen[x]) return false;
		seen[x] = 1;
		for (int i = 0; i < adj[0].size(); ++i)
		{
			if (adj[x][i] && dfs(prev[i]))
			{
				prev[i] = x;
				return true;
			}
		}
		return false;
	}

	int maxflow()
	{
		int flow = 0;
		for (int i = 0; i < adj.size(); i++)
		{
			fill(seen.begin(), seen.end(), false);
			if (dfs(i))
				++flow;
		}
		return flow;
	}
};

struct IncreaseMap
{
	unordered_map <string, int> h;
	int num(const string &s)
	{
		if (h.find(s) == h.end())
		{
			int e = h.size();
			h[s] = e;
		}

		return h[s];
	}
};

int solve(const vector <pii> &W, int n, int m)
{
	Notebook::adj = vector <vector <bool>> (n, vector <bool> (m, false));
	Notebook::seen = vector <bool> (n, false);
	Notebook::prev = vector <int> (m, -1);

	for (const pii &p : W)
		Notebook::adj[p.y][p.x] = true;

	int k = Notebook::maxflow();
	int l = 0;

	unordered_set <int> F;
	for (int k : Notebook::prev)
	{
		if (k == -1)
			l += 1;
		else
			F.insert(k);
	}

	// cerr << "Es " << k << endl;
	return W.size() - k - l - (n - F.size());
}

int main()
{
	int t;
	cin >> t;

	forsn(z, 1, t + 1)
	{
		int n;
		cin >> n;

		IncreaseMap L, R;
		vector <pii> W;
		forn(i, n)
		{
			string a, b;
			cin >> a >> b;

			W.push_back(pii(L.num(a), R.num(b)));
		}

		printf("Case #%d: %d\n", z, solve(W, L.h.size(), R.h.size()));
	}

	return 0;
}
