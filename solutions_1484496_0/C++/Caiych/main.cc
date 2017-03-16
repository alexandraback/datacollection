#include <stdio.h>
#include <cstring>

using namespace std;

const int maxdp = 1000000;

int dp[maxdp],pre[maxdp];
int a[30],T,n;

bool ttt;


void out(int x) {
	if (x == 0) return;
	if (pre[x] != 0) 
		out(pre[x]);
	if (ttt) {
		ttt = true;
		printf(" %d",x - pre[x]);
	} else {
		ttt = true;
		printf("%d",x - pre[x]);
	}
}

int main() {
	scanf("%d",&T);
	for (int cas = 1;cas <= T;cas++) {
		scanf("%d",&n);
		memset(pre,0,sizeof(pre));
		memset(dp,-1,sizeof(dp));
		dp[0] = 0;
		for (int i = 0;i < n;i++) {
			scanf("%d",&a[i]);
		}
		printf("Case #%d:\n",cas);
		bool ans = false;
		for (int i = 0;i < n;i++) {
			if (ans) break;
			for (int j = maxdp - 1;j >= 0;j--) 
				if (dp[j] >= 0) {
					if (dp[j + a[i]] != -1) {
						ttt = false;
						out(j);
						if (ttt) printf(" %d\n",a[i]);
						else printf("%d\n",a[i]);
						ttt = false;
						out(j+a[i]);
						printf("\n");
						ans = true;
						break;
					}
					dp[j+a[i]] = 0;
					pre[j+a[i]] = j;
				}
		}
		if (!ans) printf("Impossible\n");
	}
	return 0;
}
