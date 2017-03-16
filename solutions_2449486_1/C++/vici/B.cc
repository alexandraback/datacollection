#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
using namespace std;
int const maxn = 110;
typedef long long ll;
int mp[maxn][maxn];
int arr[maxn * maxn];
int const dir[4][2] = { 0, 1, 0, -1, 1, 0, -1, 0 };
int n, m;
bool rc[maxn], hc[maxn];
int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	int T, ca = 1;
	for (scanf("%d", &T); T--; ) {
		scanf("%d%d", &n, &m);
		int cnt = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("%d", &mp[i][j]);
				arr[cnt++] = mp[i][j];
			}
		}
		sort(arr, arr + cnt);
		int cc = 1;
		for (int i = 1; i < cnt; ++i) {
			if (arr[i] != arr[i - 1]) arr[cc++] = arr[i];
		}
		
		int pos = 0;
		while (pos + 1 < cc) {
			bool fd = false;
			memset(rc, 0, sizeof rc);
			memset(hc, 0, sizeof hc);
			for (int i = 0; i < n; ++i) {
				bool ff = true;
				for (int j = 0; j < m; ++j) {
					if (mp[i][j] != arr[pos]) {
						ff = false;
						break;
					}
				}
				if (ff) hc[i] = true;
			}
			for (int i = 0; i < m; ++i) {
				bool ff = true;
				for (int j = 0; j < n; ++j) {
					if (mp[j][i] != arr[pos]) {
						ff = false;
						break;
					}
				}
				if (ff) rc[i] = true;
			}
			for (int i = 0; i < n; ++i) {
				if (hc[i]) {
					fd = true;
					for (int j = 0; j < m; ++j) {
						mp[i][j] = arr[pos + 1];
					}
				}
			}
			for (int i = 0; i < m; ++i) {
				if (rc[i]) {
					fd = true;
					for (int j = 0; j < n; ++j) {
						mp[j][i] = arr[pos + 1];
					}
				}
			}
			if (!fd) break;
			++pos;
		}
		bool flag = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (mp[i][j] != arr[cc - 1]) {
					flag = false;
				}
			}
		}
		if (flag) printf("Case #%d: YES\n", ca++);
		else printf("Case #%d: NO\n", ca++);
	}
    return 0;
}

