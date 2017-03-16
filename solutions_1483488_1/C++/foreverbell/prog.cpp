
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long LL;
int test_case, a, b, p10[10], arr[2000001];

void init() {
	p10[0] = 1;
	for (int i = 1; i < 10; ++i) p10[i] = p10[i - 1] * 10;
}

int gcnt(int x) {
	if (arr[x] != -1) return arr[x] - 1;
	int bit[10], l = 0, y = x, cnt = 0, tbl[20];
	while (y) bit[l++] = y % 10, y /= 10;	
	l -= 1, y = x;
	for (int i = l; i >= 0; --i) { 
		if (bit[i] != 0 && y >= a && y <= b) {
			if (arr[y] == -1) tbl[++cnt] = y;
			arr[y] = 1;
		}
		y -= p10[l] * bit[i];
		y *= 10;
		y += bit[i];
	}
	sort(tbl + 1, tbl + 1 + cnt);
	for (int i = 1; i <= cnt; ++i) {
		arr[tbl[i]] = i;
	}
	return arr[x] - 1;
}

int main() {
	init();
	scanf("%d", &test_case);
	for (int tt = 1; tt <= test_case; ++tt) {
		int res = 0;
		scanf("%d%d", &a, &b);
		for (int i = a; i <= b; ++i) arr[i] = -1;
		for (int i = a; i <= b; ++i) {
			res += gcnt(i);
		}
		printf("Case #%d: %d\n", tt, res);
	}
	return 0;
}
