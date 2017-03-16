#define _CRT_SECURE_NO_WARNINGS
#include <functional>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <sstream>
#include <complex>
#include <cstdio>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <ctime>
#include <set>
#include <map>

#define ll long long
#define ld long double
#define mp make_pair
#define TASKNAME "monument"


const int inf = 2 * 1e9;
const int mod = 1e9 + 7;
const ll infll = (ll)1e18;
const ld eps = 1e-9;

const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, -1, 0, 1 };

using namespace std;

struct tt {
	int a, b, c;
	tt() : a(0), b(0), c(0) { }
	tt(int a, int b, int c) : a(a), b(b), c(c) {}
	bool operator<(const tt t) const {
		if (a < t.a)
			return true;
		if (a == t.a && b < t.b)
			return true;
		if (a == t.a && b == t.b && c < t.c)
			return true;
		return false;
	}
};

void solve() {
	int j, p, s, k;
	cin >> j >> p >> s >> k;
	vector<tt> ans;
	vector<vector<vector<int>>> mm(4, vector<vector<int>>(4, vector<int>(4, 0)));
	for (int a = 1; a < 4; a++) {
		if (a > j)
			break;
		for (int b = 1; b < 4; b++) {
			if (b > p)
				break;
			for (int c = 1; c < 4; c++) {
				if (c > s)
					break;
				if (mm[a][b][0] == k ||
					mm[a][0][c] == k ||
					mm[0][b][c] == k)
					continue;
				mm[a][b][0]++;
				mm[a][0][c]++;
				mm[0][b][c]++;
				ans.push_back(tt(a, b, c));
			}
		}
	}
	cout << ans.size() << endl;
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i].a << " " << ans[i].b << " " << ans[i].c;
		if (i != ans.size() - 1)
			cout << endl;
	}
}

int main() {
#ifdef __DEBUG__
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	clock_t start = clock();
#else
	//assert(freopen(TASKNAME".in", "r", stdin));
	//assert(freopen(TASKNAME".out", "w", stdout));
#endif

	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		cerr << "Test #" << t + 1 << " in progress\n";
		cout << "Case #" << t + 1 << ": ";
		solve();
		cout << endl;
		cerr << "Test #" << t + 1 << " done\n";
	}

#ifdef __DEBUG__
	fprintf(stderr, "\nTime: %Lf\n", ((clock() - start) / (ld)CLOCKS_PER_SEC));
#endif
	return 0;
}