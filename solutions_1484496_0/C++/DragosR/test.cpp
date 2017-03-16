#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>

const int maxv = 100000 * 30;

using namespace std;

int dp[maxv], tt[maxv];
int A[100], B[100];
int N, T;

int main() {

	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);

	scanf("%d\n", &T);

	for(int t = 1; t <= T ; ++t) {
		scanf("%d", &N);
		for(int i = 0; i < N; ++i)
			scanf("%d", &A[i]);
		
		
		bool ok = 0;
		for(int mask = 1; mask < (1 << N); ++mask) {
			int sum1 = 0;
			int b = 0;
			
			memset(dp, 0, sizeof(dp)) ; memset(tt, 0, sizeof(tt));
			B[0] = 0;
			for(int i = 0; i < N; ++i)
				if(mask & (1 << i)) 
					sum1 += A[i], b++; 
				else B[++B[0]] = i;
			if(b <= 1) continue;
			
//			printf("%d %d\n", sum1, mask);
			dp[0] = 1;
			
			for(; B[0] >= 1; B[0]--) {
				int i = B[B[0]] ; 
				for(int s = sum1; s >= 0; s--)
					if(dp[s]) {
						dp[s + A[i]] = 1;
						tt[s + A[i]] = i;
					}
				}
			if(dp[sum1]) {
				printf("Case #%d:\n", t);
				for(int i = 0; i < N; ++i)
					if(mask & (1 << i))
						printf("%d ", A[i]);
				printf("\n");
				while(sum1 > 0) {
					printf("%d ", A[tt[sum1]]) ;
					sum1 -= A[tt[sum1]];
				}
				printf("\n"); 
				ok = 1; break;
			}
		}
		if(!ok) {
			printf("Case #%d:\n", t);
			printf("Impossible\n");
		}
	}
	return 0;
}
