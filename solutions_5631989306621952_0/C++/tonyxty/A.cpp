#include <cstdio>
#include <cstring>
using namespace std;

char buf[1004];
char ans[2008];
int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%s", buf);
		int l = strlen(buf);
		int st = 1004, sp = 1005;
		ans[1004] = buf[0];
		for (int i = 1; i < l; i++) {
			ans[st - 1] = ans[sp] = buf[i];
			if (strncmp(ans + st - 1, ans + st, sp - st + 1) > 0)
				st--;
			else
				sp++;
		}
		ans[sp] = '\0';
		printf("Case #%d: %s\n", t, ans + st);
	}
}
