#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <utility>

using namespace std;

int tests, r, n, m, k, cnt[66][126], value[8];
pair<int, pair<int, int> > P[66];

struct S {
	int a, b, c;
};

int incode(int a, int b, int c) {
	return a * 36 + b * 6 + c;
}

int main() {
	freopen("C-small-1-attempt0.in", "r", stdin);
	freopen("C-small-1-attempt0.out", "w", stdout);
	int p = 0;
	for (int a = 2; a <= 5; ++a) {
		for (int b = 2; b <= 5; ++b) {
			for (int c = 2; c <= 5; ++c) {
				++p;
				for (int mask = 0; mask < 8; ++mask) {
					int product = 1;
					if (mask & 1) product *= a;
					if ((mask >> 1) & 1) product *= b;
					if ((mask >> 2) & 1) product *= c;
					++cnt[p][product];
				}
				P[p] = make_pair(a, make_pair(b, c));
			}
		}
	}
	printf("Case #1:\n");
	scanf("%d", &tests);
	scanf("%d%d%d%d", &r, &n, &m, &k);
	while (r--) {
		for (int i = 1; i <= k; ++i) {
			scanf("%d", &value[i]);
		}
		vector<int> avl;
		for (int i = 1; i <= p; ++i) {
			bool flag = true;
			int sum = 0;
			for (int j = 1; j <= k; ++j) {
				if (cnt[i][value[j]] == 0) {
					flag = false;
				}
			}
			if (flag) avl.push_back(i);
		}
		int ra = rand() % avl.size();
		printf("%d%d%d\n", P[avl[ra]].first, P[avl[ra]].second.first, P[avl[ra]].second.second);
	}
	return 0;
}
