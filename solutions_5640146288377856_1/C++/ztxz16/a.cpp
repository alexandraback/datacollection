#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#define Max(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((b) & FASTBUFFER | (a) & ~FASTBUFFER))
#define Min(a, b) ((FASTBUFFER = ((a) - (b)) >> 31), ((a) & FASTBUFFER | (b) & ~FASTBUFFER))
#define Swap(a, b) (a ^= b, b ^= a, a ^= b)
#define OO 2147483647
#define priority_queue PQ

using namespace std;

const int N = 1000005;

int FASTBUFFER, test;
int visit[N], f[N];
int r, c, w, mi[16];

int dfs(int now) {
	int a[11] = {0};
	if (visit[now]) {
		return f[now];
	}
	
	visit[now] = 1;
	int x = now, s = 0;
	while (x) {
		a[++a[0]] = x % 3;
		x /= 3;
		s += (a[a[0]] == 2);
	}
	
	if (s == w) {
		return 0;
	}
	
	int tag = 0;
	for (int i = 1; i + w - 1 <= c; i++) {
		int flag = 1;
		for (int j = 1; j <= c; j++) {
			if (j >= i && j <= i + w - 1) {
				if (a[j] == 1) {
					flag = 0;
					break;
				}
			} else {
				if (a[j] == 2) {
					flag = 0;
					break;
				}
			}
		}
		
		if (flag) {
			tag = 1;
			break;
		}
	}
	
	if (!tag) {
		return -10000;
	}
	
	f[now] = 2147483647;
	for (int i = 1; i <= c; i++) {
		if (a[i] == 0) {
			f[now] = min(f[now], max(dfs(now + mi[i - 1]), dfs(now + mi[i - 1] * 2)) + 1);
		}
	}
	
	return f[now];
}

void work() {
	scanf("%d %d %d", &r, &c, &w);
	int ret = 0;
	for (int i = w; i <= c; i += w) {
		ret += (r - 1);
	}
	
	for (int i = w; i <= c; i += w) {
		if (i + w > c) {
			ret += w + ((c - i + w) > w);
		} else {
			ret++;
		}
	}
	
	printf("%d\n", ret);
}

int main() {
	freopen("input.txt", "r", stdin); freopen("output1.txt", "w", stdout);
	mi[0] = 1;
	for (int i = 1; i <= 10; i++) {
		mi[i] = mi[i - 1] * 3;
	}
	
	scanf("%d", &test);
	for (int tt = 1; tt <= test; tt++) {
		printf("Case #%d: ", tt);
		work();
	}
	
	return 0;
}

