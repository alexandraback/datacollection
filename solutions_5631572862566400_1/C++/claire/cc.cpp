#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>

using namespace std;
typedef long long ll;
const int N = 1200;
int n, ans;
int c[N], a[N], p[N];

int find(int k) {
	memset(c, 0, sizeof(c));
	int now = k;
	int cnt = 0;
	c[now] = 1;
	while (1) {
		now = a[now];
		cnt++;
		if (c[now]) {
			if (now == k) return cnt;
			else return 0;
		}
		c[now] = 1;
	}
	return 0;
}

int cal(int k) {
	if (p[k] != 0)
		return p[k];
	int ans = 1;
	for (int i = 1; i <= n; i++)
		if (a[i] == k && a[k] != i)
			ans = max(ans, cal(i) + 1);
	p[k] = ans;
	return ans;
}

int main() {
	int o, cas = 0;
	scanf("%d", &o);
	while (o--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		memset(p, 0, sizeof(p));
		ans = 0;
		for (int i = 1; i <= n; i++)
			ans = max(ans, find(i));
		int s = 0;
		for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++)
				if (a[i] == j && a[j] == i) {
					s += cal(i) + cal(j);
				}
		ans = max(ans, s);
		printf("Case #%d: %d\n", ++cas, ans);
	}
}