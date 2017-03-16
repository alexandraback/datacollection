#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define FOR(i,l,r) for(int i=(l);i<=(r);i++)
using namespace std;
typedef long long LL;

bool vis[10];
void clear() {
	memset(vis,0,sizeof vis);
}
bool yes(LL n) {
	while (n) {
		vis[n%10]=1;
		n/=10;
	}
	return vis[0]&vis[1]&vis[2]&vis[3]&vis[4]
	       &vis[5]&vis[6]&vis[7]&vis[8]&vis[9];
}
int main() {
	int T; scanf("%d",&T);
	for (int tt=1;tt<=T;tt++) {
		LL n; scanf("%lld",&n);
		printf("Case #%d: ",tt);
		if (n==0) {
			printf("INSOMNIA\n");
			continue;
		}

		clear();
		bool flag=0;
		for (LL i=1;i<=1000000;i++)
			if (yes(i*n)) {
				flag=1;
				printf("%lld\n",i*n);
				break;
			}
		if (!flag) puts("INSOMNIA");
	}
	return 0;
}