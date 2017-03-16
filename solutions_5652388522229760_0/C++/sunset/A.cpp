#include <cstdio>
using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for(int NOWCASE=1; NOWCASE<=T; ++NOWCASE) {
		printf("Case #%d: ", NOWCASE);
		long long N;
		scanf("%lld", &N);
		if( N==0 ) {
			puts("INSOMNIA");
			continue;
		}
		long long i = 0;
		int digitCnt = 0, digit[10] = {};
		do {
			++i;
			long long tmp = N * i;
			while( tmp ) {
				if( digit[tmp%10] == 0 ) {
					digit[tmp%10] = 1;
					++digitCnt;
				}
				tmp /= 10;
			}
		} while( digitCnt != 10 );
		printf("%lld\n", N*i);
	}
	return 0;
}
