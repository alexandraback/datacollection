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
int a[maxn], d[maxn];

int main() {
	int cases;
	scanf("%d", &cases);
	for (int o = 0; o < cases; ++o) {
		int n, ans = 1;
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
		for (int i = 0; i < n; ++i) {
			if (a[a[i]] == i) {
				ans = max(ans, d[i] + d[a[i]] + 2);
			}
		}
		//for (int i = 0; i < n; ++i) cerr<<d[i]<<" ";
		//cerr<<endl;
		for (int i = 0; i < n; ++i) {
			memset(vis, 0, sizeof(vis));
			vis[i] = 1;
			int x = a[i], y = 2, z = i;
			while (!vis[x]) {
				if (a[x] == i) {
					ans = max(ans, y);
					//cerr<<i<<" "<<y<<endl;
				}
			/*	if (a[x] == z) {
					ans = max(ans, y + d[x]);
					cerr<<i<<" "<<y + d[x]<<endl;
				}*/
				vis[x] = 1;
				z = x;
				x = a[x];
				++y;
			}
		}
		printf("Case #%d: %d\n", o + 1, ans);
	}
	return 0;
}


