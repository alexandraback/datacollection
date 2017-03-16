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

int n, ans;
vector<string> a;
vector<bool> used;
string res;

bool good(string x) {
	int mi[26];
	int ma[26];
	int cnt[26] = {};
	for (int i = 0; i < 26; ++i) {
		mi[i] = Inf;
		ma[i] = -1;
	}
	for (int i = 0; i < x.size(); ++i) {
		int cur = x[i] - 'a';
		cnt[cur]++;
		mi[cur] = min(i, mi[cur]);
		ma[cur] = max(i, ma[cur]);
	}
	for (int i = 0; i < 26; ++i) {
		if (cnt[i] && cnt[i] != ma[i] - mi[i] + 1)
			return false;
	}
	return true;
}

void search(int x) {
	if (x == n) {
		ans += good(res);
		return;
	}
	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			used[i] = true;
			res += a[i];
			search(x + 1);
			res.erase(res.size() - a[i].size(), a[i].size());
			used[i] = false;
		}
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

		cin >> n;
		a.resize(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		used.assign(n, false);
		ans = 0;
		search(0);
		cout << ans << endl;
	}
	return 0;
}