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
#define dbg(x) //{cerr << #x << " = " << x << endl;}
#define dbgv(x) {cerr << #x << " ={"; for (int _i = 0; _i < x.size(); _i++) {if (_i) cerr << ", "; cerr << x[_i];} cerr << "}" << endl;}
#define NAME "problem"

string T(int test) { ostringstream os; os << "Case #" << test << ":"; return os.str(); }

int xabs(int a) { return a < 0 ? -a : +a; }

LD solve_small(int n, int sz, int x)
{
	dbg(x);
	vector<vector<LD> > d(sz + 1, vector<LD>(sz + 1));
	d[0][0] = 1.0;
	for(int i = 0; i <= sz; ++i)
		for(int j = 0; j <= sz; ++j) if(i < sz || j < sz)
		{
			if(i == sz)
				d[i][j + 1] += d[i][j];
			else if(j == sz)
				d[i + 1][j] += d[i][j];
			else
			{
				d[i + 1][j] += 0.5 * d[i][j];
				d[i][j + 1] += 0.5 * d[i][j];
			}				
		}
	LD sum = 0.0;
	for(int i = 0; i <= sz; ++i)
		for(int j = 0; j <= sz; ++j)
		{
			if(i + j == n && (i >= x))
			{
				dbg(i + j);
				dbg(i);
				dbg(j);
				dbg(d[i][j]);
				sum += d[i][j];
			}
		}

	return sum;
}

void solve(int test)
{
	cout.precision(10);
	cout.setf(ios::fixed);
	int n, x, y;
	cin >> n >> x >> y;

	int level = xabs(x) + y;
	int lblocks = level + 1;
	int sblocks = 2 * lblocks - 1;

	dbg(level);
	dbg(lblocks);
	dbg(sblocks);
	LL need = 0;
	for(int i = 0; i < level; i += 2)
	{
		need += 2 * (i + 1) - 1;
	}
	dbg(need);

	dbg(n);
	if(need >= n)
	{
		cout << T(test) << " " << 0.0 << endl;
		return;
	}

	n -= need;
	dbg(n);
	if(sblocks <= n)
	{
		cout << T(test) << " " << 1.0 << endl;
		return;
	}

	if(x == 0)
	{
		cout << T(test) << " " << 0.0 << endl;
		return;
	}

	dbg("solve small");

	LD res = solve_small(n, lblocks - 1, y + 1);
	cout << T(test) << " " << res << endl;	
}

int main()
{
	//freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
	//freopen(NAME ".in","r",stdin);freopen(NAME ".out","w",stdout);

	int tests;
	scanf("%d", &tests);
	for(int test = 1; test <= tests; ++test)
		solve(test);

	return 0;
}
/*************************
*************************/
#endif
