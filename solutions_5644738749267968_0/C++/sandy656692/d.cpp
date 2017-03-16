#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2020;

struct node {
	double w;
	bool a;
	bool operator < (const node & b) const {
		return w > b.w;
	}
} all[N];

int main() {
	int ttt;
	scanf("%d", &ttt);
	for (int test = 1; test <= ttt; ++test) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%lf", &all[i].w);
			all[i].a = true;
		}
		for (int i = 0; i < n; ++i) {
			scanf("%lf", &all[i + n].w);
			all[i + n].a = false;
		}
		sort(all, all + n + n);
		int minn = 0, maxn = 0;
		int sum = 0;
		for (int i = 0; i < n + n; ++i) {
			if (!all[i].a) {
				++sum;
				continue;
			}
			if (sum == 0) ++minn;
			else --sum;
		}
		sum = 0;
		for (int i = 0; i < n + n; ++i) {
			if (all[i].a) {
				++sum;
				continue;
			}
			if (sum == 0) continue;
			--sum;
			++maxn;
		}
		printf("Case #%d: %d %d\n", test, maxn, minn);
	}
	return 0;
}