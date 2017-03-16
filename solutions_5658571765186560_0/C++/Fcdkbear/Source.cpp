#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <memory.h>
#include <ctime>
#include <bitset>
#include <unordered_set>
#include <unordered_map>

using namespace std;

#define ABS(a) ((a>0)?a:-(a))
#define MIN(a,b) ((a<b)?(a):(b))
#define MAX(a,b) ((a<b)?(b):(a))
#define FOR(i,a,n) for (int i=(a);i<(n);++i)
#define FI(i,n) for (int i=0; i<(n); ++i)
#define pnt pair <int, int>
#define mp make_pair
#define PI 3.1415926535897
#define MEMS(a,b) memset(a,b,sizeof(a))
#define LL long long
#define U unsigned

vector<vector<int> > all[7];
vector<vector<int> > min1[7];
int a[6][6];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };
int was[6][6];
void dfs(int x, int y)
{
	if ((x<0) || (y<0) || (x>5) || (y>5))
		return;
	if (was[x][y])
		return;
	if (a[x][y] == 0)
		return;
	was[x][y] = 1;
	FOR(k, 0, 4)
		dfs(x + dx[k], y + dy[k]);
}

void generateAllMasks(int x, int y, int tot)
{
	if (y == 6)
	{
		generateAllMasks(x + 1, 0, tot);
		return;
	}
	if (x == 6)
	{
		bool good = true;
		MEMS(was, 0);
		dfs(0, 0);
		FOR(i, 0, 6)
		{
			FOR(j, 0, 6)
			{
				if ((a[i][j] == 1) && (was[i][j] == 0))
					return;
			}
		}
		vector<int> now;
		FOR(i, 0, 6)
		{
			int mask = 0;
			FOR(j, 0, 6)
			{
				if (a[i][j])
					mask |= (1 << j);
			}
			now.push_back(mask);
		}
		while (now.back() == 0)
			now.pop_back();
		all[tot].push_back(now);
		return;
	}
	if (tot < 6)
	{
		a[x][y] = 1;
		generateAllMasks(x, y + 1, tot + 1);
	}
	a[x][y] = 0;
	if (tot)
		generateAllMasks(x, y + 1, tot);
}

int tmp[6][6];
int tmp1[6][6];

void toArray(vector<int> now)
{
	MEMS(tmp, 0);
	FOR(i, 0, now.size())
	{
		FOR(j, 0, 6)
			tmp[i][j] = ((now[i] >> j) & 1);
	}
}

vector<int> toMask()
{
	vector<int> now;
	FOR(i, 0, 6)
	{
		int mask = 0;
		FOR(j, 0, 6)
		{
			if (tmp[i][j])
				mask |= (1 << j);
		}
		now.push_back(mask);
	}
	while (now.back() == 0)
		now.pop_back();
	return now;
}

vector<int> reflect(vector<int> now)
{
	toArray(now);
	FOR(j, 0, 6)
		FOR(i, 0, now.size() / 2)
		swap(tmp[i][j], tmp[now.size() - i - 1][j]);
	return toMask();
}

vector<int> rotate(vector<int> now)
{
	toArray(now);
	FOR(i, 0, 6)
		FOR(j, 0, 6)
		tmp1[i][j] = tmp[6 - j - 1][i];
	memcpy(tmp, tmp1, sizeof(tmp));
	return toMask();
}

int p[7][4010];

int find(int v, int x)
{
	if (p[v][x] == x)
		return p[v][x];
	return find(v, p[v][x]);
}

void join(int v, int x, int y)
{
	x = find(v, x);
	y = find(v, y);
	if (rand() & 1)
		p[v][x] = y;
	else
		p[v][y] = x;
}

