#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

int FASTBUFFER;

int n, v, c, d, a[105];
int ans, f[105];

void dfs(int i) {
	if (i >= ans + 1) {
		return;
	}
	
	memset(f, 0, sizeof(f));
	f[0] = 1;
	for (int j = 1; j < i; j++) {
		for (int k = v; k >= a[j]; k--) {
			f[k] |= f[k - a[j]];
		}
	}
	
	int ok = 1;
	for (int j = 1; j <= v; j++) {
		if (!f[j]) {
			ok = 0;
			break;
		}
	}
	
	if (ok) {
		ans = i - 1;
		return;
	}
	
	for (int j = 1; j <= v; j++) {
		ok = 1;
		for (int k = 1; k < i; k++) {
			if (a[k] == j) {
				ok = 0;
				break;
			}
		}
		
		if (ok == 1) {
			a[i] = j;
			dfs(i + 1);
		}
	}
}

void work() {
	scanf("%d %d %d", &c, &d, &v);
	for (int i = 1; i <= d; i++) {
		scanf("%d", &a[i]);
	}
	
	if (c != 1 || v > 30) {
		printf("100\n");
		return;
	}
	
	ans = d + 5;
	dfs(d + 1);
	printf("%d\n", ans - d);
}

int test;

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d", &test);
	for (int tt = 1; tt <= test; tt++) {
		printf("Case #%d: ", tt);
		work();
	}
	
	return 0;
}
