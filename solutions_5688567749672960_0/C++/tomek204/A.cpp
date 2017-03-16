#include <bits/stdc++.h>

using namespace std;

int w[1000100];

int rev(int u) {
	int ret = 0, pot = 1;
	while (u) {
		ret = ret * 10 + (u%10);
		u /= 10;
	}
	return ret;
}

int main() {
	for (int i = 1; i <= 1000000; i++) w[i] = 1000000;
	w[1] = 1;
	for (int i = 1; i <= 1000000; i++) {
		w[i+1] = min(w[i+1], w[i]+1);
		int k = rev(i);
		if (k <= 1000000) w[k] = min(w[k], w[i]+1);
	}
	int t; scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		int n; scanf("%d", &n);
		printf("Case #%d: %d\n", i, w[n]);
	}
	return 0;
}