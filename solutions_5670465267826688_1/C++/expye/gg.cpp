#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const char ans[2][5] = {
	"NO", "YES"
};
int T, l;
long long x;
int mul[5][5];
char s[10100];
int multi(int x, int y) {
	int cnt = 0, ret;
	if (x < 0) x = -x, cnt++;
	if (y < 0) y = -y, cnt++;
	ret = mul[x][y];
	if (cnt % 2 == 1) ret = -ret;
	return ret;
}
int main() {
	freopen("C-large.in", "r", stdin);
	freopen("GCJ.out", "w", stdout);
	mul[1][1] = 1;
	mul[1][2] = 2;
	mul[1][3] = 3;
	mul[1][4] = 4;
	mul[2][1] = 2;
	mul[2][2] = -1;
	mul[2][3] = 4;
	mul[2][4] = -3;
	mul[3][1] = 3;
	mul[3][2] = -4;
	mul[3][3] = -1; 
	mul[3][4] = 2;
	mul[4][1] = 4;	
	mul[4][2] = 3;
	mul[4][3] = -2;
	mul[4][4] = -1;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		bool q = 0;
		scanf("%d%I64d", &l, &x);
		scanf("%s", s);
		x = min(x, 4 + 4 + x % 4);
		int cnt = 0, now = 1;
		while (x--) {
			for (int j = 0; j < l; j++) {
				now = multi(now, s[j] - 'i' + 2);
				if (cnt == 0) {
					if (now == 2 || now == -2) cnt++;
				}
				if (cnt == 1) {
					if (now == 4 || now == -4) cnt++;
				}
			}
		}
		if (cnt == 2 && now == -1) q = 1;
		printf("Case #%d: %s\n", i, ans[q]);
	}
	return 0;
}
