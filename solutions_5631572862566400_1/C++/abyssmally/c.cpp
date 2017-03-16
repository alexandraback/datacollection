#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define N 1234

int cases;
int n, a[N];
vector<int> al[N];
char s[N];
int dfs(int at, int blk) {
	int ans = 0;
	for (int to : al[at]) if (to != blk) ans = max(ans, dfs(to, blk));
	return ans + 1;
}
int dfs2(int at, int blk, int blk2) {
	int ans = 0;
	for (int to : al[at]) if (to != blk && to != blk2) ans = max(ans, dfs2(to, blk, blk2));
	return ans + 1;
}
int main() {
	freopen("c.in", "r", stdin);
	freopen("c.out", "w", stdout);
	scanf("%d", &cases);
	fo(_case,1,cases+1) {
		printf("Case #%d: ", _case);
		scanf("%d", &n);
		fo(i,0,n) {
			al[i].clear();
		}
		fo(i,0,n) {
			scanf("%d", a+i); a[i]--;
			al[a[i]].push_back(i);
		}
		int lng = 1, cnt = 0, cnt2 = 0;
		fo(i,0,n) {
			int at = i, length = 0;
			while (length == 0 || at != i) {
				at = a[at]; length++;
				if (length == n+2) break;
			}
			if (at == i) lng = max(lng, length);
		}
		fo(i,0,n) if (a[i] > i && a[a[i]] == i) {
			cnt2 += dfs2(i, i, a[i]) + dfs2(a[i], i, a[i]);
		}
		printf("%d\n", max(cnt2, max(lng, cnt)));
	}

	return 0;
}