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
int n, a[200][60], cnt[3000];

int main()
{
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);
	int test, nCase = 0;
	scanf("%d", &test);
	while (test --) {
		scanf("%d", &n);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1; i < 2 * n; i ++) {
			for (int j = 0; j < n; j ++) {
				scanf("%d", &a[i][j]);
				cnt[a[i][j]] ++;
			}
		}
		nCase ++;
		printf("Case #%d:", nCase);
		for (int i = 0; i < 3000; i ++)
		if (cnt[i] % 2 == 1) {
			printf(" %d", i);
		}
		printf("\n");
	}
	return 0;
}
