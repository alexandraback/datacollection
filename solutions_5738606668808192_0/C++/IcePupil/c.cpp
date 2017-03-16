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
int n, m, p[1000], a[50], cnt, ans[20];

void check()
{
	for (int base = 2; base <= 10; base ++) {
		ans[base] = -1;
		for (int i = 0; i < m; i ++) {
			int r = 0;
			for (int j = 1; j <= n; j ++) {
				r = (r * base + a[j]) % p[i];
			}
			if (r == 0) {
				ans[base] = p[i];
				break;
			}
		}
		if (ans[base] == -1) return;
	}
	cnt --;
	for (int i = 1; i <= n; i ++) {
		printf("%d", a[i]);
	}
	for (int i = 2; i <= 10; i ++) {
		printf(" %d", ans[i]);
	}
	printf("\n");
}

void search(int k)
{
	if (cnt == 0) return;
	if (k == n) {
		check();
	} else {
		a[k] = 0;
		search(k + 1);
		a[k] = 1;
		search(k + 1);
	}
}

int main()
{
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	m = 0;
	for (int i = 2; i < 1000; i ++) {
		bool flag = true;
		for (int j = 2; j * j <= i; j ++)
		if (i % j == 0) {
			flag = false;
			break;
		}
		if (flag) {
			p[m ++] = i;
		}
	}
	int test, nCase = 0;
	scanf("%d", &test);
	while (test --) {
		scanf("%d%d", &n, &cnt);
		nCase ++;
		printf("Case #%d:\n", nCase);
		a[1] = 1;
		a[n] = 1;
		search(2);
	}
	return 0;
}
