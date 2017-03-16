#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <complex>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <gmpxx.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)

template<typename T> inline void ignore(T) {
}

string solve(const string &s) {
	int num[26];
	forn(i, 26) { num[i] = 0; }
	for (char c : s) {
		num[c - 'A']++;
	}
	int cnt[10];
	forn(i, 10) { cnt[i] = 0; }
	string digits[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR",
		"FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
	vector<pair<char, int> > keys;
	keys.emplace_back('Z', 0);
	keys.emplace_back('X', 6);
	keys.emplace_back('G', 8);
	keys.emplace_back('W', 2);
	keys.emplace_back('T', 3);
	keys.emplace_back('U', 4);
	keys.emplace_back('F', 5);
	keys.emplace_back('V', 7);
	keys.emplace_back('I', 9);
	keys.emplace_back('N', 1);
	for (auto kv : keys) {
		char c = kv.first;
		int i = kv.second;
		int k = cnt[i] += num[c - 'A'];
		for (char d : digits[i]) {
			num[d - 'A'] -= k;
		}
	}
	string ans;
	forn(i, 10) {
		forn(j, cnt[i]) {
			ans.push_back('0' + i);
		}
	}
	return ans;
}

int main(void) {
	int t; cin >> t;
	forn(k, t) {
		string s; cin >> s;
		string v = solve(s);
		cout << "Case #" << (k+1) << ": " << v << endl;
	}
	return 0;
}
