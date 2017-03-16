#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <vector>
#include <bitset>
#include <map>
#include <queue>
#include <ctime>
#include <stack>
#include <set>
#include <list>
#include <deque>
#include <functional>
#include <sstream>
#include <fstream>
#include <complex>
#include <numeric>
#include <assert.h>
#include <iomanip>
#include <unordered_map>

using namespace std;

int a, b, c, K, T;

struct point {
	int a, b, c;
};

vector<point> v, ans;
map<pair<int, int>, int> aa, bb, cc;
int start, en;

void go() {
	if (ans.size() < v.size())
		ans = v;
	en = clock();
	if ((en - start + .0) / CLOCKS_PER_SEC >= 2.0)
		return;
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			for (int k = 1; k <= c; k++) {
				if (!v.empty() && v.back().a == i && v.back().b == j && v.back().c == k)
					continue;
				en = clock();
				if (aa[{i, j}] + 1 <= K && bb[{j, k}] + 1 <= K && cc[{i, k}] + 1 <= K && (en - start + .0) / CLOCKS_PER_SEC <= 2.0) {
					aa[{i, j}]++;
					bb[{j, k}]++;
					cc[{i, k}]++;
					v.push_back({ i, j, k });
					go();
					v.pop_back();
					aa[{i, j}]--;
					bb[{j, k}]--;
					cc[{i, k}]--;
				}
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> a >> b >> c >> K;
		aa.clear();
		bb.clear();
		cc.clear();
		ans.clear();
		start = clock();
		go();
		cout << "Case #" << t << ": " << (int)ans.size() << endl;
		for (int i = 0; i < (int)ans.size(); i++)
			cout << ans[i].a << " " << ans[i].b << " " << ans[i].c << endl;
	}
	return 0;
}