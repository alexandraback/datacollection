#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>

using namespace std;


int used[5555];
int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int cas, cases;
	scanf("%d", &cas);
	for (cases = 1; cases <= cas; cases ++) {
		vector<int> ans;
		memset(used, 0, sizeof used);
		int n;
		scanf("%d", &n);
		for (int i = 1; i <= 2 * n - 1; i++)
			for (int j = 1; j <= n; j++) {
				int x;
				scanf("%d", &x);
				used[x] ++;
			}
		for (int i = 1; i <= 2500; i++)
			if (used[i] & 1)
				ans.push_back(i);
		printf("Case #%d:", cases);
		for (int i = 0; i < ans.size(); i++)
			printf(" %d", ans[i]);
		printf("\n");
	}
}
