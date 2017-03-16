#if 1
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
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

template<class T> string to_str(const T &a) { oss os; os << a; return os.str(); }
template<> string to_str<LD>(const LD& a) { oss os; os.precision(10); os.setf(ios::fixed); os << a; return os.str(); }
template<class T> T from_str(const string &s) { iss is; T val; is >> val; return val; }
string T(int test) { ostringstream os; os << "Case #" << test << ":"; return os.str(); }
int _test_start = -1, _test_end = -1;
bool need_to_run(int test) { return _test_start == -1 || _test_start <= test && test <= _test_end; }


void solve(int test)
{
	// read
	int r, c, m;
	cin >> r >> c >> m;
	if (!need_to_run(test)) return;
	// solve
	if (m == 0)
	{
		vector< string > a(r, string(c, '.'));
		a[r - 1][c - 1] = 'c';
		cout << T(test) << endl;
		for (int i = 0; i < r; ++i)
			cout << a[i] << endl;
		return;
	}
	if ((r == 1 || c == 1) || (m + 1 == r * c))
	{
		vector< string > a(r, string(c, '.'));
		int rem = m;
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				if (rem > 0)
				{
					--rem;
					a[i][j] = '*';
				}
		a[r - 1][c - 1] = 'c';
		cout << T(test) << endl;
		for (int i = 0; i < r; ++i)
			cout << a[i] << endl;
		return;
	} else
	if (r * c < m + 4)
	{
		cout << T(test) << endl << "Impossible" << endl;
		return;
	}
	int rem = m;
	vector<string> a(r, string(c, '.'));
	int lx = -1, ly = -1;
	for (int i = 0; i < r - 2; ++i)
		for (int j = 0; j < c - 2; ++j)
			if (0 < rem)
			{
				--rem;
				a[i][j] = '*';
				lx = i;
				ly = j;
			}
	bool moved = false;
	if (rem % 2 != 0 && lx != -1)
	{
		a[lx][ly] = '.';
		++rem;
		moved = true;
	}
	int up = r - 2;
	if (moved)
		--up;
	for (int i = 0; i < up; ++i)
		for (int j = c - 2; j < c; ++j)
			if (0 < rem)
			{
				--rem;
				a[i][j] = '*';
			}
	for (int i = 0; i < c; ++i)
		for (int j = r - 2; j < r; ++j)
		{
			if (0 < rem)
			{
				--rem;
				a[j][i] = '*';
			}			
		}

	a[r - 1][c - 1] = 'c';
	vector< vector<int> > bad(r, vector<int>(c, 0));
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
		{
			for (int dx = -1; dx <= 1; ++dx)
				for (int dy = -1; dy <= 1; ++dy)
				{
					int nx = i + dx;
					int ny = j + dy;
					if (0 > nx || 0 > ny || nx >= r || ny >= c)
						continue;
					if (a[nx][ny] == '*')
						bad[i][j]++;
				}
		}
	queue<pii> q;
	vector<vector<int> > visited(r, vector<int>(c));
	visited[r - 1][c - 1] = true;
	if (!bad[r - 1][c - 1])
		q.push(mp(r - 1, c - 1));
	
	while (q.size())
	{
		int x = q.front().X, y = q.front().Y;
		q.pop();
		for (int dx = -1; dx <= 1; ++dx)
			for (int dy = -1; dy <= 1; ++dy)
			{
				int nx = x + dx;
				int ny = y + dy;
				if (0 > nx || 0 > ny || nx >= r || ny >= c)
					continue;
				if (!visited[nx][ny])
				{
					if (a[nx][ny] != '*')
						visited[nx][ny] = true;
					if (!bad[nx][ny])
						q.push(mp(nx, ny));
				}
			}		
	}
	int cnt = 0;
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j)
			cnt += visited[i][j];
	// cout << "reach: " << cnt << endl;
	// for (int i = 0; i < r; ++i)
	// {
	// 	for (int j = 0; j < c; ++j)
	// 		cout << visited[i][j];
	// 	cout << endl;
	// }
	if (cnt != r * c - m)
	{
		cout << T(test) << endl << "Impossible" << endl;
		return;
	}
	// write
	cout << T(test) << endl;
	for (int i = 0; i < r; ++i)
		cout << a[i] << endl;
}

int main(int argc, char *argv[])
{
	//freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
	//freopen(NAME ".in","r",stdin); freopen(NAME ".out","w",stdout);
	if (argc == 2) { _test_start = _test_end = from_str<int>(argv[1]); }
	if (argc == 3) { _test_start = from_str<int>(argv[1]); _test_end = from_str<int>(argv[2]); }

	clock_t tstart = clock();
	
	int tests;
	scanf("%d", &tests);
	for(int test = 1; test <= tests; ++test)
	{
		clock_t tprev = clock();
		solve(test);
		if (need_to_run(test))
			dbg("elapsed for #" << test << ": " << (clock() - tprev) / LD(CLOCKS_PER_SEC));
	}

	dbg("elapsed: " << (clock() - tstart) / LD(CLOCKS_PER_SEC));
	return 0;
}
/*************************
*************************/
#endif

