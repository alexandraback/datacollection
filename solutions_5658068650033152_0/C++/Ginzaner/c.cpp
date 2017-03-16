#include <cstdio>

using namespace std;

int main() {
	int T;
	scanf("%d", &T);
	for(int k = 1; k<=T; k++) {
		printf("Case #%d: ", k);
		
		int N,M,K;
		scanf("%d %d %d", &N, &M, &K);
		
		if(N <= 2 || M <= 2 || K <= 4) printf("%d\n", K);
		
		int num = 0;
		int k1 = 3;
		int k2 = 3;
		
		while(num < K) {
			num = k*k2-4;
			if(k1 == N && k2 == M) break;
			if(k1 == N) k2++;
			else if(k2 == M) k1++;
			else if(k1 < k2) k1++;
			else k2++;
		}
		
		if(num < K) printf("%d\n", k1+k2+ 4-(M*N-K));
		else {
			printf("%d\n", k1+k2);
		}
	}
}
