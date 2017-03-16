#include <cstdio>
using namespace std;

int main() {
	int t;
	char buf[120];
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%s", buf);
		int ans = 0;
		char *p = buf;
		char s;
		while (*p) {
			s = *p;
			while (*p == s) p++;
			ans++;
		}
		if (s == '+') ans--;
		printf("Case #%d: %d\n", i, ans);
	}
}
