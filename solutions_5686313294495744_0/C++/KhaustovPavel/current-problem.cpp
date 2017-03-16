#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES
 
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <sstream>
#include <set>
#include <map>
#include <queue>
#include <memory.h>
#include <ctime>
 
using namespace std;
 
#pragma comment(linker, "/STACK:128000000")
 
typedef pair<int, int> pii;
typedef long long int64;
typedef pair<int64, int64> pii64;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
typedef pair<int,pii> piii;
typedef pair<int64,pii> piii64;
typedef pair<pii,pii> piiii;
typedef pair<double, double> pdd;
typedef pair<double, int> pdi;
 
#define y1 dsjfksdj_fks
#define y2 alksaad_sa
#define y0 _sdkfsjfs__
 
#define tm _dskfjskdfjksdf

map<string, int> idsa;
map<string, int> idsb;

inline int get_id_a(string s, bool add = false)
{
	map<string, int>::iterator fit = idsa.find(s);
	if (fit == idsa.end())
	{
		if (add)
		{
			int nid = static_cast<int>(idsa.size());
			idsa[s] = nid;
			return nid;
		} else {
			return -1;
		}
	}
	return fit->second;
}

inline int get_id_b(string s, bool add = false)
{
	map<string, int>::iterator fit = idsb.find(s);
	if (fit == idsb.end())
	{
		if (add)
		{
			int nid = static_cast<int>(idsb.size());
			idsb[s] = nid;
			return nid;
		} else {
			return -1;
		}
	}
	return fit->second;
}

int nt;
int n;
int k1, k2;
string s1, s2;
vector<pii> a;
vvi g;
vector<bool> used;
vector<int> mp;

bool dfs(int x)
{
	if (used[x]) return false;

	used[x] = true;

	int k = static_cast<int>(g[x].size());
	for (int i = 0; i < k; ++i)
	{
		int y = g[x][i];
		if (mp[y] == -1 || dfs(mp[y]))
		{
			mp[y] = x;
			return true;
		}
	}

	return false;
}

inline int solve()
{
	g.clear();
	k1 = static_cast<int>(idsa.size());
	k2 = static_cast<int>(idsb.size());
	g.resize(k1);
	for (int i = 0; i < n; ++i)
	{
		g[a[i].first].push_back(a[i].second);
	}
	mp.clear();
	mp.assign(k2, -1);
	for (int i = 0; i < k1; ++i)
	{
		used.clear();
		used.assign(k1, false);
		dfs(i);
	}
	int res = k1 + k2;
	int nn = n;
	for (int i = 0; i < k2; ++i)
	{
		if (mp[i] != -1) {
			res -= 2;
			--nn;
		}
	}
	res = nn - res;
	return res;
}

int main()
{
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	
	cin >> nt;
	for (int tn = 1; tn <= nt; ++tn)
	{
		idsa.clear();
		idsb.clear();
		a.clear();
		cin >> n;
		a.resize(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> s1 >> s2;
			a[i] = pii(get_id_a(s1, true), get_id_b(s2, true));
		}
		int res = solve();
		printf("Case #%d: %d\n", tn, res);
	}

    return 0;
}  