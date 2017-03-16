#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <memory.h>
#include <cassert>

using namespace std;

#define fo(a,b,c) for (int a = (b); a < (c); a++)
#define fr(a,b) fo(a, 0, (b))
#define fi(n) fr(i, (n))
#define fj(n) fr(j, (n))
#define fk(n) fr(k, (n))
#define fd(a,b,c) for (int a = (b); a >= (c); a--)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define _(a,b) memset((a), (b), sizeof(a))
#define __(a) memset((a), 0, sizeof(a))
#define sz(a) (int)(a).size()
#define mp make_pair
#define pb push_back

typedef long long lint;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<string> VS;
typedef pair<int, int> PII;

const int INF = 1000000000;
const lint LINF = 4000000000000000000LL;
const double eps = 1e-9;

void prepare()
{
	freopen("b-large.in", "r", stdin);
	freopen("b-large.out", "w", stdout);
}

void panic(bool expression = false)
{
	if (!expression)
	{
		cerr << "PANIC!" << endl;
		assert(false);
	}
}

int n, m, h;
int ceil[105][105];
int floor[105][105];
double d[105][105];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

bool inside(int x, int y)
{
	return x >= 0 && x < n && y >= 0 && y < m;
}

int getWalkTime(pair<int, int> from, pair<int, int> to, double curh)
{
	if (curh > ceil[to.first][to.second] - 50 + eps)
		return -1;
	if (floor[from.first][from.second] > ceil[to.first][to.second] - 50)
		return -1;
	if (floor[to.first][to.second] > ceil[to.first][to.second] - 50)
		return -1;
	if (floor[to.first][to.second] > ceil[from.first][from.second] - 50)
		return -1;
	if (curh - floor[from.first][from.second] >= 20.0 - eps)
		return 1;
	return 10;
}

double getWaitingTime(pair<int, int> from, pair<int, int> to, double curh)
{
	double dh = max(0.0, 50.0 - (ceil[to.first][to.second] - curh));
	return dh / 10;
}

void initDij()
{
	fi(n)
	{
		fj(m)
			d[i][j] = 1e20;
	}
	queue<pair<int, int> > q;
	q.push(mp(0, 0));
	d[0][0] = 0;
	while (!q.empty())
	{
		pair<int, int> p = q.front();
		q.pop();
		fi(4)
		{
			pair<int, int> t(p.first + dx[i], p.second + dy[i]);
			if (inside(t.first, t.second) && d[t.first][t.second] > eps)
			{
				if (getWalkTime(p, t, h) > 0)
				{
					q.push(t);
					d[t.first][t.second] = 0;
				}
			}
		}
	}
}

double dij()
{
	set<pair<double, pair<int, int> > > q;
	fi(n)
	{
		fj(m)
		{
			if (d[i][j] <= eps)
			{
				q.insert(mp(0, mp(i, j)));
			}
		}
	}

	while (!q.empty())
	{
		pair<int, int> p = q.begin()->second;
		q.erase(q.begin());
		fi(4)
		{
			pair<int, int> t(p.first + dx[i], p.second + dy[i]);
			if (inside(t.first, t.second))
			{
				double curh = max(0.0, h - d[p.first][p.second] * 10);
				panic(curh <= h);
				double waitTime = getWaitingTime(p, t, curh);
				curh -= waitTime * 10;
				int dwalk = getWalkTime(p, t, curh);
				if (dwalk > 0)
				{
					double len = waitTime + dwalk;
					if (d[t.first][t.second] > d[p.first][p.second] + len)
					{
						q.erase(mp(d[t.first][t.second], t));
						d[t.first][t.second] = d[p.first][p.second] + len;
						q.insert(mp(d[t.first][t.second], t));
					}
				}
			}
		}
	}
	return d[n - 1][m - 1];
}

void solve(int test_num)
{
	//cerr << test_num << endl;
	printf("Case #%d: ", test_num);
	scanf("%d%d%d", &h, &n, &m);
	fi(n)
	{
		fj(m)
			scanf("%d", &ceil[i][j]);
	}
	fi(n)
	{
		fj(m)
			scanf("%d", &floor[i][j]);
	}

	initDij();

	printf("%.10lf\n", dij());
}

int main()
{
	prepare();
	int number_of_tests;
	scanf("%d\n", &number_of_tests);
	fi(number_of_tests)
		solve(i + 1);
	return 0;
}