#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int value[3000];

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("b.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++) {
		memset(value, 0, sizeof(value));
		int n;
		scanf("%d", &n);
		for (int i = 0; i < 2 * n - 1; i++) {
			for (int j = 0; j < n; j++) {
				int num;
				scanf("%d", &num);
				value[num]++;
			}
		}
		vector<int> ans;
		ans.clear();
		for (int i = 0; i < 3000; i++) {
			if (value[i] % 2 == 1) {
				ans.push_back(i);
			}
		}
		sort(ans.begin(), ans.end());
		printf("Case #%d:", t + 1);
		for (int i = 0; i < ans.size(); i++) {
			printf(" %d", ans[i]);
		}
		printf("\n");
	}
}