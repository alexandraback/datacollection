#include <cstdio>

int T,K,C,S;
long long printnum(int lf,int rg) {
	long long ret=0;
	for(int i=lf;i<=rg;i++) {
		if(i<K) {
			ret=ret*K+i;
		} else {
			ret=ret*K+K-1;
		}
	}
	return ret+1;
}
int main() {
	scanf("%d",&T);
	for(int ts=1;ts<=T;ts++) {
		scanf("%d%d%d",&K,&C,&S);
		if(C*S<K) {
			printf("Case #%d: IMPOSSIBLE\n",ts);
		} else {
			printf("Case #%d:",ts);
			for(int i=0;i<(K+C-1)/C;i++) {
				printf(" %lld",printnum(C*i,C*i+C-1));
			}
			printf("\n");
		}
	}
	return 0;
}
