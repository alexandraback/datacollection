#include <cstdio>
#include <cstring>

const int N = 1000 + 10;

int n, d[N];


inline bool Check(int m) {
	// printf("%d:\n", m);
	for (int i = 1; i <= m; ++i) {
		int cot = 0;
		for (int j = 0; j < n; ++j)
			cot += (d[j] - 1) / i;
		// printf("%d %d\n", i, cot);
		if (cot + i <= m) return true;
	}
	return false;
}

inline int Work() {
	int l = 0, r = 0, m;
	
	scanf("%d ", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d ", d + i);
		if (d[i] > r) r = d[i];
	}
	
	while (l + 1 < r) {
		m = (l + r) >> 1;
		if (Check(m)) r = m; else l = m;
	}
	
	return r;
}

int main() {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	
	int T; scanf("%d ", &T);
	for (int i = 1; i <= T; ++i)
		printf("Case #%d: %d\n", i, Work());
	
	return 0;
}
