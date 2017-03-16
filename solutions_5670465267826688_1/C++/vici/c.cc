#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int const N = 10010;
int const mp[4][4] = {
	1, 2, 3, 4,
	2, -1, 4, -3,
	3, -4, -1, 2,
	4, 3, -2, -1
};

int f(int x, int y) {
	int z = x * y > 0 ? 1 : -1;
	int tx = max(x, -x);
	int ty = max(y, -y);
	return mp[tx - 1][ty - 1] * z;
}
char s[N * 33];

int main() {
	//freopen("C-small-attempt1.in", "r", stdin);
	//freopen("C-small-ans1.txt", "w", stdout);
	freopen("C-large.in", "r", stdin);
	freopen("C-large-ans.txt", "w", stdout);
	int T, ca = 1;
	int l; ll x;
	for (scanf("%d", &T); T--; ) {
		scanf("%d%I64d", &l, &x);
		scanf(" %s", s);
		int m = l * min(x, x % 12 + 12LL);
		for (int i = l; i < m; ++i) {
			s[i] = s[i - l];
		}
		bool foundI = 0;
		bool foundJ = 0;
		int now = 1;
		for (int i = 0; i < m; ++i) {
			int t;
			if (s[i] == 'i') t = 2;
			else if (s[i] == 'j') t = 3;
			else t = 4;
			now = f(now, t);
			if (!foundI) {
				if (now == 2) foundI = 1;
			} else if (!foundJ) {
				if (now == 4) foundJ = 1;
			}
		}
		if (foundJ && now == -1) {
			printf("Case #%d: YES\n", ca++);
		} else {
			printf("Case #%d: NO\n", ca++);
		}
	}
	return 0;
}

