#pragma comment(linker, "/STACK:512000000")
#define _CRT_SECURE_NO_WARNINGS
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
#include <deque>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
//#include <unordered_map>
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

int testNumber = 1;

bool todo = true;

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
	start = clock();
	int t = 1;
	cout.sync_with_stdio(0);
	cin.tie(0);
	precalc();
	cout.precision(10);
	cout << fixed;
	cin >> t;
	int testNum = 1;
	while (t--) {
		//cerr << testNum << endl;
		cout << "Case #" << testNum++ << ": ";
		solve();
		++testNumber;
		//++timer;
	}

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

	return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

/*int pr[] = { 97, 2011 };
int mods[] = { 1000000007, 1000000009 };

const int C = 300500;
int powers[2][C];*/

//int MOD = 1000000007;

//int c[5010][5010];

template<typename T>
T binpow(T q, T w, T mod) {
	if (!w)
		return 1 % mod;
	if (w & 1)
		return q * 1LL * binpow(q, w - 1, mod) % mod;
	return binpow(q * 1LL * q % mod, w / 2, mod);
}

/*int curMod = 1000000009;

int fact[100500], revfact[100500];

int getC(int n, int k) {
int res = fact[n] * revfact[n - k] % curMod * revfact[k] % curMod;
return res;
}*/

/*const int C = 7000500;

int least_prime[C];*/

void precalc() {

	/*for (int i = 2; i < C; ++i) {
	if (!least_prime[i]) {
	least_prime[i] = i;
	for (li j = i * 1LL * i; j < C; j += i) {
	least_prime[j] = i;
	}
	}
	}*/

	/*fact[0] = revfact[0] = 1;
	for (int i = 1; i < 100500; ++i) {
	fact[i] = fact[i - 1] * i % curMod;
	revfact[i] = binpow(fact[i], curMod - 2, curMod);
	}*/

	/*for (int w = 0; w < 2; ++w) {
	powers[w][0] = 1;
	for (int j = 1; j < C; ++j) {
	powers[w][j] = (powers[w][j - 1] * 1LL * pr[w]) % mods[w];
	}
	}*/
	/*for (int i = 0; i < 5010; ++i) {
	c[i][i] = c[i][0] = 1;
	for (int j = 1; j < i; ++j) {
	c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	}
	}*/
}

template<typename T>
T gcd(T q, T w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}
template<typename T>
T lcm(T q, T w) {
	return q / gcd(q, w) * w;
}

#define int li

//const int mod = 1000000007;

int best_c = 0, best_j = 2e18;

void update_ans(vector<vector<int>>& a, bool inverted) {
	vector<int> num(2);
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < a[i].size(); ++j) {
			num[i] = num[i] * 10 + a[i][j];
		}
	}
	if (inverted) {
		swap(num[0], num[1]);
	}
	int cur_diff = abs(num[0] - num[1]);
	if (cur_diff > abs(best_c - best_j)) {
		return;
	}
	if (cur_diff < abs(best_c - best_j)) {
		best_c = num[0];
		best_j = num[1];
		return;
	}
	if (best_c < num[0]) {
		return;
	}
	if (best_c > num[0]) {
		best_c = num[0];
		best_j = num[1];
		return;
	}
	if (best_j > num[1]) {
		best_j = num[1];
		return;
	}
}

void update_ans(int c, int j, bool inverted) {
	vector<int> num(2);
	num[0] = c;
	num[1] = j;
	int cur_diff = abs(num[0] - num[1]);
	if (cur_diff > abs(best_c - best_j)) {
		return;
	}
	if (cur_diff < abs(best_c - best_j)) {
		best_c = num[0];
		best_j = num[1];
		return;
	}
	if (best_c < num[0]) {
		return;
	}
	if (best_c > num[0]) {
		best_c = num[0];
		best_j = num[1];
		return;
	}
	if (best_j > num[1]) {
		best_j = num[1];
		return;
	}
}

