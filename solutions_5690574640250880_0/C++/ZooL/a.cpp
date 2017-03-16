#include <functional>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <list>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;

const LD eps = 1e-9;
const LD pi = acos(-1.0);
const LL inf = 1e+9;

#define mp make_pair
#define pb push_back
#define X first
#define Y second

#define dbg(x) { cerr << #x << " = " << x << endl; }


typedef vector<int> vi;
typedef vector<vi> vvi;

#define forn(i, n) for (int i = 0; i < n; ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()

#define START clock_t _clock = clock();
#define END cerr << endl << "time: " << (clock() - _clock) / LD(CLOCKS_PER_SEC) << endl;

#define NAME "problem"

int sm[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

bool ch(int x, int y, int n, int m)
{
	return x >= 0 && y >= 0 && x < n && y < m;
}

int check(vector <vector <char> > &g)
{
	int n = g.size();
	int m = g[0].size();
	vector <vector <int> > a(n, m);
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < m; k++)
		{
			 for (int j = 0; j < 8; j++)
			 {
				 int nx = i + sm[j][0];
				 int ny = k + sm[j][1];
				 if (ch(nx, ny, n, m) && g[nx][ny] == '*')
				 {
					 a[i][k]++;
				 }
			 }
		}
	}

	char used[51][51] = {};
	queue<pii> q;
	used[n - 1][m - 1] = 1;
	if (a[n - 1][m - 1] == 0)
		q.push(mp(n - 1, m - 1));
	
	while (!q.empty())
	{
		pii cur = q.front();
		q.pop();
		for (int j = 0; j < 8; j++)
		{
			int nx = cur.X + sm[j][0];
			int ny = cur.Y + sm[j][1];
			if (ch(nx, ny, n, m) && !used[nx][ny] && g[nx][ny] != '*')
			{
				used[nx][ny] = 1;
				if (a[nx][ny] == 0)
				{
					q.push(mp(nx, ny));
				}
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int k = 0; k < m; k++)
			if (!used[i][k])
				cnt++;
	return cnt;
}
int bits (int mask)
{
	int cnt = 0;
	while (mask)
	{
		mask &= (mask - 1);
		cnt++;
	}
	return cnt;
}
int main()
{
    //freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout);
    freopen("input.txt", "r", stdin);  freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int q = 0; q < T; q++)
	{
		cerr << q << endl;
		 int R, C, M, M1;
		 cin >> R >> C >> M;

		 cout << "Case #" << q + 1 << ": " << endl;
		 vector <vector <char> > res(R, vector <char> (C));
		 bool fl = 0;
		 for (int mask = 0; mask < (1 << (R * C)); mask++)
		 {
			 for (int i = 0; i < R * C; i++)
			 {
				 if (mask & (1 << i))
				 {
					 res[i / C][i % C] = '*';
				 }
				 else
					 res[i / C][i % C] = '.';
			 }
			 if (res[R - 1][C - 1] == '*' || bits(mask) != M)
				 continue;
			 res[R - 1][C - 1] = 'c';
			 if (check(res) == M)
			 {
				for (int i = 0; i < R; i++)
				{
					for (int j = 0; j < C; j++)
					{
						cout << res[i][j];
					}
					cout << endl;
				} 
				fl = 1;
				break;
			 }
		 }
		 if (!fl)
			 cout << "Impossible" << endl;
	}

    return 0;
}
/*******************************************
*******************************************/
