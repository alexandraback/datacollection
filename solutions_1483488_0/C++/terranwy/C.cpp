#include <cstdio>

const int ns[10] = {0, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int casei, cases, A, B, ans;
int vlen;
int valid[10];

inline void tryAdd(int t) {
	for (int i = 0; i < vlen; ++i) if (valid[i] == t) return;
	valid[vlen++] = t;
}

int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	
	scanf("%d", &cases);
	for (casei = 1; casei <= cases; ++casei) {
		scanf("%d%d", &A, &B);
		ans = 0;
		for (int i = A; i <= B; ++i) {
			int len = 0;
			while (i >= ns[len]) ++len;
			vlen = 0;
			for (int j = 1; j < 10 && i >= ns[j]; ++j) {
				int k = (i % ns[j]) * ns[len - j] + i / ns[j];
				if (k >= A && k <= B && k > i) {
					tryAdd(k);					
				}
			}
			ans += vlen;
		}
		printf("Case #%d: %d\n", casei, ans);
	}

	return 0;
}
