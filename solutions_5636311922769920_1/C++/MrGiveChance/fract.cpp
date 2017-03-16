#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
	freopen("large.in","r",stdin);
	freopen("large.out","w",stdout);
	long long int T,K,C,S,cases;

	scanf("%lld ",&T);
	
	for (cases=1;cases<=T;cases++){
		scanf("%lld %lld %lld ", &K,&C,&S);
		if ( (K + C - 1) / C > S ) {
			printf("Case #%lld: IMPOSSIBLE\n",cases);
			continue;
		}
		printf("Case #%lld:",cases);

		for (int i=0;i<K;i+=C){
			long long int num = 0;

			for (int j=0;j<C;j++) {
				int position = i + j;
				// printf("position: %d",position);
				if (position >= K) position = K-1;

				num = num * K + position;
			}
			printf(" %lld",num+1);
		}
		printf("\n");
	}
}