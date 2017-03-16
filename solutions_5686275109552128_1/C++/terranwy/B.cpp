#include <cstdio>
#include <cstring>

const int maxP = 1000;

int casei, cases, n;
int p[1010];


int main() {
	scanf("%d", &cases);
	for (casei = 1; casei <= cases; ++casei) {
		scanf("%d", &n);
		int m;
		memset(p, 0, sizeof(p));
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &m);
			++p[m];
			if (m > ans) ans = m;
		}
		
		for (int i = 1; i < ans; ++i) {
			int now = i;
			for (int j = i + 1; j <= maxP; ++j) if (p[j] > 0) {
				now += p[j] * ((j - 1) / i);
			}
			if (now < ans) ans = now;
		}
			
		printf("Case #%d: %d\n", casei, ans);
		
	}
	
	return 0;
}

