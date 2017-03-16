#include <cstdio>
#include <cstdlib>
#include <cstring>

int main() {
	int testNum;
	scanf("%d", &testNum);
	for (int test = 1; test <= testNum; ++test) {
		int N;
		char p[99];
		scanf("%d", &N);
		scanf("%s", p);
		int ans = 0;
		int pt = 0;
		for (int i = 0; i <= N; ++i) {
			int pn = p[i] - '0';
			if (pn && pt < i) {
				ans += i - pt;
				pt = i;
			}
			pt += pn;
		}
		printf("Case #%d: %d\n", test, ans);
	}
	return 0;
}