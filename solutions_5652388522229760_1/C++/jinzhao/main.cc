#include <cstdio>
#include <cstring>

using namespace std;

bool b[10];

bool cal(int c) {
	while (c) {
		b[c % 10] = true;
		c /= 10;
	}
	for (int i = 0; i < 10; i++) {
		if (b[i] == false) return true;
	}
	return false;
}

int main() {
	int t, tt, a;
	scanf("%d", &t);
	for (tt = 1; tt <= t; tt++) {
		scanf("%d", &a);
		if (a == 0) {
			printf("Case #%d: INSOMNIA\n", tt);
		} else {
			memset(b, 0, sizeof(b));
			int ans = a;
			while (cal(ans)) ans += a;
			printf("Case #%d: %d\n", tt, ans);
		}
	}
	return 0;
}
