#include <cstdio>
#include <cstdlib>

using namespace std;

const int MAXN = (int) 1e4;
const int trans[4][4] = {
	{1, 2, 3, 4},
	{2, -1, 4, -3},
	{3, -4, -1, 2},
	{4, 3, -2, -1}
};

char s[MAXN + 10];
int a[MAXN + 10], b[MAXN + 10];

inline int multiply(int x, int y) {
	int fx = x / abs(x);
	int fy = y / abs(y);
	return fx * fy * trans[abs(x) - 1][abs(y) - 1];
}

inline int calc(int x, int y) {
	for (int i = -4; i <= 4; i++)
		if (i && multiply(b[x - 1], i) == b[y])
			return i;
}

int main() {
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int T, kase = 0;
	b[0] = 1;
	scanf("%d", &T);
	while (T--) {
		int l, x;
		scanf("%d%d", &l ,&x);
		scanf("%s", s);
		int cnt = 0;
		while (x--)
			for (int i = 0; i < l; i++)
				a[++cnt] = s[i] - 'i' + 2;
		for (int i = 1; i <= cnt; i++)
			b[i] = multiply(b[i - 1], a[i]);
		bool flag = false;
		for (int i = 1; i < cnt; i++) {
			for (int j = i + 1; j < cnt; j++)
				if (calc(1, i) == 2 && calc(i + 1, j) == 3 && calc(j + 1, cnt) == 4) {
					flag = true;
					break;
				}
			if (flag) break;
		}
		printf("Case #%d: %s\n", ++kase, flag ? "YES" : "NO");
	}
	return 0;
}