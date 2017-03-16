#pragma comment(linker, "/STACK:256000000")

#include<stdio.h>
#include<stack>
#include<math.h>
#include<time.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<set>
#include<unordered_set>
#include<iomanip>
#include<memory.h>
#include<vector>
#include<map>
#include<cassert>
#include<queue>

using namespace std;

typedef long long li;
typedef long double ld;

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define pb push_back
#define mp make_pair
#define all(v) v.begin(),v.end()

int n, m, k;

bool read()
{
	cin >> n >> m >> k;
	return true;
}

int used[1 << 20];
int T = 0;
int u[20][20];
bool bad[20][20];
int TT = 0;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

void dfs(int mask, int x, int y)
{
	if (mask & (1 << (x * m + y)))
	{
		bad[x][y] = true;
		return;
	}
	u[x][y] = TT;
	bad[x][y] = true;
	if (x == 0 || y == 0 || x == n - 1 || y == m - 1)
		bad[x][y] = false;
	forn (i, 4)
	{
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 0 || nx == n || ny < 0 || ny == m)
			continue;
		if (u[nx][ny] != TT)
			dfs(mask, nx, ny);
		if (!bad[nx][ny])
			bad[x][y] = false;
	}
}

bool ok(int mask)
{
	TT++;
	int cur = n * m;
	forn (i, n)
	{
		dfs(mask, i, 0);
		dfs(mask, i, m - 1);
	}
	forn (i, m)
	{
		dfs(mask, 0, i);
		dfs(mask, n - 1, i);
	}
	forn (i, n)
		forn (j, m)
			cur -= u[i][j] == TT;
	return cur >= k;
}

void solve()
{
	T++;
	queue<int> q;
	q.push(0);
	while (!q.empty())
	{
		int v = q.front();
		q.pop();
		if (ok(v))
		{
			int ans = 0;
			forn (i, n * m)
			{
				if (v & (1 << i))
					ans++;
			}
			cout << ans << endl;
			return;
		}
		forn (i, n * m)
		{
			int nv = v | (1 << i);
			if (used[nv] != T)
			{
				used[nv] = T;
				q.push(nv);
			}
		}
	}
}

int main()
{

#ifdef Baster
	freopen("C-small-attempt2.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
	
	int t;
	cin >> t;
	forn (i, t)
	{
		read();
		cout << "Case #" << i + 1 << ": "; 
		solve();
	}
	return 0;
}