#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;
#define MAXN 2000010

int bit[MAXN];
int f[MAXN];
int g[10];
int temp[20];

int cal(int val, int A) {
	int u = val, res = 1, pos = 0;
	for(int i = 1; i < bit[val]; ++i) {
		u = u / f[val] + u % f[val] * 10;
		if(u >= A && u < val && bit[u] == bit[val]) {
			temp[pos++] = u;
		}
	}

	if(pos == 0) return pos;
	sort(temp, temp + pos);
//	printf("%d %d\n", temp[0], val);
	for(int i = 1; i < pos; ++i)
		if(temp[i] != temp[i - 1]) {
//			printf("%d %d\n", temp[i], val);
			++res;
		}
	return res;
}

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C.out", "w", stdout);
	g[1] = 1;
	for(int i = 2; i <= 7; ++i) g[i] = g[i - 1] * 10;
	for(int i = 1; i <= 2000000; ++i) {
		bit[i] = bit[i / 10] + 1;
		f[i] = g[bit[i]];
	}

	int T;
	scanf("%d", &T);

	for(int cas = 1; cas <= T; ++cas) {
		int A, B, res = 0;
		scanf("%d%d", &A, &B);
//		A = 1000000;B = 2000000;
		for(int i = A + 1; i <= B; ++i) {
			res += cal(i, A);
		}
		printf("Case #%d: %d\n", cas, res);
	}
	return 0;
}
