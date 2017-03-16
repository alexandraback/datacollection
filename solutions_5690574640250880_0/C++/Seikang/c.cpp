//Seikang

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <stdlib.h>
#include <assert.h>

#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>

#include <cmath>
#include <complex>
#include <algorithm>

#include <ctime>
#define gtime clock()

using namespace std;

#define SZ(cont) (int)(cont.size())
#define ALL(cont) (cont).begin(), (cont).end()
#define DEBUG(x) cerr << ">" << #x << ":" << x << endl

typedef long long int64;
typedef pair<int64, int64> ii;
typedef vector<int64> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;

const int64 oo32 = 1ll << 30, oo64 = 1ll << 60;
const double pi = acos(-1.0), eps = 1e-9;
inline bool equal(const double &a, const double &b){return abs(a - b) < eps;}

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 1, 0, -1, 1, -1, 1, 0};
const int mineID = -1;


bool valid(vvi &grid, int x, int y)
{
	if(x < 0 || y < 0)
		return false;
	if(grid.size() <= x || grid[0].size() <= y)
		return false;
	return true;
}

int mines(vvi &grid, int x, int y)
{
	int ans = 0;
	for (int i = 0; i < 8; ++i)
	{
		int tx = x + dx[i];
		int ty = y + dy[i];
		if(!valid(grid, tx, ty))
			continue;
		ans += (grid[tx][ty] == mineID);
	}
	return ans;
}


bool eval(vvi &grid)
{
	for (int i = 0; i < grid.size(); ++i)
	{
		for (int j = 0; j < grid[0].size(); ++j)
		{
			if(grid[i][j] != mineID)
				grid[i][j] = oo64;
		}
	}

	if (mines(grid, 0, 0) != 0)
	{
		int m = mines(grid, 0, 0);
		//cout << m << endl;

		if(valid(grid, 1, 0))
			m--;
		if(valid(grid, 0, 1))
			m--;
		if(valid(grid, 1, 1))
			m--;

		return m == 0;
	}

	queue<ii> q;
	q.push(make_pair(0, 0));
	grid[0][0] = 0;
	while(!q.empty())
	{
		ii p = q.front(); q.pop();
		int x = p.first, y = p.second;;
		
		for (int i = 0; i < 8; ++i)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			if(!valid(grid, tx, ty))
				continue;
			if(grid[tx][ty] != oo64)
				continue;
			grid[tx][ty] = mines(grid, tx, ty);
			if(grid[tx][ty] == 0)
				q.push(make_pair(tx, ty));
		}
	}

	for (int i = 0; i < grid.size(); ++i)
	{
		for (int j = 0; j < grid[0].size(); ++j)
		{
			if(grid[i][j] == oo64)
				return false;
		}
	}
	return true;
}

void print_grid(vvi &grid)
{
	for (int i = 0; i < grid.size(); ++i)
	{
		for (int j = 0; j < grid[0].size(); ++j)
		{
			if(i == 0 && j == 0)
				cout << 'c';
			else if(grid[i][j] == mineID)
				cout << '*';
			else
				cout << '.';
		}
		cout << endl;
	}
}

int main()
{
	//freopen ("c.in", "rt", stdin);
	//freopen ("c.out", "wt", stdout);
	int T, r, c, m;
	cin >> T;
	for (int t = 1; t <= T; ++t)
	{
		cout << "Case #" << t << ":" << endl;
		cin >> r >> c >> m;

		vvi grid = vvi(r, vi(c));
		//cout << grid.size() << endl;
		//cout << grid[0].size() << endl;

		while(m >= min(r, c))
		{
			//cout << r << " " << c << " " << m << endl;

			if(r >= c)
			{
				r--;
				for (int i = 0; i < c; ++i)
					grid[r][i] = mineID;
					
				m -= c;
			}
			else
			{
				c--;
				for (int i = 0; i < r; ++i)
					grid[i][c] = mineID;
				
				m -= r;
			}

		}
		//cout << "reach " <<endl;
		//cout << c << r << m << endl;

		if(c >= r)
		{
			//cout << "reach " <<endl;
			for (int i = 1; m && i < c - 1; ++i)
			{
				grid[r - 1][c - i] = mineID;
				m--;
			}
			if(m == 1)
			{
				grid[r - 2][c - 1] = mineID;
			}
			//cout << "reach " <<endl;
		}
		else
		{
			for (int i = 1; m && i < r - 1; ++i)
			{
				grid[r - i][c - 1] = mineID;
				m--;
			}
			if(m == 1)
			{
				grid[r - 1][c - 2] = mineID;
			}
		}

		if(eval(grid))
			print_grid(grid);
		else
			cout << "Impossible" << endl;
	}
	return 0;
}
