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

int lown[101][101];

int main() 
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("jam.out", "w", stdout);
	int ncas, n, m;
	scanf("%d", &ncas);
	for (int cas = 1; cas <= ncas; ++cas) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				scanf("%d", &lown[i][j]);
			}
		}
		bool fail = false;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				int k = lown[i][j], l = 0;
				bool chk1 = false, chk2 = false;
				for (; l < n && lown[l][j] <= k; ++l);
				if (l < n) chk1 = true;
				for (l = 0; l < m && lown[i][l] <= k; ++l);
				if (l < m) chk2 = true;
				//printf("i = %d, j = %d, chk1 = %d, chk2 = %d\n", i, j, chk1, chk2);
				fail = (chk1 && chk2);
				if (fail) break;
			}
			if (fail) break;
		}
		printf("Case #%d: ", cas);
		if (fail) puts("NO");
		else puts("YES");
	}
	//system("pause");
	return 0;
}
