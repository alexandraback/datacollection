#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>

#define ll unsigned long long
using namespace std;

const int maxn = 200;
int T, N, M, A[200], B[200];
long long d[200][200];
ll cantA[maxn], cantB[maxn];
int main() {

	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);


	scanf("%d\n", &T) ;
	
	for(int t = 1; t <= T; ++t) {
		scanf("%d %d\n", &N, &M);
		for(int i = 1; i <= N; ++i)
			scanf("%lld %d", &cantA[i], &A[i]);
		for(int j = 1; j <= M; ++j)
			scanf("%lld %d", &cantB[j], &B[j]);
		
		memset(d, 0, sizeof(d));
		for(int i = 1; i <= N; ++i) {
			for(int j = 1; j <= M; ++j) {
				d[i][j] = max(d[i][j - 1], max(d[i - 1][j], d[i][j]));
				if(A[i] == B[j]) {
					ll gain = min(cantA[i], cantB[j]) ; 
					cantA[i] -= gain ; cantB[j] -= gain ; 
					d[i][j] += gain ;
				}
			}
		}
		printf("Case #%d: ", t);
		printf("%llu\n", d[N][M]);
	}

	return 0;
}
	
					

		
