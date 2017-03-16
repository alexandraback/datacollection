#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <set>
using namespace std;
const int MAX = 21;
vector<vector<pair<int, int> > > vv[MAX];
set<long long> s[7];
bool mark[MAX][MAX];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
bool can(int x, int y)
{
	if (mark[x][y])
		return false;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < MAX && 0 <= ny && ny < MAX && mark[nx][ny])
			return true;
	}
	return false;
}
vector<pair<int, int> > v;
void check()
{
	v.clear();
	int mnx = MAX, mny = MAX;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			if (mark[i][j])
			{
				v.push_back(make_pair(i, j));
				mnx = min(mnx, i);
				mny = min(mny, j);
			}
	for (int i = 0; i < v.size(); i++)
	{
		v[i].first -= mnx;
		v[i].second -= mny;
	}
	long long hx = 0, hy = 0;
	for (int i = 0; i < v.size(); i++)
	{
		hx = hx * 10 + v[i].first + 1;
		hy = hy * 10 + v[i].second + 1;
	}
	long long h = hx * 1e9 + hy;
	if (s[v.size()].count(h))
		return;
	s[v.size()].insert(h);
	vv[v.size()].push_back(v);
}
void bt(int size)
{
	check();
	if (size == 6)
		return;
	for (int i = 0; i < MAX; i++)
		for (int j = 0; j < MAX; j++)
			if (can(i, j))
			{
				mark[i][j] = true;
				bt(size + 1);
				mark[i][j] = false;
			}
}
int cnt;
void dfs(int x, int y, int n, int m)
{
	mark[x][y] = true;
	cnt++;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < m && !mark[nx][ny])
			dfs(nx, ny, n, m);
	}
}
bool gs(int size, int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (!mark[i][j])
			{
				cnt = 0;
				dfs(i, j, n, m);
				if (cnt % size)
					return false;
			}
	return true;
}
bool _solve(vector<pair<int, int> > v, int n, int m)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			bool valid = true;
			for (int k = 0; k < v.size(); k++)
				valid &= (0 <= v[k].first + i && v[k].first + i < n && 0 <= v[k].second + j && v[k].second + j < m);
			if (!valid)
				continue;
			memset(mark, false, sizeof(mark));
			for (int k = 0; k < v.size(); k++)
				mark[v[k].first + i][v[k].second + j] = true;
			if (gs(v.size(), n, m))
				return true;
		}
	return false;
}
bool solve(vector<pair<int, int> > v, int n, int m)
{
	return _solve(v, n, m) || _solve(v, m, n);
}
int main()
{
	ios::sync_with_stdio(false);
	mark[8][0] = true;
	bt(1);
	int t;
	cin >> t;
	for (int _ = 1; _ <= t; _++)
	{
		int x, r, c;
		cin >> x >> r >> c;
		if (x > 6)
			cout << "Case #" << _ << ": RICHARD\n";
		else
		{
			bool ans = true;
			for (int i = 0; i < vv[x].size() && ans; i++)
				ans &= solve(vv[x][i], r, c);
			if (ans)
				cout << "Case #" << _ << ": GABRIEL\n";
			else
				cout << "Case #" << _ << ": RICHARD\n";
		}
	}
	return 0;
}
