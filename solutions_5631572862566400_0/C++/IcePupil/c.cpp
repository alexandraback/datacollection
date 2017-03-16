#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
int n, ans, f[1000], p[1000];
bool used[1000];

bool check(int n)
{
	for (int i = 0; i < n; i ++) {
		int j = f[p[i]];
		bool flag = false;
		if (p[(i + 1) % n] == j) flag = true;
		if (p[(i - 1 + n) % n] == j) flag = true;
		if (!flag) return false;
	}
	return true;
}

void search(int k)
{
	if (k > ans && check(k)) {
		ans = k;
	}
	for (int i = 1; i <= n; i ++)
	if (!used[i]) {
		used[i] = true;
		p[k] = i;
		search(k + 1);
		used[i] = false;
	}
}

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	int nCase = 0, test;
	scanf("%d", &test);
	while (test --) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &f[i]);
		}
		ans = 0;
		memset(used, false, sizeof(used));
		search(0);
		nCase ++;
		printf("Case #%d: %d\n", nCase, ans);
	}
	return 0;
}
