#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;
const int N = 200;
int n, ans;
int c[N], a[N];

void dfs(int now, int first, int last, int k1, int k2) {
	if ((k1 == 1 || last == a[first]) && (k2 == 1 || first == a[last]))
			ans = max(ans, now);
	for (int i = 1; i <= n; i++)
		if (c[i] == 0) {
			if (k2 == 0 && a[last] != i) continue;
			c[i] = 1;
			if (last == a[i])
				dfs(now + 1, first, i, k1, 1);
			else
				dfs(now + 1, first, i, k1, 0);
			c[i] = 0;
		}
}

int main() {
	int o, cas = 0;
	scanf("%d", &o);
	while (o--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		memset(c, 0, sizeof(c));
		ans = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++) if (i != j) {
				c[i] = 1;
				c[j] = 1;
				if (j == a[i]) {
					if (i == a[j])
						dfs(2, i, j, 1, 1);
					else
						dfs(2, i, j, 1, 0);
				} else {
					if (i == a[j])
						dfs(2, i, j, 0, 1);
					else
						dfs(2, i, j, 0, 0);
				}
				c[i] = 0;
				c[j] = 0;
			}
			
		printf("Case #%d: %d\n", ++cas, ans);
	}
}