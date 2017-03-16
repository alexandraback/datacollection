#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:16777216")
#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <string>
#include <cassert>
#include <iomanip>
#include <sstream>
#include <iostream>
using namespace std;
typedef long long LL;
template<class T> T Abs(T x) { return x < 0 ? -x : x; }


void Go() {
	string a, b;
	cin >> a >> b;
	int q = 0;
	for (auto c : a) {
		if (c == '?') {
			q++;
		}
	}
	for (auto c : b) {
		if (c == '?') {
			q++;
		}
	}
	vector<int> repl(q);
	int bestDiff = -1;
	int bestA = -1;
	int bestB = -1;
	while (true) {
		int j = 0;
		int nA = 0;
		for (auto c : a) {
			int d = (c == '?') ? repl[j++] : (c - '0');
			nA = nA * 10 + d;
		}
		int nB = 0;
		for (auto c : b) {
			int d = (c == '?') ? repl[j++] : (c - '0');
			nB = nB * 10 + d;
		}
		int diff = abs(nA - nB);
		if (bestDiff == -1 || make_tuple(diff, nA, nB) < make_tuple(bestDiff, bestA, bestB)) {
			bestDiff = diff;
			bestA = nA;
			bestB = nB;
		}
		int rem = 1;
		for (int i = 0; i < q; i++) {
			int v = repl[i] + rem;
			rem = v / 10;
			repl[i] = v % 10;
		}
		if (rem > 0) {
			break;
		}
	}
	cout
		<< setfill('0') << setw(a.size()) << bestA << ' '
		<< setfill('0') << setw(b.size()) << bestB << endl;
}

int main() {
	const string task = "B";
	const string folder = "gcj/2016/1B";
	const int attempt = 0;
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
