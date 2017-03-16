#include <bits/stdc++.h>

using namespace std;


const int MAXN = 2010;

char s[MAXN];
int cnt[300];
int ans[10];
char num[10][10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int need[10][300];
bool flag;

void check() {
	for (int i = (int)'A'; i <= (int)'Z'; i++) 
		if (cnt[i] != 0) return;
	flag = true;
}
void dfs(int p) {
	if (flag) return;
	if (p==10) {
		check();
		return;
	}
	int len = strlen(num[p]);
	int Max = MAXN;
	for (int i = 0; i < len; i++) Max = min(Max, cnt[(int)num[p][i]] / need[p][(int)num[p][i]]);
	for (int i = Max; i >= 0; i--) {
		ans[p] = i;
		for (int j = 0; j < len; j++) cnt[(int)num[p][j]] -= i;
		dfs(p+1);
		if (flag) return;
		for (int j = 0; j < len; j++) cnt[(int)num[p][j]] += i;
	}
}
void work() {
	memset(cnt, 0, sizeof(cnt));
	int len = strlen(s);
	for (int i = 0; i < len; i++) cnt[(int)s[i]]++;
	flag = false;
	dfs(0);
	for (int i = 0; i <= 9; i++)
		for (int j = 0; j < ans[i]; j++) printf("%d", i);
	puts("");
}

void init() {
	for (int i = 0; i <= 9; i++) {
		int len = strlen(num[i]);
		for(int j = 0; j < len; j++) need[i][(int)num[i][j]]++;
	}
}
int main() {
	init();
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; tt++) {
		scanf("%s", s);
		printf("Case #%d: ", tt);
		work();
	}
	return 0;
}
