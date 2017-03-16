#include <algorithm>
#include <iostream>
#include <set>
#include <string>
#include <vector>

using namespace std;

typedef vector<int> vi;

vector<int> v;
vector<vi> vr;
vector<int> g;

int get(int i)
{
	while (g[i] != i)
	{
		i = g[i];
	}
	return i;
}

int depth(int curr, int excl)
{
	int res = 0;
	for (int i = 0, size = vr[curr].size(); i < size; ++i)
	{
		if (vr[curr][i] != excl)
			res = max(res, 1 + depth(vr[curr][i], excl));
	}
	return res;
}

int solve()
{
	int n = 0;
	cin >> n;
	v.resize(n);
	vr.resize(n);
	g.resize(n);
	for (int i = 0; i < n; ++i)
	{
		vr[i] = vi();
	}

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
		--v[i];
		vr[v[i]].push_back(i);
		g[i] = i;
	}

	for (int i = 0; i < n; ++i)
	{
		int j = v[i];
		int gi = get(i);
		int gj = get(j);
		if (gi != gj)
		{
			int mn = min(gi, gj);
			int mx = max(gi, gj);
			g[mx] = g[mn];
		}
	}

	for (int i = 0; i < n; ++i)
	{
		//cout << g[i] << endl;
	}

	int res = 0;
	for (int i = 0; i < n; ++i)
	{
		if (g[i] == i)
		{
			//cout << "group " << i << endl;
			set<int> s;
			for (int j = i; j < n; ++j)
			{
				if (get(j) == i)
					s.insert(j);
			}
			vector<int> p;
			for (set<int>::iterator it = s.begin(), end = s.end(); it != end; ++it)
			{
				if (v[v[*it]] == *it)
				{
					p.push_back(*it);
					p.push_back(v[*it]);
					break;
				}
			}
			if (p.empty())
			{
				vector<int> c;
				int curr = *s.begin();
				while (s.find(curr) != s.end())
				{
					c.push_back(curr);
					s.erase(curr);
					curr = v[curr];
				}
				//for (int i = 0; i < c.size(); ++i)
				//	cout << c[i] << endl;
				int j = 0;
				for (j = 0; c[j] != curr; ++j);

				res = max(res, (int)c.size() - j);
			}
			else
			{
				//cout << p[0] << endl;
				//cout << p[1] << endl;
				res = max(res, 2 + depth(p[0], p[1]) + depth(p[1], p[0]));
			}
		}
	}
	return res;
}

int main()
{
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		int res = solve();
		cout << "Case #" << i + 1 << ": ";
		cout << res << endl;
	}
	return 0;
}
