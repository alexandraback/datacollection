#include <iostream>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <queue>
#include <algorithm>
#include <cstdio>
#pragma comment(linker, "/STACK:256000000")

using namespace std;

void solve(int tcase) {
	cout << "Case #" << tcase << ":";

	int n;
	cin >> n;

	map<int, int> a;

	for (int i = 0; i < 2 * n - 1; ++i) {
		for (int j = 0; j < n; ++j) {
			int x;
			cin >> x;
			++a[x];
		}
	}

	vector<int> res;
	for (const auto& p : a) {
		if (p.second % 2 == 1) {
			res.push_back(p.first);
		}
	}
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size(); ++i) {
		cout << " " << res[i];
	}
	cout << endl;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i) {
		solve(i + 1);
	}

	return 0;
}