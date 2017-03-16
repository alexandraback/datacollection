#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

int val[7];
int n, m, k;
int num[3];
int st[64];

void dfs(int dep)
{
	if (dep == n) {
		int p = 0;
		for (int i = 0; i < n; ++i) {
			p = p * (m - 1) + (num[i] - 2);
	//		printf("%d", num[i]);
		}
	//	printf("\np = %d\n", p);
		for (int i = 0; i < k; ++i) {
			int t = val[i];
			for (int j = 0; j < n && t != 1; ++j) {
				if (t % num[j] == 0) t /= num[j];
			}
	//		printf("(%d, %d) ", val[i], t == 1);
			st[p] += t == 1;
		}
	//	printf("\n");
		return;
	}
	for (int i = 2; i <= m; ++i) {
		num[dep] = i;
		dfs(dep + 1);
	}
}

int main() 
{
	freopen("C-small-1-attempt0.in", "r", stdin);
	freopen("jam.out", "w", stdout);
	int ncas;
	scanf("%d", &ncas);
	int r;
	for (int cas = 1; cas <= ncas; ++cas) {
		scanf("%d%d%d%d", &r, &n, &m, &k);
		printf("Case #1:\n");
		while (r--) {
			for (int i = 0; i < k; ++i) {
				scanf("%d", &val[i]);
			}
			memset(st, 0, sizeof(st));
			dfs(0);
			int p = 0;
			for (; p < 64 && st[p] != k; ++p);
			//printf("p = %d, st[p] = %d\n", p, st[p]);
			if (p == 64) {
				for (int i = 0; i < n; ++i) printf("2");
				printf("\n");
			} else {
				for (int i = 0; i < n; ++i) {
					printf("%d", p % (m - 1) + 2);
					p /= m - 1;
				}
				printf("\n");
			}
		}
	}
	//system("pause");
	return 0;
}
