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

bool dp[1 << 20];
int path[1 << 20];
int n, k;
int key[20][201], kl[20], tk[20];
int keys[201];
int lis[20];

bool dfs(int x)
{
	if (!x) return true;
	if (dp[x]) return false;
	dp[x] = true;
	for (int i = 0; i < n; ++i) {
		if (!(x & (1 << i)) || !keys[tk[i]]) continue;
		for (int j = 0; j < kl[i]; ++j) {
			++keys[key[i][j]];
		}
		--keys[tk[i]];
		path[x] = i;
		if (dfs(x ^ (1 << i))) return true;
		++keys[tk[i]];
		for (int j = 0; j < kl[i]; ++j) {
			--keys[key[i][j]];
		}
	}
	return false;
}

int main() 
{
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("jam.out", "w", stdout);
	int ncas, t, ll;
	scanf("%d", &ncas);
	for (int cas = 1; cas <= ncas; ++cas) {
		fill_n(dp, 1 << n, false);
		fill_n(path, 1 << n, -1);
		fill_n(keys, 201, 0);
		scanf("%d%d", &k, &n);
		for (int i = 0; i < k; ++i) {
			scanf("%d", &t);
			++keys[t];
		}
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &tk[i], &kl[i]);
			for (int j = 0; j < kl[i]; ++j) {
				scanf("%d", &key[i][j]);
			}
		}
		printf("Case #%d:", cas);
		if (dfs((1 << n) - 1)) {
			t = (1 << n) - 1;
			ll = 0;
			while (t) {
				printf(" %d", path[t] + 1);
				t = t ^ (1 << path[t]);
			}
			printf("\n");
		} else {
			printf(" IMPOSSIBLE\n");
		}
	}
	//system("pause");
	return 0;
}
