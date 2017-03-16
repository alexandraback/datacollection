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

int n, k, l, s, test;
double s1, s2, mx;
char a[105], b[105], now[105];

void dfs(int i) {
	if (i > s) {
		int nownow = 0;
		s2++;
		for (int j = 1; j + l - 1 <= s; j++) {
			int flag = 1;
			for (int k = 1; k <= l; k++) {
				if (b[k] != now[j + k - 1]) {
					flag = 0;
					break;
				}
			}
			
			s1 += flag;
			nownow += flag;
		}
		
		mx = max(mx, (double)nownow);
		return;
	}
	
	for (int x = 1; x <= k; x++) {
		now[i] = a[x];
		dfs(i + 1);
	}
}

void work() {
	scanf("%d %d %d", &k, &l, &s);
	scanf("%s", a + 1);
	scanf("%s", b + 1);
	s1 = s2 = mx = 0;
	dfs(1);
	printf("%.12f\n", mx - s1 / s2);
}

int main() {
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	scanf("%d", &test);
	for (int tt = 1; tt <= test; tt++) {
		printf("Case #%d: ", tt);
		work();
	}
	
	return 0;
}
