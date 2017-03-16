#include<iostream>
#include<sstream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<climits>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
using namespace std;

#define N 1100
int a[N], n, e[N][N], vst[N];

int dfs(int x) {
	vst[x] = 1;
	for (int i = 0; i < n; ++i) if (e[x][i]) {
		if (vst[i]) return 1;
		if (dfs(i)) return 1;
	} return 0;
}

void conduct() {
	int i, j, tmp, tot, cnt;
	scanf("%d", &n);
	memset(e, 0, sizeof(e));
	for (i = 0; i < n; ++i) {
		scanf("%d", &a[i]); for (j = 0; j < a[i]; ++j) { scanf("%d", &tmp); e[i][tmp-1] = 1; }
	} for (i = 0; i < n; ++i) { memset(vst, 0, sizeof(vst)); if (dfs(i)) { printf("Yes\n"); return; } }
	printf("No\n");
}

int main() {
	int time; scanf("%d", &time);
	for (int i = 1; i <= time; ++i) {
		printf("Case #%d: ", i); conduct();
	} return 0;
}
