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

string T(int test) { ostringstream os; os << "Case #" << test << ":"; return os.str(); }

pair<LL, int> add(LL from, LL to)
{
	if(from == 1)
		return mp(from, inf);
	int cnt = 0;
	while(from <= to)
	{
		from += from - 1;
		++cnt;
	}
	return mp(from, cnt);
}

LL _solve(LL a, const vector<LL> &c)
{
	LL res = 0;
	for(int i = 0; i < c.size(); ++i)
	{
		pair<LL, int> cur = add(a, c[i]);
		res += cur.Y;
		a = cur.X;
		a += c[i];
	}
	return res;
}

void solve(int test)
{
	LL a;
	int n;
	cin >> a >> n;

	vector<LL> p(n);
	for(int i = 0; i < n; ++i)
		cin >> p[i];

	sort(p.begin(), p.end());

	LL best = inf64;
	for(int rem = 0; rem <= p.size(); ++rem)
	{
		
		vector<LL> c;
		for(int j = 0; j < p.size() - rem; ++j)
			c.push_back(p[j]);

		LL cur = _solve(a, c) + rem;
		best = min(best, cur);
	}
	cout << T(test) << " " << best << endl;
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
