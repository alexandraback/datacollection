#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>

using namespace std;

const int maxN = 510;
const int maxS = 1 << 20;

int n, a[maxN];
pair < int, int > s[maxS];

void solve(int test) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < (1 << n); ++i) {
		int res = 0;
		for (int j = 0; j < n; ++j)
			if (i & (1 << j))
				res += a[j];
		s[i] = make_pair(res, i);
	}
	printf("Case #%d:\n", test);
	sort(s + 1, s + (1 << n));
	bool have = false;
	for (int i = 2; i < (1 << n); ++i)
		if (s[i].first == s[i - 1].first) {
			vector < int > p, q;
			for (int j = 0; j < n; ++j) {
				if (s[i].second & (1 << j)) p.push_back(a[j]);
				if (s[i - 1].second & (1 << j)) q.push_back(a[j]);
			}
			have = true;
			for (int j = 0; j < p.size(); ++j)
				printf((j == 0) + " %d", p[j]);
			printf("\n");
			for (int j = 0; j < q.size(); ++j)
				printf((j == 0) + " %d", q[j]);
			printf("\n");
			break;
		}
	if (!have) {
		printf("Impossible\n");
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d", &tests);
	for (int i = 0; i < tests; ++i) {
		solve(i + 1);
	}
	return 0;
}