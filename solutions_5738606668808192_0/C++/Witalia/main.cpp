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

typedef double ld;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;

const int mx[4] = { 1, 0, -1, 0 };
const int my[4] = { 0, 1, 0, -1 };

const int Inf = 1000000000;
const int Mi = 1000000007;
const int N = 50005;
const int K = 20;
const ld eps = 10e-8;
const ld PI = 2 * acos(0.0);
const ll InfLL = ll(Inf) * ll(Inf);

unsigned rand16() { return rand() % (1 << 16); }
unsigned rand32() { return (rand16() << 16) + rand16(); }
ull rand64() { return (((ull)rand32()) << 32) + rand32(); }
int rand(int L, int R) { if (L > R) return R; return rand32() % (R - L + 1) + L; }
ld random(ld L, ld R) { return rand(ceil((L - eps) * 100), floor((R + eps) * 100)) / 100.0; }

ll Abs(ll a) { return a < 0 ? -a : a; }
ll sqr(ll a) { return a*a; }
ll gcd(ll a, ll b) { return !b ? a : gcd(b, a % b); }

string toStr(int n) {
	char s[100];
	sprintf(s, "%d", n);
	return string(s);
}

ll nums[11];
int n = 16, target = 50, cnt = 0;
vector<int> st;
vector<pair<string, vector<int>>> ans;

ll poww(ll a, ll k) {
	ll res = 1;
	while (k) {
		if (k & 1) res = res * a;
		a = a * a;
		k >>= 1;
	}
	return res;
}

int is_prime(ll a) {
	int x = sqrt(a) + 1;
	for (int i = 2; i < sqrt(a) && i <= 100; ++i) {
		if (a % i == 0) {
			return i;
		}
	}
	return 1;
}

void gen(int ps = 1) {
	if (cnt >= target) {
		return;
	}
	if (ps == n - 1) {
		vector<int> divs;
		bool fl = false;
		for (int i = 2; i <= 10; ++i) {
			divs.push_back(is_prime(nums[i]));
			fl |= divs.back() == 1;
		}
		cnt += !fl;
		if (!fl) {
			string s = "1";
			for (int i = n - 2; i > 0; --i)
				s += st[i - 1] ? "1" : "0";
			s += "1";
			ans.push_back(make_pair(s, divs));
		}
		return;
	}
	for (int x = 0; x < 2; ++x) {
		st.push_back(x);
		for (int i = 2; x && i <= 10; ++i) {
			nums[i] += poww(i, ps);
		}
		gen(ps + 1);
		st.pop_back();
		for (int i = 2; x && i <= 10; ++i) {
			nums[i] -= poww(i, ps);
		}
	}
}

//#define ONLINE_JUDGE
int main() {
	std::ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cout << "Case #1:" << endl;
	for (int i = 2; i <= 10; ++i) {
		nums[i] = 1 + poww(i, n - 1);
	}
	gen();
	for (int i = 0; i < target; ++i) {
		cout << ans[i].first;
		for (int j = 0; j < ans[i].second.size(); ++j) {
			cout << " " << ans[i].second[j];
		}
		cout << endl;
	}
	/*int t;
	cin >> t;
	for (int _t = 0; _t < t; ++_t) {
		cout << "Case #" << (_t + 1) << ": ";
		
	}*/
	return 0;
}
