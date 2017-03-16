#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
char mp[111][111];
int main() {
	freopen("C-small-attempt0.in", "r", stdin);
	freopen("C-out.txt", "w", stdout);
	int T, ca = 0, m, r, c;
	for (scanf("%d", &T); T--; ) {
		scanf("%d%d%d", &r, &c, &m);
		rep(i, r) rep(j, c) mp[i][j] = '.';
		rep(i, r) mp[i][c] = 0;
		printf("Case #%d:\n", ++ca);
		if (r == 1 || c == 1) {
			mp[0][0] = 'c';
			for (int i = r - 1; i >= 0; --i) {
				for (int j = c - 1; j >= 0; --j) {
					if (m == 0) break;
					--m; mp[i][j] = '*';
				}
			}
			rep(i, r) puts(mp[i]);
		} else {
			int rem = r * c - m;
			if (rem == 1) {
				rep(i, r) rep(j, c) mp[i][j] = '*';
				mp[0][0] = 'c';
				rep(i, r) puts(mp[i]);
				continue;
			}
			if (rem == 2 || rem == 3 || rem == 5 || rem == 7) {
				puts("Impossible");
				continue;
			}
			if ((r == 2 || c == 2) && (rem % 2 == 1)) {
				puts("Impossible");
				continue;
			}
			rep(i, r) rep(j, c) mp[i][j] = '*';
			for (int k = 2; k <= c; ++k) {
				for (int h = 2; h <= r; ++h) {
					if (k == 2) {
						if (h + h == rem) {
							rep(i, h) rep(j, k) mp[i][j] = '.';
							mp[0][0] = 'c';
							goto __skip;
						}
					} else {
						for (int h2 = 2; h2 <= h; ++h2) {
							int remt = rem - h - h - h2;
							int kt = k - 3;
							if (remt < 0) continue;
							if (kt == 0 && remt == 0) {
								rep(i, h) rep(j, 2) mp[i][j] = '.';
								rep(i, h2) mp[i][k - 1] = '.';
								mp[0][0] = 'c';
								goto __skip;
							}
							if (kt * h2 <= remt && kt * h >= remt) {
								int mid = remt / kt, midm = remt % kt;
								rep(i, h) rep(j, 2) mp[i][j] = '.';
								rep(i, h2) mp[i][k - 1] = '.';
								for (int j = 2; j < k - 1; ++j) {
									rep(i, mid) mp[i][j] = '.';
									if (midm > 0) {
										--midm;
										mp[mid][j] = '.';
									}
								}
								mp[0][0] = 'c';
								goto __skip;
							}
						}
					}
				}
			}
		__skip:;
	   	rep(i, r) puts(mp[i]);
		}
	}
	return 0;
}

