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
#define dbg(x) //{cerr << #x << " = " << x << endl;}
#define dbgv(x) //{cerr << #x << " ={"; for (int _i = 0; _i < x.size(); _i++) {if (_i) cerr << ", "; cerr << x[_i];} cerr << "}" << endl;}
#define NAME "problem"

template<class T> string to_str(const T &a) { oss os; os << a; return os.str(); }
template<> string to_str<LD>(const LD& a) { oss os; os.precision(10); os.setf(ios::fixed); os << a; return os.str(); }
template<class T> T from_str(const string &s) { iss is(s); T val; is >> val; return val; }
string T(int test) { ostringstream os; os << "Case #" << test << ":"; return os.str(); }
int _test_start = -1, _test_end = -1;
bool need_to_run(int test) { return _test_start == -1 || (_test_start <= test && test <= _test_end); }

string rev(string s) {
	reverse(s.begin(), s.end());
	return s;
}

LL ipow(LL a, LL n) {
	if (n == 0) return 1;
	LL r = ipow(a, n >> 1);
	r *= r;
	if (n & 1) {
		r *= a;
	}
	return r;
}

// 10000 .. 99999
LL get10(int num) {
	if (num == 1) {
		return 9;
	}
	LL res = 0;
	res += 1;
	res += 9;
	res++;

	// half of 999
	res += (ipow(10, (num + 1) / 2) - 1) - 1;
	// another halfs
	res += (ipow(10, num / 2) - 1) - 9;
	return res;
}
LL brute(int n) {
	vector<int> dp(n + 1, inf);
	dp[1] = 1;
	dp[0] = 1;

	for (int i = 2; i <= n; ++i) {
		
		dp[i] = dp[i - 1] + 1;
		auto si = to_str(i);
		auto t = rev(si);
		if (t[0] == '0' || t == si) {
			continue;
		}
		auto ti = from_str<int>(t);
		dbg(ti);
		if (ti >= i) {
			continue;
		}
		dp[i] = min(dp[i], dp[from_str<int>(t)] + 1);
	}
	dbgv(dp);
	return dp.back();
}
void solve(int test) {
	// read
	LL n;
	cin >> n;

	if (!need_to_run(test)) return;
	// solve
	LL res = 0;
	
	LL add = 0;
	if (n % 10 == 0) {
		--n;
		++add;
	}

	string s = to_str(n);
	if (s.size() == 1) {
		res += s[0] - '0';
	} else {
//		res += 9;
//		res += (s.size() - 2) * 19;
		for (int i = 1; i < s.size(); ++i) {
			res += get10(i);
		}
		// 999999...999
		res++;
		dbg(res);
//		res++;
		// 100000...0000
		LL p10 = 1;
		while (p10 <= n) {
			p10 *= 10;
		}
		p10 /= 10;
		LL add2 = n - p10;
		dbg(p10);
		dbg(add2);
				
		for (int i = 1; i <= s.size(); ++i) {
			dbg(i);
			auto t = rev(s.substr(0, i));
			if (t.size() < s.size()) {
				t = "1" + string(s.size() - t.size() - 1, '0') + t;
			}
			dbg(t);
			LL ti = from_str<LL>(t);
			dbg(ti);
			LL cur = ti - p10 + 1;
			t = rev(t);
			LL cn = from_str<LL>(t);
			cur += n - cn;
			dbg(cn);
			add2 = min(add2, cur);

		}

		res += add2;
		
	}
	
	// write
	cout << T(test) << " " << res + add << endl;// << " " << brute(n + add) << endl;
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
