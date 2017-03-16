#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
typedef long long LL;

LL n;
bool vis[15];

void deal(LL x) {
	while (x > 0) {
		vis[x % 10] = true;
		x /= 10;
	}
}

bool check() {
	for (int i = 0; i < 10; i++) {
		if (!vis[i]) return false;
	}
	return true;
}

int main() {
	int kase = 0;
	int T;
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d: ", ++kase);
		scanf("%lld", &n);
		if (n == 0) {
			printf("INSOMNIA\n");
			continue;
		}
		memset(vis, 0, sizeof(vis));
		for (int i = 1; ; i++) {
			deal(n * i);
			if (check()) {
				printf("%lld\n", n * i);
				break;
			}
		}
	}
	return 0;
}
