#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <memory.h>
#include <map>
#define _USE_MATH_DEFINES
#include <math.h>
#include <list>
#include <fstream>
#include <time.h>
#include <iomanip>
#include <queue>
#include <stack>
#include <complex>
#include <limits.h>

#define Cpp11
#ifdef Cpp11
#include <cassert>
#include <chrono>
#include <regex>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <valarray>
using namespace std::chrono;
#endif
using namespace std;

typedef long long ll;

const int N = 1001;
const int K = 105;
const int Inf = 1000000000;
const ll InfL = 1000000000000000000LL;
const int MOD = 1000000007;

ll Abs(ll a) { return a < 0 ? -a : a; }
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }

//int mx[] = { 1, 1, 2,2, -1, -1, -2, -2 };
//int my[] = { 2, -2, 1, -1, 2, -2, 1, -1 };

int mx[] = { 1, -1, 0, 0 };
int my[] = { 0, 0, -1, 1 };

vector<vector<int>> a;
int ans, cnt;
int n, m, c;

bool good(int i, int j) {
	return i >= 0 && j >= 0 && i < n && j < m;
}

void dfs(int i, int j) {
	if (a[i][j] != 0)
		return;
	++cnt;
	a[i][j] = -1;
	for (int k = 0; k < 4; ++k) {
		if (good(i + mx[k], j + my[k])) {
			dfs(i + mx[k], j + my[k]);
		}
	}
}

int count() {
	cnt = 0;
	for (int i = 0; i < n; ++i) {
		dfs(i, 0);
		dfs(i, m - 1);
	}
	for (int j = 0; j < m; ++j) {
		dfs(0, j);
		dfs(n - 1, j);
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			a[i][j] = max(0, a[i][j]);
		}
	}
	return n * m - cnt;
}

void search(int i, int j, int cur = 0) {
	if (cur >= ans)
		return;
	if (i == n) {
		if (count() >= c)
			ans = min(ans, cur);
		return;
	}
	for (int k = 0; k < 2; ++k) {
		a[i][j] = k;
		search(i + (j + 1) / m, (j + 1) % m, cur + k);
	}
}

//#define ONLINE_JUDGE
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cout << "Case #" << t + 1 << ": ";

		cin >> n >> m >> c;
		a.resize(n);
		for (auto &i : a)
			i.assign(m, 0);
		ans = Inf;
		search(0, 0);
		cout << ans << endl;
	}
	return 0;
}