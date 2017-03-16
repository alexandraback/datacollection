#include <stdio.h>
#include <string.h>

int a, b, w, n;
int mark[3000000];
int f(int x) {
	if(x < 10) return 0;
	int y = x, ret = 0;
	for(int i = 0; i < n; ++i) {
		y = y / 10 + y % 10 * w;
		if(y > x && y <= b && mark[y] != x) {
			mark[y] = x;
			++ret;
		}
	}
	return ret;
}

int solve() {
	int ret = 0;
	w = 1, n = 0;
	while(a / w > 9) {
		w *= 10;
		++n;
	}
	for(int i = a; i <= b; ++i) {
		ret += f(i);
	}
	return ret;
}

int main() {
	int t;
	freopen("C-large.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &t);
	for(int i = 0; i < t; ++i) {
		scanf("%d %d", &a, &b);
		memset(mark + a, 0, sizeof(mark[0]) * (b - a + 1));
		printf("Case #%d: %d\n", i + 1, solve());
	}
	//scanf("%d");
	return 0;
}
