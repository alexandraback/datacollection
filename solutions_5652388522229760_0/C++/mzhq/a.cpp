#include <bits/stdc++.h>
#define ll long long
#define mst(a,x) memset(a,x,sizeof(a))
#define For(i, t) for(int i = 0; i < t; i++)
#define Debug(x) cerr << #x << " = "  << x << endl;
using namespace std;

bool vis[10];
int main() {
	int ans, T, x, tot;

	freopen("ggout.txt", "w", stdout);
	scanf("%d", &T);
	For(cas, T) {
		scanf("%d", &x);
		if(!x) {
			printf("Case #%d: INSOMNIA\n", cas + 1);
			continue;
		}

		tot = 0;
		mst(vis, 0);
		for(ans = x; ;ans += x) {
			int tmp = ans;
			do{
				int d = tmp % 10;
				if(!vis[d]) {
					tot++;
					vis[d] = 1;
				}
				tmp /= 10;
			}while(tmp);
			if(tot == 10) break;
		}
		printf("Case #%d: %d\n", cas + 1, ans);
	}
	return 0;
}
