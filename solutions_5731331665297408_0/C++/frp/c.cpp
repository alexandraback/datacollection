#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

vector<string> zipcodes;
vector<vector<pair<int, bool> > > g;
vector<int> path;
//set<pair<int, int> > back_routes;
vector<set<int> > back_g;

int n;

string res_str;
string cur_str;

vector<bool> used;

void mega_dfs(int v, int len, bool ret)
{
	bool was_used = used[v];
	used[v] = true;
	if (!ret)
	{
		cur_str += zipcodes[v];
		len++;
		if (len == n)
		{
			if (cur_str < res_str)
				res_str = cur_str;
			cur_str.erase(cur_str.size() - 5);
			used[v] = false;
			return;
		}
	}
	for (auto & p : g[v])
		if (!p.second && !used[p.first] && back_g[v].find(p.first) == back_g[v].end())
		{
			p.second = true;
			back_g[p.first].insert(v);
			mega_dfs(p.first, len, false);
			back_g[p.first].erase(v);
			p.second = false;
		}
	set<int> bg_v = back_g[v];
	for (auto & p : bg_v)
	{
		back_g[v].erase(p);
		mega_dfs(p, len, true);
		back_g[v].insert(p);
	}

	if (!ret)
		cur_str.erase(cur_str.size() - 5);
	if (!was_used)used[v] = false;
}

void test(int t)
{
	int m;
	cin >> n >> m;
	zipcodes.resize(n);
	used.assign(n, false);
	for (int i = 0; i < n; i++)
		cin >> zipcodes[i];
	g.assign(n, vector<pair<int, bool> >());
	back_g.assign(n, set<int>());
	for (int i = 0; i < m; i++)
	{
		int u, v;
		cin >> u >> v;
		u--; v--;
		g[u].push_back(make_pair(v, false));
		g[v].push_back(make_pair(u, false));
	}
	res_str = "";
	cur_str = "";
	for (int i = 0; i < n; i++)
		res_str += "AAAAA";
	for (int i = 0; i < n; i++)
		mega_dfs(i, 0, false);
	cout << "Case #" << t << ": " << res_str << endl;
}

int main()
{
	int t;
	cin >> t;
	for (int i = 1; i <= t; i++)
		test(i);
}
