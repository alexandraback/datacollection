#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char s[2][8];
int len;
int ans[2];
int mn;
void dfs(int x) {
	if (x == len + len) {
		//printf("sfd\n");
		int t0 = 0, t1 = 0;
		for (int i = 0; i < len; ++ i) {
			t0 *= 10;
			t0 += s[0][i] - '0';
			t1 *= 10;
			t1 += s[1][i] - '0';
		}
		if (abs(t0 - t1) < mn || (abs(t0 - t1) == mn && t0 < ans[0]) || (abs(t0 - t1) == mn && t0 == ans[0] && t1 < ans[1])) {
			mn = abs(t0 - t1);
			ans[0] = t0;
			ans[1] = t1;
		}
		return;
	}
	if (x < len) {
		if (s[0][x] == '?') {
			for (int i = 0; i <= 9; ++ i) {
				s[0][x] = i + '0';
				dfs(x + 1);
			}
			s[0][x] = '?';
		}
		else {
			dfs(x + 1);
		}
	}
	else {
		if (s[1][x - len] == '?') {
			for (int i = 0; i <= 9; ++ i) {
				s[1][x - len] = i + '0';
				dfs(x + 1);
			}
			s[1][x - len] = '?';
		}
		else {
			dfs(x + 1);
		}
	}
}
int main() {
	int T;
	freopen("B-small-attempt1.in", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	for (int cas = 1; cas <= T; ++ cas) {
		memset(s, 0, sizeof s);
		scanf("%s%s", s[0], s[1]);
		len = strlen(s[0]);
		mn = 100010;
		dfs(0);
		printf("Case #%d: ", cas);
		if (len == 1) {
			printf("%01d %01d\n", ans[0], ans[1]);
		}
		if (len == 2)
			printf("%02d %02d\n", ans[0], ans[1]);
		else if (len == 3) {
			printf("%03d %03d\n", ans[0], ans[1]);
		}
	}
	return 0;
}