#include <cstdio>

long long vt[10100];
//long long dp[10100][10100];

long long best(long long maxE, long long E, long long R, long long N, long long i) {
	if (E > maxE) E=maxE;
	if (i == N) return 0;	
	
	long long b=0;
	int e;
	//for (n=i; n < N; n++) {
		for (e=0; e <= E; e++) {
			long long r = vt[i]*e + best(maxE,E-e+R,R,N,i+1);
			if (r > b) b=r;
		}
	//}
	return b;

}

int main() {
	int T;
	scanf("%d", &T);
	int i;
	
	for (i=0; i < T; i++) {
		long long E,R,N; // E=max energy (and initial), R=regained energy after activity, N=number of activities
		scanf("%lld %lld %lld", &E, &R, &N);
		//long long maxE = E;
		
		int j;
		for (j=0; j < N; j++) {
			scanf("%lld", &vt[j]);
		}
		
		printf("Case #%d: %lld\n", i+1, best(E,E,R,N,0));
	}
	
	return 0;
}
