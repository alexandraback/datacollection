#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <bitset>

using namespace std;

int n;
int a[30];

vector <pair<int, int> > sums;

void solve(int testcase) {
	printf("Case #%d:\n", testcase);
	sums.clear();

	scanf("%d", &n);

	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}

	for (int i = 1; i < (1 << n); ++i) {
		int sum = 0;
		for (int j = 0; j < n; ++j) {
			if (i & (1 << j)) {
				sum += a[j];
			}
		}
		sums.push_back(make_pair(sum, i));
	}
	sort(sums.begin(), sums.end());

	for (int i = 1; i < sums.size(); ++i) {
		if (sums[i].first == sums[i - 1].first) {
			int val = sums[i].second;
			for (int j = 0; j < n; ++j) {
				if (val & (1 << j)) {
					printf("%d ", a[j]);
				}
			}
			printf("\n");
			val = sums[i - 1].second;
			for (int j = 0; j < n; ++j) {
				if (val & (1 << j)) {
					printf("%d ", a[j]);
				}
			}
			printf("\n");
			return ;
		}
	}
	printf("Impossible\n");
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;

	cin >> tests;

	for (int t = 1; t <= tests; ++t) {
		solve(t);
	}

	return 0;
}