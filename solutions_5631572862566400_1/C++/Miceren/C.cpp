#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 1111;

int go[N];
int n;
int path[N], visit[N], crawl[N];

int main() {
	int tests;
	scanf("%d", &tests);
	for (int testCount = 1; testCount <= tests; testCount++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &go[i]);
			path[i] = 0;
		}
		for (int times = 0; times <= n + 10; times++) {
			for (int i = 1; i <= n; i++) {
				path[go[i]] = max(path[go[i]], path[i] + 1);
			}
		}

		for (int i = 1; i <= n; i++) {
			crawl[i] = 0;
			if (path[i] < n) {
				crawl[i] = path[i];
			} else {
				for (int y = 1; y <= n; y++) {
					if (path[y] < n && go[y] == i) {
						crawl[i] = max(crawl[i], path[y] + 1);
					}
				}
			}
		}

		static bool forbid[N];
		fill(forbid + 1, forbid + n + 1, false);

		int answer = 0, acumulate = 0;
		for (int x = 1; x <= n; x++) {
			if (forbid[x]) {
				continue;
			}
			int t = x, dist = 0;
			fill(visit + 1, visit + n + 1, 0);
			while (!visit[t]) {
				visit[t] = 1;
				t = go[t];
				dist++;
			}
			if (t == x) {
				do {
					forbid[t] = true;
					t = go[t];
				} while (t != x);
				answer = max(answer, dist);
				if (dist == 2) {
					acumulate += 2 + crawl[x] + crawl[go[x]];
				}
			}
		}
		printf("Case #%d: %d\n", testCount, max(answer, acumulate));
	}
	return 0;
}
