#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int main() {
	freopen("small.in","r",stdin);
	freopen("small.out","w",stdout);

	int T,cases,B,M;
	int has[60][60];
	scanf("%d ",&T);

	for (cases=1;cases<=T;cases++){
		scanf("%d %d", &B, &M);
		
		int n = B - 2;

		int maxi = 1;
		for (int i=0;i<n;i++) maxi *= 2;

		if (M > maxi) {
			printf( "Case #%d: IMPOSSIBLE\n",cases);
			continue;
		}
		printf( "Case #%d: POSSIBLE\n",cases);
		memset(has, 0, sizeof has);
		for (int i=1;i<B;i++) {
			for (int j=i+1;j<B;j++) {
				has[i][j] = 1;
			}
		}

		if (M == maxi) {
			has[0][B-1] = 1;
			M --;
		}

		for (int i=B-2; i>=1;i--) {
			int digit = M % 2;
			if (digit == 1) has[0][i] = 1;			
			M = M / 2;
		}

		for (int i=0;i<B;i++){
			for (int j=0;j<B;j++)
				printf("%d", has[i][j]);
			printf("\n");
		}



	}
}
