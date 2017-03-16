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
using namespace std;
typedef long long LL;
template<class T> T Abs(T x) { return x < 0 ? -x : x; }


void Go() {
	int B;
	LL M;
	cin >> B >> M;
	LL total = (LL)1 << (B - 2);
	if (total < M) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	cout << "POSSIBLE" << endl;
	vector<string> res(B, string(B, '0'));
	for (int u = 0; u < B; u++) {
		for (int v = u + 1; v < B; v++) {
			res[u][v] = '1';
		}
	}
	LL remained = total - M;
	for (int u = 1; u < B; u++) {
		int t = max(0, B - u - 2);
		LL c = (LL)1 << t;
		if (c <= remained) {
			remained -= c;
			res[0][u] = '0';
		}
	}
	for (auto row : res) {
		cout << row << endl;
	}
}

int main() {
	const string task = "B";
	const string folder = "gcj/2016/1C";
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
