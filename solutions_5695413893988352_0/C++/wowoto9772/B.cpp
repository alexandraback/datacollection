#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

char a[5], b[5];
int ans, s;
int x, y;

void dfs(int A, int B, int d) {
	if (d == s) {
		if (ans > abs(A - B)) {
			ans = abs(A - B);
			x = A, y = B;
		}
		else if (ans == abs(A - B)) {
			if (x > A)x = A, y = B;
		}
	}
	else {

		if (a[d] == '?' && b[d] == '?') {
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					dfs(A * 10 + i, B * 10 + j, d + 1);
				}
			}
		}
		else if (a[d] == '?') {
			for (int i = 0; i < 10; i++) {
				dfs(A * 10 + i, B * 10 + b[d] - '0', d+1);
			}
		}
		else if (b[d] == '?') {
			for (int i = 0; i < 10; i++) {
				dfs(A * 10 + a[d] - '0', B * 10 + i, d+1);
			}
		}
		else {
			dfs(A * 10 + a[d] - '0', B * 10 + b[d] - '0', d+1);
		}

	}
}

int main() {

	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small-attempt0.out", "w", stdout);

	int t;
	scanf("%d", &t);

	int tc = 0;

	while (t--) {

		scanf("%s %s", a, b);

		s = strlen(a);

		ans = 99999;

		dfs(0, 0, 0);

		printf("Case #%d: ", ++tc);

		if (s == 3)printf("%03d %03d\n", x, y);
		else if (s == 2)printf("%02d %02d\n", x, y);
		else
			printf("%d %d\n", x, y);

	}

}