#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;

int n;
vector<int> cakes, tmp;

bool solve(int upper) {
	for (int spe = 0; spe < upper; spe++) {
		int rest = spe, limit = upper - spe;
		tmp = cakes;
		for (int i = 0; i < n; i++) {
			if (tmp[i] <= limit) {
				continue;
			}
			int r = tmp[i] - limit;
			rest -= (r + limit - 1) / limit;
		}
		if (rest >= 0) {
			return true;
		}
	}
	return false;
}

int main() {
	int test;
	scanf("%d", &test);
	for (int testCount = 1; testCount <= test; testCount++) {
		scanf("%d", &n);
		cakes.clear();
		for(int i = 0; i < n; i++) {
			int number;
			scanf("%d", &number);
			cakes.push_back(number);
		}
		sort(cakes.begin(), cakes.end());
		int l = 0, r = 1000; 
		while (l < r) {
			int mid = (l + r) >> 1;
			if (solve(mid)) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		printf("Case #%d: %d\n", testCount, l);
	}
	return 0;
}