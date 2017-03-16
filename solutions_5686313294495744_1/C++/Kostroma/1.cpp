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

//#define int li

//const int mod = 1000000007;

vector<vector<int>> g;
vector<int> mt;
vector<char> used;

bool dfs(int v) {
	if (used[v]) {
		return false;
	}
	used[v] = true;
	for (int to : g[v]) {
		if (mt[to] == -1 || dfs(mt[to])) {
			mt[to] = v;
			return true;
		}
	}
	return false;
}

void solve() {
	int n;
	cin >> n;
	vector<vector<string>> s(n, vector<string>(2));
	vector<vector<string>> all_s(2);
	for (int i = 0; i < n; ++i) {
		cin >> s[i][0] >> s[i][1];
		for (int j = 0; j < 2; ++j) {
			all_s[j].push_back(s[i][j]);
		}
	}
	for (int i = 0; i < 2; ++i) {
		sort(all(all_s[i]));
		all_s[i].erase(unique(all(all_s[i])), all_s[i].end());
	}
	g.clear();
	g.resize(all_s[0].size());
	mt.assign(all_s[1].size(), -1);
	for (int i = 0; i < n; ++i) {
		int id[2];
		for (int j = 0; j < 2; ++j) {
			id[j] = lower_bound(all(all_s[j]), s[i][j]) - all_s[j].begin();
			assert(all_s[j][id[j]] == s[i][j]);
		}
		g[id[0]].push_back(id[1]);
	}

	int res = all_s[0].size() + all_s[1].size();
	for (int i = 0; i < all_s[0].size(); ++i) {
		used.assign(all_s[0].size(), false);
		if (dfs(i)) {
			--res;
		}
	}
	res = n - res;
	cout << res << "\n";
}



