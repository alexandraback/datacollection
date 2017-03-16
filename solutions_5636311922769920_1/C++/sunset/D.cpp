#include <cstdio>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for(int NOWCASE=1; NOWCASE<=T; ++NOWCASE) {
		int K, C, S;
		scanf("%d%d%d", &K, &C, &S);
		printf("Case #%d:", NOWCASE);
		if( K==1 ) {
			puts(" 1");
			continue;
		}
		int pick=0;
		long long pre=0;
		for(int i=1; i<C; ++i) {
			pre = (pre+pick%K) * (long long)K;
			if( pick<K )
				++pick;
		}
		if( K-pick > S )
			puts(" IMPOSSIBLE");
		else if( pick >= K )
			printf(" %lld\n", pre+1);
		else {
			for(int i=pick; i<K; ++i)
				printf(" %lld", pre + i + 1);
			puts("");
		}
	}
	return 0;
}
