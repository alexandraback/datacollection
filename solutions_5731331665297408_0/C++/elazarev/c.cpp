#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <string>
using namespace std;
int t;
int n, m;

struct fl
{
	vector<int> ind;
	string s;
	bool operator<(const fl &f) const
	{
		return s < f.s;
	}
};
vector<fl> sols;
vector<vector<int> >g;
vector<string> zip;
bool found = false;

bool can_return(int cur, const vector<pair<int, int> >& ret)
{
/*	cout << cur << " " << endl;
	for (int i = 0; i < ret.size(); ++i)
	{
		cout << ret[i].first << " " << ret[i].second << endl;
	}
	cout << endl;*/

	if (ret.size() == 0)
		return true;

	bool can = false;
	for (int i = 0; i < ret.size(); ++i)
	{
		if (ret[i].second == cur)
		{
			int ncur = ret[i].first;
			vector<pair<int, int> > r2 = ret;
			r2[i] = r2[r2.size() - 1];
			r2.pop_back();
			can |= can_return(ncur, r2);
		}
	}
	return can;
}

void go(int d, int cur, int was, const vector<pair<int, int> >& ret, const fl& f)
{
	if (found)
		return;
	if (was == (1 << n) - 1)
	{
		if (can_return(cur, ret))
		{
			cout << f.s << endl;
			found = true;
		}
		return;
	}
	for (int i = 0; i < g[cur].size(); ++i)
	{
		int to = g[cur][i];
		if (d < n && to == f.ind[d] && ((was & (1 << to)) == 0))
		{
			vector<pair<int, int> > r2 = ret;
			r2.push_back(make_pair(cur, to));
			go(d + 1, to, was | (1 << to), r2, f);
		}
	}
	for (int i = 0; i < ret.size(); ++i)
	{
		if (ret[i].second == cur)
		{
			int ncur = ret[i].first;
			vector<pair<int, int> > r2 = ret;
			r2[i] = r2[r2.size() - 1];
			r2.pop_back();
			go(d, ncur, was, r2, f);
		}
	}
}

bool check(const fl& f)
{
	int was = 1 << (f.ind[0]);
	vector<pair<int, int> > ret;
	found = false;
	go(1, f.ind[0], was, ret, f);
	return found;
}

void solve()
{
	int a, b;
	string ans, s;
	fl flight;

	cin >> n >> m;

	zip.resize(n);
	g.assign(n, vector<int>(0)); 
	
	for (int i = 0; i < n; ++i)
		cin >> zip[i];
	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		--a, --b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	vector<int> perm(n);
	for (int i = 0; i < n; ++i)
	{
		perm[i] = i;
		s += zip[i];
	}
	sols.clear();
	flight.ind = perm;
	flight.s = s;
	sols.push_back(flight);
	while(next_permutation(perm.begin(), perm.end()))
	{
		s = "";
		for (int i = 0; i < n; ++i)
			s += zip[perm[i]];
		flight.ind = perm;
		flight.s = s;
		sols.push_back(flight);
	}

	sort(sols.begin(), sols.end());
	for (int i = 0; i < sols.size(); ++i)
	{
		if (check(sols[i]))
			break;
	/*	cout << sols[i].s << " ";
		for (int j = 0; j < n; ++j)
			cout << sols[i].ind[j] << " ";
		cout << endl;*/
	}
}
int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	cin >> t;                                                                                                                                
	for (int i = 0; i < t; ++i)
	{
		cout << "Case #" << i + 1 << ": ";
		solve();
	}
	return 0;
}