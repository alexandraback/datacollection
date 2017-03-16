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
bool need_to_run(int test) { return _test_start == -1 || (_test_start <= test && test <= _test_end); }

LL encounters(int p1, int t1, int p2, int t2) {
	return 0;
		
}

void solve(int test) {
	// read
	int n;
	scanf("%d", &n);

	vector<pii> hikers;
	for (int i = 0; i < n; ++i) {
		int degree, num, time;
		scanf("%d%d%d", &degree, &num, &time);
		for (int j = 0; j < num; ++j) {
			hikers.pb(mp(degree, time + j));
		}
	}

	if (!need_to_run(test)) return;
	// solve
	set<int> speeds;
	for (auto h : hikers) {
		speeds.insert(h.Y);
	}
	LL res = inf64;
	if (speeds.size() == 1) {
		res = 0;
	} else if (n == 1) {
		res = 1;
	} else if (hikers.size() == 2) {
		res = 1;
	} else
	for (const auto& hiker : hikers) {
		LL cur = 0;
		int p1 = 0;
		int t1 = hiker.Y;
		for (const auto& hiker : hikers) {
			cur += encounters(p1, t1, hiker.X, hiker.Y);
		}
		res = min(res, cur);
	}

	// write
	cout << T(test) << " " << res << endl;
}

int main(int argc, char *argv[]) {
	//freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
	//freopen(NAME ".in","r",stdin); freopen(NAME ".out","w",stdout);
	if (argc == 2) { _test_start = _test_end = from_str<int>(argv[1]); }
	if (argc == 3) { _test_start = from_str<int>(argv[1]); _test_end = from_str<int>(argv[2]); }

	clock_t tstart = clock();
	
	int tests;
	scanf("%d", &tests);
	for(int test = 1; test <= tests; ++test) {
		clock_t tprev = clock();
		solve(test);
		if (need_to_run(test)) {
		//	dbg("elapsed for #" << test << ": " << (clock() - tprev) / LD(CLOCKS_PER_SEC));
		}
	}

	dbg("elapsed: " << (clock() - tstart) / LD(CLOCKS_PER_SEC));
	return 0;
}
/*************************
*************************/
#endif