void output(int num, int n) {
	vector<int> res;
	for (int i = 0; i < n; ++i) {
		res.push_back(num % 10);
		num /= 10;
	}
	reverse(all(res));
	for (int c : res) {
		cout << c;
	}
}

void fill_rest(vector<vector<int>>& b) {
	for (int i = 0; i < b[0].size(); ++i) {
		if (b[0][i] == -1 && b[1][i] == -1) {
			b[0][i] = b[1][i] = 0;
			continue;
		}
		if (b[0][i] == -1) {
			b[0][i] = b[1][i];
			continue;
		}
		if (b[1][i] == -1) {
			b[1][i] = b[0][i];
			continue;
		}
	}
}

bool check(int n, vector<int>& a) {
	for (int i = a.size() - 1; i >= 0; --i) {
		if (a[i] != -1 && a[i] != n % 10) {
			return false;
		}
		n /= 10;
	}
	return true;
}

void solve() {
	best_c = 0; best_j = 2e18;
	vector<string> s(2);
	cin >> s[0] >> s[1];
	vector<vector<int>> a(2, vector<int>(s[0].length()));
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < s[i].length(); ++j) {
			if (s[i][j] == '?') {
				a[i][j] = -1;
			}
			else {
				a[i][j] = s[i][j] - '0';
			}
		}
	}
	int n = a[0].size();
	int diff = 0;
	int step = 1;
	for (int i = n - 1; i >= 0; --i) {
		if (a[0][i] != -1 && a[1][i] != -1) {
			diff += (a[1][i] - a[0][i]) * step;
		}
		step *= 10;
	}

	for (int c = 0; c < step; ++c) {
		if (!check(c, a[0])) {
			continue;
		}
		for (int j = 0; j < step; ++j) {
			if (!check(j, a[1])) {
				continue;
			}
			update_ans(c, j, false);
		}
	}

	output(best_c, n);
	cout << ' ';
	output(best_j, n);
	cout << "\n";
	return;

	bool inverted = false;
	if (diff < 0) {
		inverted = true;
		a[0].swap(a[1]);
		diff = -diff;
	}

	step = 1;
	for (int i = 0; i < n; ++i) {
		step *= 10;
	}

	vector<vector<int>> dp(n + 1, vector<int>(2));
	vector<vector<vector<int>>> pred(n + 1, vector<vector<int>>(2, vector<int>(2)));

	for (int i = 0; i < n; ++i) {
		step /= 10;
		if (a[0][i] != -1 && a[1][i] != -1) {
			continue;
		}
		int max_rest = diff / step;
		int enough = (diff - 1) / step + 1;
		if (diff == 0) {
			enough = 0;
		}
		if (a[0][i] == -1 && a[1][i] == -1) {
			auto b = a;
			b[0][i] = min(enough, 9LL);
			b[1][i] = 0;
			fill_rest(b);
			update_ans(b, inverted);

			b = a;
			b[0][i] = min(max_rest, 9LL);
			b[1][i] = 0;
			diff -= (b[0][i] - b[1][i]) * step;
			a.swap(b);
			continue;
		}

		if (a[0][i] == -1) {
			auto b = a;
			b[0][i] = min(enough + b[1][i], 9LL);
			fill_rest(b);
			update_ans(b, inverted);

			b = a;
			b[0][i] = min(max_rest + b[1][i], 9LL);
			diff -= (b[0][i] - b[1][i]) * step;
			a.swap(b);
			continue;
		}

		if (a[1][i] == -1) {
			auto b = a;
			b[1][i] = max(b[0][i] - enough, 0LL);
			fill_rest(b);
			update_ans(b, inverted);

			b = a;
			b[1][i] = max(b[0][i] - max_rest, 0LL);
			diff -= (b[0][i] - b[1][i]) * step;
			a.swap(b);
			continue;
		}
	}

	update_ans(a, inverted);

	output(best_c, n);
	cout << ' ';
	output(best_j, n);
	cout << "\n";

}



