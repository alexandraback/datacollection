#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int K,C,S;

void solve() {
	scanf("%d%d%d",&K,&C,&S);
	if (S*C<K) printf("IMPOSSIBLE");
	else {
		int on = 1;
		while (on<=K) {
			ll cur = 0;
			for (int i=0;i<C;i++) {
				cur*=K;
				if (on<=K) cur+=(on-1);
				on+=1;
			}
			printf("%lld ",cur+1);
		}
	}
    printf("\n");
}

int main() {
	freopen("D.in","r",stdin);
	freopen("D.out","w",stdout);
	int T;
	scanf("%d",&T);
	for (int t=1;t<=T;t++) {
		printf("Case #%d: ",t);
		solve();
	}

	return 0;
}
