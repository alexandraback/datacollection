//author: whd

#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
#include <map>

#define mp make_pair
#define pb push_back
#define x first
#define y second

using namespace std;
typedef long long big;

typedef pair<int, int> pii;
int cnt[2600];
int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int cas, cass;
	scanf("%d", &cas);
	int n, i, j, k;
	for (cass = 1; cass <= cas; cass++) {
		memset(cnt, 0, sizeof(cnt));
		printf("Case #%d: ", cass);
		scanf("%d", &n);
		for (i = 1; i < n * 2; i++) {
			for (j = 1; j <= n; j++) {
				scanf("%d", &k);
				cnt[k]++;
			}
		}
		vector<int> ans;
		for (i = 1; i <= 2500; i++) {
			if (cnt[i] & 1)
				ans.push_back(i);
		}
		for (i = 0; i < ans.size(); i++) {
			if (i)
				printf(" ");
			printf("%d", ans[i]);
		}
		printf("\n");
	}
	fclose(stdin);
	fclose(stdout);
}

