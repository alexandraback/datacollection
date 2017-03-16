#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int F[1111];
bool vis[1111];

int st;
int mans = 0;
int n;

void dfs1(int x, int len){
	if (len > mans && F[x] == st)
		mans = len;
	if (!vis[F[x]]) {
		vis[F[x]] = true;
		dfs1(F[x], len+1);
		vis[F[x]] = false;
	}
	if (F[F[x]] == x)
		for (int i = 1; i <= n; i++)
			if (!vis[i]) {
				vis[i] = true;
				dfs1(i, len + 1);
				vis[i] = false;
			}

}

int main(){
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	int T; scanf("%d", &T);
	for (int cas = 1; cas <= T; cas++){
		printf("Case #%d: ", cas);
		memset(vis, 0, sizeof(vis));
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", F + i);
		mans = 0;
		for (int i = 1; i <= n; i++) {
			st = i;
			vis[i] = true;
			dfs1(i, 1);
			vis[i] = false;
		}
		printf("%d\n", mans);
	}
}