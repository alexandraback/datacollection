#include <bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i) {
		int N;
		cin >> N;
		map<int, int> m;
		for (int j = 0; j < (2*N-1)*N; ++j) {
			int x;
			cin >> x;
			m[x]++;
		}
		vector<int> ans;
		for (auto x : m) {
			if (x.second % 2)
				ans.push_back(x.first);
		}
		sort(ans.begin(), ans.end());
		printf("Case #%d:", i+1);
		for (auto x : ans) {
			printf(" %d", x);
		}
		printf("\n");
	}
}
