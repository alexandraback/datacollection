#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int K,C,S;

void solve() {
	scanf("%d%d%d",&K,&C,&S);
    if (S==K) {
		for (int i=0;i<K;i++) {
			ll cur = i;
			for (int j=0;j<C-1;j++) cur*=K;
			printf("%lld ",1+cur);
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
