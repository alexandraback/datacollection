#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;
const int maxn = 105;
const int N = 30;
const int mod = 1000000007;
typedef long long LL;

char s[maxn][maxn];
int jie[N], pre[N], nex[N], vis[N];
int fa[N], len;

bool judge(int i)
{
	len = strlen(s[i]);
	if(s[i][1] == 0) return 1;
	for(int j = 1; s[i][j+1]; j++)
		if(s[i][j] != s[i][0] && s[i][j] != s[i][len-1])
			return 0;
	return 1;
}

int find(int i)
{
	if(i != fa[i]) fa[i] = find(fa[i]);
	return fa[i];
}

int main()
{
	int T, nc = 0, n;
	cin >> T;
	while(T--)
	{
		printf("Case #%d: ", ++nc);
		memset(jie, 0, sizeof jie);
		memset(pre, 0, sizeof pre);
		memset(nex, 0, sizeof nex);
		memset(vis, 0, sizeof vis);
		for(int i = 0; i < N; i++) fa[i] = i;

		scanf("%d", &n);
		for(int i = 0; i < n; i++) scanf("%s", s[i]);

		bool ok = 1;
		for(int i = 0; i < n; i++) {
			if(!judge(i)) { ok = 0; break; }
			int l = s[i][0] - 'a';
			int r = s[i][len-1] - 'a';
			if(l == r) jie[l]++;
			else {
				if(nex[l]) { ok = 0; break; }
				if(pre[r]) { ok = 0; break; }
				nex[l] = r; pre[r] = l;
				int x = find(l), y = find(r);
				if(x == y) { ok = 0; break; }
				fa[x] = y;
				// printf("%d: %d %d_%d %d\n", i, x, y, l, r);
			}
		}
		if(ok == 0) { puts("0"); continue; }

		LL ans = 1;
		int num = 0;
		for(int i = 0; i < 26; i++) {
			int x = find(i);
			if(vis[x]) continue;
			vis[x] = 1;
			if(pre[i] || nex[i] || jie[i]) {
				num++;
				// cout << '-' << i << endl;
			}
		}
		// printf("num = %d\n", num);
		for(int i = 2; i <= num; i++)
			ans = (ans * i) % mod;
		for(int i = 0; i < 26; i++) {
			for(int j = 2; j <= jie[i]; j++)
				ans = (ans * j) % mod;
		}
		cout << ans << endl;
	}
	return 0;
}