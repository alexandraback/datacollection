#include <cstdio>
#include <cstring>
#include <cstdlib>

int tot;
int vis[10];

bool check(int k) {
	while (k) {
		if (!vis[k%10]) {
			vis[k%10] = 1;
			if (++tot == 10) return true;
		}
		k /= 10;
	}
	return false;
}

int main() {
	int T, n;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		scanf("%d",&n);
		printf("Case #%d: ", ca);
		if (n == 0) {
			printf("INSOMNIA\n");
			continue;
		}
		memset(vis, 0, sizeof(vis));
		tot = 0;
		int i;
		for (i = 1 ; ; ++i) {
			if (check(i*n)) break;
		}
		printf("%d\n", i*n);
	}
    return 0;
}
