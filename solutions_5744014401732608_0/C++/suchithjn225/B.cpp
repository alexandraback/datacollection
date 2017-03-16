#include <bits/stdc++.h>
using namespace std;

typedef long long Long;
typedef unsigned long long Ulong;

const int MAXB = 55;
int adjMat[MAXB][MAXB];

Long pow2[MAXB];
int main() {
	int T; scanf("%d",&T);
	pow2[0] = 1;
	for (int i=1; i<MAXB; i++) {
		pow2[i] = pow2[i-1] * 2ll;
	}
	for (int tt=1; tt<=T; tt++) {
		int B; Long M;
		scanf("%d%lld",&B,&M);
		for (int i=0; i<B; i++) {
			for (int j=0; j<B; j++) {
				if (i >= j) adjMat[i][j] = 0;
				else adjMat[i][j] = 1;
			}
		}
		if (M > pow2[B-2]) {
			printf("Case #%d: IMPOSSIBLE\n",tt);
			continue;
		}
		Long remd = pow2[B-2]-M;
		for (int i=0; (1LL<<i)<=remd; i++) {
			if (remd & (1LL<<i)) {
				adjMat[i+1][B-1] = 0;
			}
		}
		printf("Case #%d: POSSIBLE\n",tt);
		for (int i=0; i<B; i++) {
			for (int j=0; j<B; j++)
				printf("%d",adjMat[i][j]);
			printf("\n");
		}
	}
	return 0;
}