/*
 * Problem : 
 * Author : Hwhitetooth
 * Date : 
 * Result :
 */

#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;

const int N = 1000;

int f[N], d[N];
queue<int> que;
int vis[N];
int dep[N];
int testCases, n;

int main() {
	scanf("%d", &testCases);
	for (int _ = 1; _ <= testCases; ++_) {
		scanf("%d", &n);
		fill(d, d + n, 0);
		for (int i = 0; i < n; ++i) {
			scanf("%d", f + i);
			++d[--f[i]];
		}

		fill(vis, vis + n, 0);
		fill(dep, dep + n, 0);
		for (int i = 0; i < n; ++i) {
			if (d[i] > 0 || vis[i]) {
				continue;
			}
			que.push(i);
			for (; !que.empty(); que.pop()) {
				int u = que.front();
				vis[u] = 1;
				++dep[u];
				--d[f[u]];
				dep[f[u]] = max(dep[f[u]], dep[u]);
				if (d[f[u]] == 0) {
					que.push(f[u]);
				}
			}
		}

		int ans = 0, two = 0;
		for (int i = 0; i < n; ++i) {
			if (vis[i]) {
				continue;
			}
			int cnt = 0;
			for (int u = i; !vis[u]; u = f[u]) {
				++cnt;
				vis[u] = 1;
			}
			if (cnt == 2) {
				cnt += dep[i] + dep[f[i]];
				two += cnt;
			} else {
				ans = max(ans, cnt);
			}
		}
		ans = max(ans, two);

		printf("Case #%d: %d\n", _, ans);
	}
	return 0;
}
