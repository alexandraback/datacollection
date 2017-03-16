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

vector<LD> a, b;
int n;


// const int maxn = 1001;
// int dp[maxn][maxn];
// int go(int l, int r)
// {
// 	if (l + r >= n)
// 		return 0;
// 	int &res = dp[l][r];
// 	if (res != -1)
// 		return res;
// 	int r1 = go(l + 1, r);
// 	if (a[l] > b[l])
// 		r1++;
	
// 	int r2 = go(l, r + 1);
// 	if (a[n - r - 1] > b[l])
// 		r2++;
// 	res = max(r1, r2);
// 	return res;
// }

int get_dwar()
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	int res = 0;
	int pos = 0;
	for (int i = 0; i < a.size(); ++i)
	{
		while (pos < n && a[pos] < b[i]) ++pos;
		if (pos < n)
			res++;
		pos++;
	}
	return res;
		
	// // memset(dp, -1, sizeof dp);
	// // pii res = go(0, n - 1);
	// int res = 0;
	// // res.X = go(0, 0);
	// vector<int> used_a(n), used_b(n);
	// for (int it = 0; it < n; ++it))
	// {
	// 	int big_a = n - 1;
	// 	while (used_a[big_a]) --big_a;
	// 	int big_b = 0;
	// 	while (used_b[pos_b]) ++big_b;
	// 	int small_a = 0;
	// 	while (used_a[small_a]) ++small_a;
	// 	int small_b = n - 1;
	// 	while (used_b[small_b]) --small_b;
	// 	if (a[big_a] > b[big_b])
	// 	{
	// 		int small_a = 0;
	// 		while (a[small_
	// 	}
		
		
	// }
	// return res;
}

int get_war()
{
	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());
	int res = 0;
	vector<int> used(n);
	for (int i = 0; i < n; ++i)
	{
		bool bigger = true;
		for (int j = 0; j < n; ++j)
			if (!used[j] && b[j] > a[i])
			{
				bigger = false;
				break;
			}
		if (bigger)
		{
			res++;
			int pos = n - 1;
			while (used[pos]) --pos;
			used[pos] = true;
		} else
		{
			int pos = n - 1;
			while (b[pos] < a[i] || used[pos]) --pos;
			used[pos] = true;
		}
	}
	return res;
}


void solve(int test)
{
	// read
	cin >> n;
	a.resize(n);
	b.resize(n);
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < n; ++i)
		cin >> b[i];
	if (!need_to_run(test)) return;
	// solve
	pii res;
	res.X = get_dwar();
	res.Y = get_war();
	
	// write
	cout << T(test) << " " << res.X << " " << res.Y << endl;
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

