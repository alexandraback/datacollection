#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

void solve(int t) {
	int n, m;
	cin >> n;
	vector<int> counts(2501, 0);
	for (int i = 0; i < 2 * n - 1; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m;
			counts[m]++;
		}
	}


	printf("Case #%d:", t);
	for (int i = 0; i < counts.size(); i++) {
		if (counts[i] % 2 == 1) {
			printf(" %d", i);
		}
	}
	printf("\n");
}

int main() {
	int t;

	cin >> t;
	vector<int> ans(t, 0);

	for (int i = 0; i < t; i++) {
		solve(i + 1);
	}
	return 0;
}
