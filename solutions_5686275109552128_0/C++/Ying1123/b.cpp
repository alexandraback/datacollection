#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;

int D;
int p[2000];

void work() {
	scanf("%d", &D);
	int maxp = 0;
	for (int i = 0; i < D; ++i) {
		scanf("%d", &p[i]);
		maxp = max(maxp, p[i]);
	}
	int ans = maxp;
	for (int i = 1; i < maxp; ++i) {
		int time = i;
		for (int j = 0; j < D; ++j) {
			if (p[j] > i) time += (p[j] - i - 1) / i + 1;
		}
		ans = min(ans, time);
	}
	printf("%d\n", ans);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; ++i) {
		printf("Case #%d: ", i + 1);
		work();
	}
	return 0;
}
