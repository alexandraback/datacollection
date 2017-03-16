// Smile please :)

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cassert>
#include <cctype>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <iomanip>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <climits>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#undef KVARK

#ifdef KVARK
	#include "../h/debug.h"
#else
#define dbg(...) (void(1));
#define dbg2(...) (void(1));
#define dbg3(...) (void(1));
#define dbg4(...) (void(1));
#define dbg5(...) (void(1));
#define dbgp(...) (void(1));
#define dbg_arr(...) (void(1));
#define dbg_vec(...) (void(1));
#endif

typedef pair<int, int> pii;
typedef pair<unsigned long long, unsigned long long> pll;
typedef pair<double, int> pdi;
typedef vector<int> vi;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vector<int> > vvi;
typedef vector<vector<pii> > vvpii;
typedef vector<vector<long long> > vvl;
typedef vector<long long> vl;
typedef long long int llint;

#define ALL(v) (v.begin()), (v.end())
#define SZ(v) ((int)((v).size()))
#define endl "\n"

void task();

int main(){
#ifdef KVARK
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#else
	freopen("src/gcj_input.txt", "r", stdin);
	freopen("src/gcj_output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	srand(time(0));
#endif
//	ios_base::sync_with_stdio(0);

	int t;
	scanf("%d\n", &t);
	for (int i = 0; i < t; ++i) {
		printf("Case #%d: ", i+1);
		task();
		printf("\n");
	}

#ifdef KVARK_DEBUG
//	my_debug::printProcessInfo();
#endif
	return 0;
}
const int INF = 0x3f3f3f3f;
const int N = 3e5+10;
const int M = 3e5+10;

string a;
string b;
string s;
string _s;
int ansAbs = 1e9;
int sum = 1e9;
int j = 1e9;
string ans;

void solve(int i) {
	if (i == s.length()) {
		int a = 0;
		int b = 0;
		for (int i = 0; i < s.length() / 2; ++i)
			a *= 10, a += s[i] - '0';
		for (int i = s.length() / 2; i < s.length(); ++i)
			b *= 10, b += s[i] - '0';
		if (abs(a - b) < ansAbs) {
			ansAbs = abs(a-b);
			ans = s.substr(0, s.length() / 2) + " " + s.substr(s.length() / 2);
			sum = a + b;
			j = b;
		}
		if (abs(a - b) == ansAbs && a + b < sum) {
			ansAbs = abs(a-b);
			ans = s.substr(0, s.length() / 2) + " " + s.substr(s.length() / 2);
			sum = a + b;
			j = b;
		}
		if (abs(a - b) == ansAbs && a + b == sum && b < j) {
			ansAbs = abs(a-b);
			ans = s.substr(0, s.length() / 2) + " " + s.substr(s.length() / 2);
			sum = a + b;
			j = b;
		}
		return;
	}
	if (_s[i] != '?') {
		s[i] = _s[i];
		solve(i+1);
		return;
	}
	for (int j = 0; j < 10; ++j) {
		s[i] = j + '0';
		solve(i+1);
	}
}

string solve_clever(string a, string b, int k) {
	int cmp = 0;
	int n = a.size();
	for (int i = 0; i < n; ++i) {
		if (cmp == 0) {
			if (i == k) {
				if (a[i] == '?' && b[i] == '?') {
					a[i] = '0';
					b[i] = '1';
				}
				if (a[i] == '?' && b[i] != '0')
					a[i] = b[i] - 1;
				if (b[i] == '?' && a[i] != '9')
					b[i] = a[i] + 1;
			}
			if (a[i] == '?' && b[i] == '?') {
				a[i] = '0';
				b[i] = '0';
				continue;
			}
			if (a[i] != '?' && b[i] != '?') {
				if (a[i] < b[i])
					cmp = -1;
				else if (b[i] < a[i])
					cmp = 1;
				continue;
			}
			if (a[i] == '?')
				a[i] = b[i];
			else if (b[i] == '?')
				b[i] = a[i];
			continue;
		}
		if (cmp == -1) {
			if (a[i] == '?')
				a[i] = '9';
			if (b[i] == '?')
				b[i] = '0';
			continue;
		}
		if (cmp == 1) {
			if (a[i] == '?')
				a[i] = '0';
			if (b[i] == '?')
				b[i] = '9';
			continue;
		}
	}
	return a + " " + b;
}

string solve_clever2(string a, string b, int k) {
	int cmp = 0;
	int n = a.size();
	for (int i = 0; i < n; ++i) {
		if (cmp == 0) {
			if (i == k) {
				if (a[i] == '?' && b[i] == '?') {
					a[i] = '1';
					b[i] = '0';
				}
				if (a[i] == '?' && b[i] != '9')
					a[i] = b[i] + 1;
				if (b[i] == '?' && a[i] != '0')
					b[i] = a[i] - 1;
			}
			if (a[i] == '?' && b[i] == '?') {
				a[i] = '0';
				b[i] = '0';
				continue;
			}
			if (a[i] != '?' && b[i] != '?') {
				if (a[i] < b[i])
					cmp = -1;
				else if (b[i] < a[i])
					cmp = 1;
				continue;
			}
			if (a[i] == '?')
				a[i] = b[i];
			else if (b[i] == '?')
				b[i] = a[i];
			continue;
		}
		if (cmp == -1) {
			if (a[i] == '?')
				a[i] = '9';
			if (b[i] == '?')
				b[i] = '0';
			continue;
		}
		if (cmp == 1) {
			if (a[i] == '?')
				a[i] = '0';
			if (b[i] == '?')
				b[i] = '9';
			continue;
		}
	}
	return a + " " + b;
}

unsigned long long _f(string s) {
	unsigned long long r = 0;
	for (char c: s) {
		r *= 10;
		r += c - '0';
	}
	return r;
}

pll getP(string a) {
	string f = a.substr(0, a.size() / 2);
	string s = a.substr(a.size() / 2 + 1, a.size() / 2);
	return pll{_f(f), _f(s)};
}

string getMin(string a, string b) {
	if (a == "")
		return b;
	if (b == "")
		return a;
	pll p1 = getP(a);
	pll p2 = getP(b);
	unsigned long long abs1 = p1.first < p1.second ? p1.second - p1.first : p1.first - p1.second;
	unsigned long long abs2 = p2.first < p2.second ? p2.second - p2.first : p2.first - p2.second;
	if (abs1 < abs2)
		return a;
	if (abs2 < abs1)
		return b;
	if (p1.first + p1.second < p2.first + p2.second)
		return a;
	if (p2.first + p2.second < p1.first + p1.second)
		return b;
	if (p1.second < p2.second)
		return a;
	return b;
}

string solve2(string a, string b) {
	string ans = "";
	for (int i = 0; i <= a.size(); ++i) {
		string x = solve_clever(a, b, i);
		ans = getMin(ans, x);
	}
	for (int i = 0; i <= a.size(); ++i) {
		string x = solve_clever2(a, b, i);
		ans = getMin(ans, x);
	}
	return ans;
}

void task(){
	ansAbs = 1e9;
	sum = 1e9;
	j = 1e9;
	cin >> a >> b;
	s = a + b;
	_s = a + b;
	cout << solve2(a, b);
}
