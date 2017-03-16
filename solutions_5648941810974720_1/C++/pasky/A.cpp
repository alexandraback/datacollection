#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <string>
#include <cassert>
#include <sstream>
#include <iostream>
#include <functional>
using namespace std;
typedef long long LL;
template<class T> T Abs(T x) { return x < 0 ? -x : x; }

vector<string> DIGITS = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};


void Go() {
	string ss;
	cin >> ss;
	vector<int> counts(26);
	auto digits = DIGITS;
	for (auto& s : digits) {
		for (auto& c : s) {
			c -= 'A';
		}
	}
	int total = 0;
	for (auto c : ss) {
		counts[c - 'A']++;
		total++;
	}
	string res;
	auto remove = [&](int digit, int cnt) {
		for (int i = 0; i < cnt; i++) {
			for (auto c : digits[digit]) {
				counts[c]--;
				total--;
			}
			res.push_back(digit + '0');
		}
	};
	remove(0, counts['Z' - 'A']);
	remove(2, counts['W' - 'A']);
	remove(4, counts['U' - 'A']);
	remove(6, counts['X' - 'A']);
	remove(8, counts['G' - 'A']);

	bool stop = false;
	function<void(int)> find = [&](int firstDigit) {
		if (total == 0) {
			sort(res.begin(), res.end());
			cout << res << endl;
			stop = true;
		}
		if (stop) {
			return;
		}
		for (int digit = firstDigit; digit < 10; digit++) {
			res.push_back(digit + '0');
			bool ok = true;
			for (auto c : digits[digit]) {
				counts[c] -= 1;
				ok = ok && counts[c] >= 0;
				total -= 1;
			}
			if (ok) {
				find(digit);
			}
			for (auto c : digits[digit]) {
				counts[c] += 1;
				total += 1;
			}
			res.pop_back();
		}
	};
	find(0);
}

int main() {
	const string task = "A";
	const string folder = "gcj/2016/1B";
	const int attempt = -1;
	const bool dbg = false;

	if (dbg) {
		freopen("inp.txt", "r", stdin);
	}
	else {
		stringstream ss;
		ss << folder << '/' << task;
		if (attempt < 0)
			ss << "-large";
		else
			ss << "-small-attempt" << attempt;
		freopen((ss.str() + ".in").c_str(), "r", stdin);
		freopen((ss.str() + ".out").c_str(), "w", stdout);
	}


	static char tt[128];
	gets(tt);
	int t;
	sscanf(tt, "%d", &t);
	for (int i = 0; i < t; i++) {
		printf("Case #%d: ", i + 1);
		Go();
	}
	return 0;
}
