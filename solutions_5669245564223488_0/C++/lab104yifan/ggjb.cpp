#include <stdio.h>
#include <string.h>

const int MOD = 1000000007;
int n, t, vis[105], count[30];
char str[105][105];

bool check(int i) {
    int vv[30];
    memset(vv, 0, sizeof(vv));
    int len = strlen(str[i]);
    for (int j = 0; j < len ;j++) {
    	if (vv[str[i][j] - 'a'] && j != 0 && str[i][j] != str[i][j - 1]) {
	    return false;
	}
	vv[str[i][j] - 'a']++;
    }
    return true;
}

bool judge(int i, int wei) {
    int vv[30];
    memset(vv, 0, sizeof(vv));
    int len = strlen(str[i]);
    int j;
    for (j = 0; j < len; j++) {
	if (vv[str[i][j] - 'a'] && j != 0 && str[i][j] != str[i][j - 1]) {
	    return false;
	}
	vv[str[i][j] - 'a']++;
    }
    for (j = 0; j < len; j++) {
	if (str[i][j] - 'a' != wei)
	    break;
    }
    for (;j < len; j++) {
	if (count[str[i][j] - 'a']) return false;
    }
    return true;
}

int dfs(int num, int wei) {
    if (num == n) {
	return 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
	if (vis[i]) continue;
	if (!judge(i, wei)) continue;
	vis[i] = 1;
	int len = strlen(str[i]);
	for (int j = 0; j < len; j++)
	    count[str[i][j] - 'a']++;
	int t = dfs(num + 1, str[i][len - 1] - 'a');
	ans = (ans + t) % MOD;
	for (int j = 0; j < len; j++)
	    count[str[i][j] - 'a']--;
	vis[i] = 0;
    }
    return ans;
}

int main() {
    int cas = 0;
    scanf("%d", &t);
    while (t--) {
	memset(vis, 0, sizeof(vis));
	memset(count, 0, sizeof(count));
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	    scanf("%s", str[i]);
	int ans = 0;
	for (int i = 0; i < n; i++) {
	    memset(count, 0, sizeof(count));
	    memset(vis, 0, sizeof(vis));
	    if (!check(i)) continue;
	    vis[i] = 1;
	    int len = strlen(str[i]);
	    for (int j = 0; j < len; j++)
		count[str[i][j] - 'a']++;
	    int t = dfs(1, str[i][len - 1] - 'a');
	    ans = (ans + t) % MOD;
	    vis[i] = 0;
	}
	printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}
