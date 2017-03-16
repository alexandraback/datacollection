#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int tc, h, w, a[105][105], mh[105], mw[105];
bool canH[105][105], canW[105][105];
int main () {
	scanf("%d", &tc);
	for (int t = 1; t<=tc; ++t) {
		scanf("%d%d", &h, &w);
		memset(mw, 0, sizeof(mw));
		memset(mh, 0, sizeof(mh));
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				scanf("%d", &a[i][j]);
				mh[i] = max(mh[i], a[i][j]);
				mw[j] = max(mw[j], a[i][j]);
			}
		}
		bool ans = true;
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				canH[i][j] = (a[i][j] == mh[i]);
				canW[i][j] = (a[i][j] == mw[j]);
				if (!canH[i][j] && !canW[i][j]) ans = false;
			}
		}
		printf("Case #%d: ", t);
		if (ans) printf("YES\n");
		else printf("NO\n");
	}

}