#include <iostream>
#include <cstdio>
#include <cstring>  
#include <string>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <bitset>

using namespace std;

const int maxn = 1005;

bool vis[maxn];
int a[maxn], d[maxn], tag[maxn], b[maxn];

int main() {
	int cases;
	scanf("%d", &cases);
	for (int o = 0; o < cases; ++o) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &a[i]);
			--a[i];
		}
		memset(d, 0, sizeof(d));
		for (int i = 0; i < n; ++i) {
			memset(vis, 0, sizeof(vis));
			vis[i] = 1;
			int x = a[i], y = 1, z = i;
			while (!vis[x]) {
				vis[x] = 1;
				if (a[x] != z) d[x] = max(d[x], y);
				++y;
				z = x;
				x = a[x];
			}
		}
		memset(tag, 0, sizeof(tag));
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			memset(vis, 0, sizeof(vis));
			vis[i] = 1;
			int x = a[i], y = 2, z = i;
			b[0] = i, b[1] = x;
			while (!vis[x]) {
				if (a[x] == i) {
					ans = max(ans, y);
				}
				vis[x] = 1;
				z = x;
				x = a[x];
				b[y] = x;
				++y;
			}
		}
		for (int i = 0; i < n; ++i) {
			if (a[a[i]] == i) {
				tag[i] = d[i] + d[a[i]] + 2;
				tag[a[i]] = 0;
			}
		}
		int sum = 0;
		for (int i = 0; i < n; ++i) {
			if (tag[i] != -1) {
				sum += tag[i];
			}
		}
		ans = max(ans, sum);
		printf("Case #%d: %d\n", o + 1, ans);
	}
	return 0;
}


