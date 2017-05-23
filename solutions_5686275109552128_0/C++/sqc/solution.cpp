#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int main() {
	//freopen("B-small-attempt0.in", "r", stdin);
	//freopen("B-small-attempt0.out", "w", stdout);
	//freopen("B-large.in", "r", stdin);
	//freopen("B-large.out", "w", stdout);
	int t;
	int tmp;
	int d;
	scanf("%d", &t);
	vector<int> ps;
	int res;
	int curTimes;
	int maxCount;
	for (int i = 1 ; i <= t; i++) {
		ps.clear();
		res = INT_MAX;
		maxCount = 0;
		scanf("%d", &d);
		for (int j = 0; j < d; j++) {
			scanf("%d", &tmp);
			maxCount = max(maxCount, tmp);
			ps.push_back(tmp);
		}
		


		for (int k = maxCount; k >= 1; k--) {
			curTimes = 0;
			for (int j = 0; j < d; j++) {
				if (ps[j] > 1) {
					curTimes += (ps[j] - 1) / k;
				}
			}
			res = min(res, curTimes + k);
		}
		printf("Case #%d: %d\n", i, res);
	}
	return 0;
}