int N, M, X;
int b[21][21];
int solve(int x, int y, int need, int f)
{
	if (x == N)
	{
		if (!f)
			return 0;
		FOR(i,0,N)
			FOR(j,0,M)
		if (b[i][j] == 0)
			return 0;
		return 1;
	}
	if (y == M)
	{
		return solve(x + 1, 0, need, f);
	}
	FOR(it, 0, all[X].size())
	{
		if (x + all[X][it].size() > N)
			continue;
		bool good = true;
		FOR(i, 0, all[X][it].size())
		{
			if (!good)
				break;
			FOR(j, 0, 6)
			{
				if ((all[X][it][i] >> j) & 1)
				{
					if ((y + j > M) || (b[x + i][y + j] == 1))
					{
						good = false;
						break;
					}
				}
			}
		}
		if (good)
		{
			FOR(i, 0, all[X][it].size())
			{
				FOR(j, 0, 6)
				{
					if ((all[X][it][i] >> j) & 1)
					{
						b[x + i][y + j] = 1;
					}
				}
			}
			int res = solve(x, y + 1, need, (f | (min1[X][it] == min1[X][need])));
			if (res)
				return res;
			FOR(i, 0, all[X][it].size())
			{
				FOR(j, 0, 6)
				{
					if ((all[X][it][i] >> j) & 1)
					{
						b[x + i][y + j] = 0;
					}
				}
			}
		}
	}
	if (b[x][y] == 0)
		return 0;
	return solve(x,y+1,need,f);
}

map<pair<int, pnt>, int> mm;
set<vector<int> > used;
set<vector<int> > used1;
int ansQuery(int x, int n, int m)
{
	if (n > m)
		swap(n, m);
	if (mm.find(mp(x, mp(n, m))) != mm.end())
		return mm[mp(x, mp(n, m))];
	if ((n*m) % x)
		return 0;
	if (x >= 7)
		return 0;
	N = n;
	M = m;
	X = x;
	used.clear();
	used1.clear();
	FOR(i, 0, all[x].size())
	{
		//cout << i << endl;
		MEMS(b, 0);
		if (used.find(min1[x][i]) != used.end())
			continue;
		if (used1.find(all[x][i]) != used1.end())
			continue;
		used1.insert(all[x][i]);
		used.insert(min1[x][i]);
		int val = solve(0, 0, i, 0);
		if (!val)
			return mm[mp(x,mp(n,m))] = 0;
	}
	return mm[mp(x, mp(n, m))] = 1;
}

void outAll(int p)
{
	FOR(i, 0, all[p].size())
	{
		FOR(j, 0, all[p][i].size())
			cout << all[p][i][j] << " ";
		cout << endl;
	}
}

int main()
{
#ifdef Fcdkbear
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	double beg = clock();
#else
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif

	generateAllMasks(0, 0, 0);
	FOR(i, 0, 5)
		FOR(j, 0, 4000)
		p[i][j] = j;
	FOR(it, 1, 5)
	{
		int sz = all[it].size();
		FOR(i, 0, sz)
		{
			vector<int> now1 = all[it][i];
			min1[it].push_back(now1);
			FOR(it1, 0, 4)
			{
				FOR(it2, 0, 2)
				{
					all[it].push_back(now1);
					now1 = reflect(now1);
				}
				now1 = rotate(now1);
			}
		}
	}
	FOR(it, 1, 5)
	{
		FOR(i, 0, all[it].size())
		{
			vector<int> now1 = all[it][i];
			min1[it].push_back(now1);
			FOR(it1, 0, 4)
			{
				FOR(it2, 0, 2)
				{
					min1[it][i] = MIN(min1[it][i], now1);
					now1 = reflect(now1);
				}
				now1 = rotate(now1);
			}
		}
	}
	//outAll(2);
	int tests;
	scanf("%d", &tests);
	FOR(it, 0, tests)
	{
		int x, n, m;
		cin >> x >> n >> m;
		int res = ansQuery(x, n, m);
		if (res)
			printf("Case #%d: GABRIEL\n", it+1);
		else
			printf("Case #%d: RICHARD\n", it+1);
		fprintf(stderr, "%d\n", it);
	}

#ifdef Fcdkbear
	double end = clock();
	fprintf(stderr, "*** Total time = %.3lf ***\n", (end - beg) / CLOCKS_PER_SEC);
#endif
	return 0;
}