#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(int a, vector<int> m) {
	int r = 1000;
	int i = 0;
	int c = 0;
	while (true) {
		while (i < m.size() && m[i] < a) {
			a += m[i];
			++i;
		}
		if (r > c + m.size() - i) r = c + m.size() - i;
		if (i == m.size()) break;
		if (a == 1) break;
		while (a <= m[i]) {
			c++;
			a += a - 1;
		}
	}
	return r;
}

int main() {
	int cc;
	cin >> cc;
	for (int c = 0; c < cc; ++c) {
		int a, t;
		cin >> a >> t;
		vector<int> m(t);
		for (int i = 0; i < t; ++i) {
			cin >> m[i];
		}
		sort(m.begin(), m.end());
		printf("Case #%d: %d\n", c + 1, solve(a, m));
	}
}