#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <ctime>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define VAL(x) #x << " = " << (x) << "   "
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define CLR(x, a) memset(x, a, sizeof x)
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define FOR(i, n) for (int i = 0; i < (n); i ++)
#define X first
#define Y second
#define EPS (1e-8)

//#define cin fin
//#define cout fout

//ifstream fin("problem.in");
//ofstream fout("problem.out");

const int MAXN = 1 * 10 + 10;

bool a[MAXN][MAXN], reveal[MAXN][MAXN], mark[MAXN][MAXN];
int n, m, x;

int dx[] = {1, -1, 0, 0, 1, 1, -1, -1};
int dy[] = {0, 0, 1, -1, 1, -1, 1, -1};

bool inRange(int x, int y)
{
	return (x >= 0 && x < n && y >= 0 && y < m);
}

void dfs(int x, int y)
{
	reveal[x][y] = true;

	if (!mark[x][y]) return;

	for (int i = 0; i < 8; i ++)
	{
		int cx = x + dx[i], cy = y + dy[i];
		if (inRange(cx, cy) && !reveal[cx][cy]) dfs(cx, cy);
	}
}

bool check()
{
	if (n * m - x == 1) return true;

	CLR(mark, 0);
	CLR(reveal, 0);

	FOR(i, n) FOR(j, m) 
	{
		if (a[i][j]) continue;
		
		int cnt = 0;
		FOR(k, 8)
		{
			int x = i + dx[k], y = j + dy[k];
			if (!inRange(x, y) || !a[x][y]) cnt ++;
		}
		
		mark[i][j] = (cnt == 8);
	}

	bool flag = false;	
	FOR(i, n) FOR(j, m) if (!flag && mark[i][j])
	{
		dfs(i, j);
		flag = true;
		break;
	}

	int tot = 0;
	FOR(i, n) FOR(j, m) tot += reveal[i][j];

	return (tot == (n * m - x));
}

int main ()
{
	ios::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for (int o = 1; o <= tc; o ++)
	{
		cin >> n >> m >> x;
		
		bool found = false;
		cout << "Case #" << o << ":\n";
		for (int i = 0; i < (1 << (n * m)); i ++)
		{
			CLR(a, 0);
			for (int j = 0; j < n * m; j ++)
				if (i & (1 << j))
					a[j / m][j % m] = true;

			if (__builtin_popcount(i) == x && check())
			{
				found = true;

				bool click = false;
				for (int j = 0; j < n; j ++)
				{
					for (int k = 0; k < m; k ++)
					{
						if (!a[j][k])
						{
							if (n * m - x == 1 || (!click && mark[j][k]))
							{
								click = true;
								cout << 'c';
							}
							else cout << '.';
						}
						else cout << '*';
					}
					cout << endl;
				}

				break;
			}
		}

		if (!found) cout << "Impossible\n";
	}
	return 0;
}

