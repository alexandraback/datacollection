#include <cstdio>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for(int NOWCASE=1; NOWCASE<=T; ++NOWCASE) {
		int K, C, S;
		scanf("%d%d%d", &K, &C, &S);
		printf("Case #%d:", NOWCASE);
		for(int i=0; i<S; ++i) {
			long long pre=i;
			for(int j=1; j<C; ++j)
				pre *= K;
			printf(" %lld", pre + 1);
		}
		puts("");
	}
	return 0;
}
