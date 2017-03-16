#include <cstdio>
using namespace std;
typedef long long ll;

int T, K, C, S;

ll pw (int x, int y) {
	ll ans = 1;
	for (int i=1;i<=y;++i) ans *= x;
	return ans;
}

int main () {
	scanf("%d",&T);
	for (int z=1;z<=T;++z) {
		scanf("%d %d %d",&K,&C,&S);
		printf("Case #%d: ", z);
		if (K == 1) printf("1\n");
		else if (C == 1) {
			if (S < K) printf("IMPOSSIBLE\n");
			else {
				for (int i=1;i<K;++i) printf("%d ",i);
				printf("%d\n",K);
			}
		}
		else if ((K+1)/2 <= S) {
			for (int i=1;i<=(K+1)/2;++i) {
				if (i == (K+1)/2 && K%2 == 1) printf("%lld",(i-1)*pw(K,C-1) + 1);
				else printf("%lld", (i-1) * pw(K,C-1) + i + (K+1)/2);
				if (i == (K+1)/2) printf("\n");
				else printf(" ");
			}
		}
		else printf("IMPOSSIBLE\n");
	}
	return 0;
}
