#if 1
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <functional>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <ctime>
#include <cassert>
#include <sstream>
#include <iostream>
#include <bitset>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int , int> pii;
typedef vector <int> veci;
typedef vector <veci> graph;
const LD eps = 1e-9;
const LD pi = acos(-1.0);
const int inf = 1000 * 1000 * 1000;
const LL inf64 = LL(inf) * inf;

#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define iss istringstream
#define oss ostringstream
#define dbg(x) {cerr << #x << " = " << x << endl;}
#define dbgv(x) {cerr << #x << " ={"; for (int _i = 0; _i < x.size(); _i++) {if (_i) cerr << ", "; cerr << x[_i];} cerr << "}" << endl;}
#define NAME "problem"

struct state_t
{
	LD cost;
	int x, y;
	state_t() {}
	state_t(LD cost, int x, int y) : cost(cost), x(x), y(y) {}
	friend bool operator < (const state_t &a, const state_t &b)
	{
		return a.cost > b.cost;
	}
};

void solve(int test)
{
	int h, n, m;
	cin >> h >> n >> m;
	vector< vector<int> > f(n, vector<int>(m));
	vector< vector<int> > c(n, vector<int>(m));
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> c[i][j];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			cin >> f[i][j];


	vector< vector<LD> > d(n, vector<LD>(m));
	vector< vector<int> > was(n, vector<int>(m));

	priority_queue< state_t > q;

	q.push(state_t(0.0, 0, 0));
	was[0][0] = true;
//	d[0][0] = -inf;
	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};
	while(q.size())
	{
		state_t cur = q.top(); q.pop();
		if(d[cur.x][cur.y] < cur.cost)
			continue;

		int x = cur.x, y = cur.y;
		LD t = cur.cost;
		for(int i = 0; i < 4; ++i)
		{
			int nx = cur.x + dx[i], ny = cur.y + dy[i];
			if(0 > nx || 0 > ny || nx >= n || ny >= m)
				continue;

			if(c[nx][ny] - f[nx][ny] < 50 - eps)
				continue;
			if(c[x][y] - f[nx][ny] < 50 - eps)
				continue;
			if(c[nx][ny] - f[x][y] < 50 - eps)
				continue;
			

			LD need_t = (50 - c[nx][ny] + h) / 10.0;
			if(need_t < t)
				need_t = t;

			LD cur_w = max(LD(0.0), h - 10.0 * need_t);			

			LD add = 0.0;
			if(cur_w - f[x][y] > 20.0 - eps)
				add = 1.0;
			else
				add = 10.0;
			if(need_t > eps)
				need_t += add;
			if(!was[nx][ny] || d[nx][ny] > need_t)
			{
				d[nx][ny] = need_t;
				was[nx][ny] = true;
				q.push(state_t(need_t, nx, ny));
			}			
		}		
	}


	LD ans = d[n - 1][m - 1];
	cout.precision(9);
	cout.setf(ios::fixed);
	cout << "Case #" << test << ": " << ans << endl;
}

int main()
{
	//freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
	//freopen(NAME ".in","r",stdin);freopen(NAME ".out","w",stdout);

	int tt; cin >> tt;
	for(int t = 1; t <= tt; ++t) solve(t);

	return 0;
}
/*************************
*************************/
#endif
