#include <cstdio>
#include <cstring>
using namespace std;

int T, n, m, z[55], x, y;
bool b[55][55];
char ans[500];

int a[55];
bool v[55];
int q[55], qw;
bool valid() {
	qw = 0;
	q[qw++] = a[0];
	for (int i = 1; i < n; ++i) {
		while (qw > 0 && !b[q[qw-1]][a[i]]) qw--;
		if (qw == 0) return false;
		q[qw++] = a[i];
	}
	return true;
}
void per(int i) {
	if (i == n) {
		if (valid()) {
			char s[500], t[500];
			strcpy(s, "");
			for (int j = 0; j < n; ++j) {
				sprintf(t, "%05d", z[a[j]]);
				strcat(s, t);
			}
			if (strlen(ans) == 0 || strcmp(s, ans) < 0) strcpy(ans, s);
		}
		return;
	}
	for (int j = 0; j < n; ++j) {
		if (v[j]) {
			a[i] = j;
			v[j] = false;
			per(i+1);
			v[j] = true;
		}
	}
}

int main() {
	scanf("%d", &T);
	for (int tc = 1; tc <= T; ++tc) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &z[i]);
		}
		memset(b, false, sizeof b);
		for (int i = 0; i < m; ++i) {
			scanf("%d%d", &x, &y);
			x--;
			y--;
			b[x][y] = b[y][x] = true;
		}
		memset(v, true, sizeof v);
		strcpy(ans, "");
		per(0);
		printf("Case #%d: %s\n", tc, ans);
	}
	return 0;
}