#include <stdio.h>
#include <string>
#include <algorithm>
#include <string.h>
using namespace std;
int a[55][55], d[55][55];
int B;
long long M, M2;
long long f[55];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	f[1] = 1;
	f[2] = 1;
	for (int i = 3; i <= 50; i++) {
		for (int j = 1; j < i; j++) f[i] += f[j];
	}
	int T, runs; for (scanf("%d", &T), runs = 1; T--; runs++) {
		memset(a, 0, sizeof(a));
		printf("Case #%d: ", runs);
		scanf("%d%lld", &B, &M); M2 = M;
		if (f[B] >= M) {
			puts("POSSIBLE");
			for (int i = B; i >= 1; i--) {
				if (M >= f[i]) {
					M -= f[i];
					for (int j = 1; j <= i; j++) {
						for (int k = j + 1; k <= i; k++) {
							a[j][k] = 1;
						}
					}
					if (i != B) a[i][B] = 1;
				}
			}
			for (int i = 1; i <= B; i++) {
				for (int j = 1; j <= B; j++) printf("%d", a[i][j]);
				puts("");
			}
		}
		else puts("IMPOSSIBLE");
	}
}