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

ll fact[K];

void calc_fact() {
	fact[0] = 1;
	for (int i = 1; i < K; ++i) {
		fact[i] = (fact[i - 1] * i) % MOD;
	}
}

int n, ans;
vector<string> a;

string zip(string x) {
	string res = "";
	for (int i = 0; i < x.size(); ++i) {
		if (i == x.size() - 1 || x[i] != x[i + 1])
			res += x[i];
	}
	return res;
}

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

multiset<pair<string, ll>> zip(vector<string> a) {
	sort(a.begin(), a.end());
	multiset<pair<string, ll>> res;
	int cnt = 0;
	for (int i = 0; i < a.size(); ++i) {
		if (i == 0 || (a[i] == a[i - 1] && a[i].size() == 1))
			cnt++;
		if (i == a.size() - 1 || a[i + 1] != a[i] || a[i].size() != 1) {
			res.insert(make_pair(a[i], fact[cnt]));
			cnt = 1;
		}
	}
	return res;
}

auto zip(multiset<pair<string, ll>> x) -> decltype(x) {
	for (int t = 0; t < K; ++t) {
		bool fl = true;
		for (auto it1 = x.begin(); it1 != x.end() && fl; ++it1) {
			for (auto it2 = x.begin(); it2 != x.end() && fl; ++it2) {
				if (it1 != it2 && it1->first.back() == it2->first[0]) {
					string cur = it1->first + it2->first;
					ll cn = (it1->second * it2->second) % MOD;
					x.erase(it1);
					x.erase(it2);
					x.insert(make_pair(cur, cn));
					fl = false;
				}
			}
		}
	}
	return x;
}

bool check(multiset<pair<string, ll>> x) {
	for (char i = 'a'; i <= 'z'; ++i) {
		int cnt = 0;
		for (auto j : x) {
			if (j.first.find(i) != -1)
				++cnt;
		}
		if (cnt > 1)
			return false;
	}
	return true;
}

//#define ONLINE_JUDGE
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	calc_fact();

	int T;
	cin >> T;
	for (int t = 0; t < T; ++t) {
		cout << "Case #" << t + 1 << ": ";

		cin >> n;
		a.resize(n);
		for (int i = 0; i < n; ++i) {
			cin >> a[i];
			a[i] = zip(a[i]);
		}
		
		auto b = zip(a);
		/*if (t == 38) {
			cout << n << endl;
			for (auto i : b)
				cout << "(" << i.first << ", " << i.second << ") ";
			cout << endl;
		}*/
		b = zip(b);
		/*if (t == 38) {
			cout << n << endl;
			for (auto i : b)
				cout << "(" << i.first << ", " << i.second << ") ";
			cout << endl;
		}*/
		ll ans = fact[b.size()] * check(b);
		for (auto x : b) {
			ans = (ans * x.second) % MOD;
			ans *= good(x.first);
		}
		cout << ans << endl;
	}
	return 0;
}