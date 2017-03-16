#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 3000
using namespace std;

int T, n, x;
int p[N];

int main() {
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	scanf("%d", &T);
	for (int k = 1; k <= T; k++) {
		scanf("%d", &n);
		memset(p, 0, sizeof p);
		for (int i = 1; i < 2 * n; i++) 
			for (int j = 1; j <= n; j++) {
				scanf("%d", &x);
				p[x] ^= 1;
			}
		printf("Case #%d: ", k);
		for (int i = 1; i <= 2500; i++) if (p[i]) printf("%d ", i);
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
}