#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1000000 + 86;
const char D[] = "EWNS";

char s[MAXN];
int p;

int main() {
	int tc, cn = 0;
	int x, y;
	
	scanf("%d", &tc);
	while (tc--) {
		scanf("%d%d", &x, &y);
		int cx = 0, cy = 0;
		int dx, dy;
		int i = 1;
		memset(s, 0, sizeof(s));
		p = 0;
		if (x < 0) dx = (i + 1) % 2;
		else dx = i % 2;
		for (; cx!=x; ++i) {
			if (i % 2 == dx) s[p++] = 'W', cx -= i;
			else s[p++] = 'E', cx += i;
		}
		if (y < 0) dy = (i + 1) % 2;
		else dy = i % 2;
		for (; cy != y; ++i) {
			if (i % 2 == dy) s[p++] = 'S', cy -= i;
			else s[p++] = 'N', cy += i;
		}
		printf("Case #%d: %s\n", ++cn, s);
	}

	return 0;
}
