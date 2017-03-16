#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int n;
vector<string> first, second;

void solve() {
	int best = 0;
	for (int i = 0; i < (1 << n); i++) {
		set<string> used_first;
		set<string> used_second;
		for (int j = 0; j < n; j++) {
			if (i & (1 << j)) {
				used_first.insert(first[j]);
				used_second.insert(second[j]);
			}
		}

		int tmp = 0;
		for (int j = 0; j < n; j++) {
			if (!(i & (1 << j))) {
				if (used_first.find(first[j]) != used_first.end() &&
					used_second.find(second[j]) != used_second.end()) {
						tmp++;
				}
			}
		}

		best = max(best, tmp);
	}

	printf("%d\n", best);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int ctest = 1; ctest <= t; ctest++) {
		first.clear();
		second.clear();

		scanf(" %d", &n);
		for (int i = 0; i < n; i++) {
			char f[25];
			char s[25];
			scanf(" %s %s", f, s);
			first.push_back(string(f));
			second.push_back(string(s));
		}

		printf("Case #%d: ", ctest);
		solve();
	}
	return 0;
}
