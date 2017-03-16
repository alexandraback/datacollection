#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
// head
bool vis[15];
int cnt;

void add(LL x) {
	while (x) {
		int cur = x % 10;
		if (!vis[cur]) cnt--, vis[cur] = true;
		x /= 10;
	}
}
int main() {
	int t, n, cas = 1;
	scanf("%d", &t);
	freopen("output.txt", "w", stdout);
	while (t--) {
		memset(vis, 0, sizeof vis);
		cnt = 10;
		scanf("%d", &n);
		printf("Case #%d: ", cas++);
		if (n == 0) {
			puts("INSOMNIA");
		} else {
			LL cur = n;
			for (int i = 0; ; i++) {
				add(cur);
				if (cnt == 0) {
					printf("%I64d\n", cur);
					break;
				}
				cur += n;
			}
		}
	}
	return 0;
}
