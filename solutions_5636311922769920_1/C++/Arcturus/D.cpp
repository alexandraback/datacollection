#include <stdio.h>

int main(){
	int jcase;
	int K, C, S;
	
	freopen("D-large.in", "r", stdin);
	freopen("D-large.out", "w", stdout);
	
	scanf("%d", &jcase);
	for(int icase=0; icase<jcase; icase++){
		scanf("%d %d %d", &K, &C, &S);
		int minS = (K-1) / C + 1;
		
		if(minS > S){
			printf("Case #%d: IMPOSSIBLE\n", icase+1);
			continue;
		}
		
		printf("Case #%d:", icase+1);
		for(int i=0; i<minS; i++){
			int begn = i*C;
			long long n = begn;
			for(int j=1; j<C; j++){
				n = n * K;
				if(begn+j < K) n += (begn+j);
			}
			printf(" %lld", n+1);
		}
		printf("\n");
	}
	return 0;
}
