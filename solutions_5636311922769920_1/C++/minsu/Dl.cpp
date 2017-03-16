#include <bits/stdc++.h>
using namespace std;
typedef long long lld;

int T, K, C, S;

int main(){
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		scanf("%d%d%d",&K,&C,&S);
		printf("Case #%d: ",t);
		if( S < (K+C-1)/C ){
			printf("IMPOSSIBLE\n");
			continue;
		}
		lld L = 1;
		for(int i=1; i<C; i++) L = L * K;
		
		bool com = false;
		for(int i=0; !com; ){
			lld S = 0, M = L;
			for(int j=0; j<C; j++, M /= K){
				S += M * i;
				if( !com ){
					i++;
					if( i == K ) i=0, com = true;
				}
			}
			printf("%lld ", S+1 );
		}
		printf("\n");
	}
	return 0;
}

