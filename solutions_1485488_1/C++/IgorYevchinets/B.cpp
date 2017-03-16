
#define _CRT_SECURE_NO_DEPRECATE 

#include <string> 
#include <vector> 
#include <map> 
#include <list> 
#include <set> 
#include <queue> 
#include <iostream> 
#include <sstream> 
#include <stack> 
#include <deque> 
#include <cmath> 
#include <memory.h> 
#include <cstdlib> 
#include <cstdio> 
#include <cctype> 
#include <algorithm> 
#include <utility> 

using namespace std; 

#define FOR(i, a, b) for(int i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(int i = (b) - 1; i >= (a); --i)
#define REP(i, N) FOR(i, 0, N)
#define RREP(i, N) RFOR(i, N, 0)

#define ALL(V) V.begin(), V.end()
#define pb push_back
#define mp make_pair
#define EPS 1e-7
#define Pi 3.14159265358979

typedef long long Long;
typedef unsigned long long ULong;
typedef unsigned int Uint;
typedef unsigned char Uchar;
typedef vector <int> VI;
typedef pair <int, int> PI;

const int SZ = 1 << 7;

int C = 20100;

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

int tests;

int h, n, m;

int f[SZ][SZ], c[SZ][SZ];

bool can(int x1, int y1, int x2, int y2, int h)
{
	if(x1 < 0 || x1 >= n)
		throw -1;
	if(y1 < 0 || y1 >= m)
		throw -1;
	if(x2 < 0 || x2 >= n)
		return false;
	if(y2 < 0 || y2 >= m)
		return false;
	if(!(h + 50 <= c[x2][y2] && f[x1][y1] + 50 <= c[x2][y2] && f[x2][y2] + 50 <= c[x2][y2]))
		return false;
	if(!(f[x2][y2] <= c[x1][y1] - 50))
		return false;
	return true;
}

int res[SZ][SZ];

map<int, vector<PI>> Map;

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &tests);
	REP(I, tests)
	{
		scanf("%d%d%d", &h, &n, &m);
		REP(i, n)
			REP(j, m)
				scanf("%d", &c[i][j]);
		REP(i, n)
			REP(j, m)
				scanf("%d", &f[i][j]);

		memset(res, -1, sizeof(res));

		res[0][0] = 0;

		queue<PI> Q;

		Q.push(mp(0, 0));

		while(!Q.empty())
		{
			int x1 = Q.front().first;
			int y1 = Q.front().second;
			Q.pop();
			REP(k, 4)
			{
				int x2 = x1 + dx[k];
				int y2 = y1 + dy[k];
				if(can(x1, y1, x2, y2, h) && res[x2][y2] == -1)
				{
					res[x2][y2] = 0;
					Q.push(mp(x2, y2));
				}
			}
		}

		REP(tm, 3100000)
		{
			if(res[n - 1][m - 1] != -1 && res[n - 1][m - 1] < tm)
				break;
			int lev = h - tm;
			if(tm < C)
			{
				REP(x1, n)
					REP(y1, m)
					{
						if(res[x1][y1] == -1 || res[x1][y1] > tm)
							continue;
						int need = lev >= f[x1][y1] + 20 ? 10 : 100;
						REP(k, 4)
						{
							int x2 = x1 + dx[k];
							int y2 = y1 + dy[k];
							if(can(x1, y1, x2, y2, lev) && (res[x2][y2] == -1 || res[x2][y2] > tm + need))
							{
								res[x2][y2] = tm + need;
							}
						}
					}
			}
			else
			{
				if(tm == C)
				{
					Map.clear();

					REP(i, n)
						REP(j, m)
							Map[res[i][j]].pb(mp(i, j));
				}
				vector<PI> v = Map[tm];
				REP(i, (int)v.size())
				{
					int x1 = v[i].first;
					int y1 = v[i].second;
					
					if(res[x1][y1] == -1 || res[x1][y1] > tm)
						continue;
					int need = lev >= f[x1][y1] + 20 ? 10 : 100;
					REP(k, 4)
					{
						int x2 = x1 + dx[k];
						int y2 = y1 + dy[k];
						if(can(x1, y1, x2, y2, lev) && (res[x2][y2] == -1 || res[x2][y2] > tm + need))
						{
							res[x2][y2] = tm + need;
							Map[tm + need].pb(mp(x2, y2));
						}
					}
				}
			}
		}

		cerr << I + 1 << endl;

		printf("Case #%d: %d.%d\n", I + 1, res[n - 1][m - 1] / 10, res[n - 1][m - 1] % 10);
	}
	return 0;
}