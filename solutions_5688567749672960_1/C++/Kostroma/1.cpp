#pragma comment (linker, "/STACK:128000000")
//#include "testlib.h"
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
//#include <unordered_map>
//#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve();
void precalc();
clock_t start;
//int timer = 1;

bool doing = true;

int main() {
#ifdef room111
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(FILENAME".in", "r", stdin);
	//freopen(FILENAME ".out", "w", stdout);
#endif
	int t = 1;
	cout.sync_with_stdio(0);
	cin.tie(0);
	precalc();
	cout.precision(10);
	cout << fixed;
	cin >> t;
	start = clock();
	int testNum = 1;
	while (t--) {
		cout << "Case #" << testNum++ << ": ";
		solve();
		//++timer;
	}

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

	return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

void precalc() {
}

int binpow(int q, int w, int mod) {
	if (!w)
		return 1;
	if (w & 1)
		return q * binpow(q, w - 1, mod) % mod;
	return binpow(q * q % mod, w / 2, mod);
}

int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

#define int li

int rev(int cur) {
	vector<int> now;
	while (cur) {
		now.push_back(cur % 10);
		cur /= 10;
	}
	cur = 0;
	for (int i = 0; i < now.size(); ++i) {
		cur = cur * 10 + now[i];
	}
	return cur;
}

map<int, int> dp;

int getInt(vector<int>& cur) {
	int res = 0;
	for (int i = (int)cur.size() - 1; i >= 0; --i) {
		res = res * 10 + cur[i];
	}
	return res;
}

vector<int> can;

int solve(int n) {
	if (n < can.size()) {
		return can[n];
	}
	if (dp.count(n)) {
		return dp[n];
	}
	if (!n) {
		return dp[n] = 0;
	}
	if (n % 10 == 0) {
		return dp[n] = solve(n - 1) + 1;
	}
	int res = n;
	vector<int> now;
	int k = n;
	while (k) {
		now.push_back(k % 10);
		k /= 10;
	}
	int step = 1;
	int sum = 0;
	int last = 0;
	auto curcur = now;
	for (int i = 0; i < now.size(); ++i) {
		sum += step * (now[i] - (i == 0));
		last = now[i];
		now[i] = (i == 0);
		step *= 10;
		int nex = getInt(now);
		//cerr << "look " << n << ' ' << nex << ' ' << rev(nex) << "\n";
		if (nex <= n && rev(nex) < n) {
			res = min(res, sum + 1 + solve(rev(nex)));
		}
	}

	int nex = step / 10 - 1;
	res = min(res, n - nex + solve(nex));

	//cerr << n << ' ' << res << "\n";
	return dp[n] = res;
}

void solve() {
	if (can.empty()) {
		int n = 1000000;
		can.assign(n + 1, 1e9);
		can[0] = 0;
		for (int i = 0; i < n; ++i) {
			can[i + 1] = min(can[i + 1], can[i] + 1);
			int cur = rev(i);
			if (cur <= n) {
				can[cur] = min(can[cur], can[i] + 1);
			}
		}

	}


	int n;
	cin >> n;
	//n = 100000000000000LL - rand();

	int res = solve(n);

	cout << res << "\n";

}


