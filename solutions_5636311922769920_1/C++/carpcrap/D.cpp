#include <iostream>
#include <stdio.h>

int main(){
	int T;
	scanf("%d", &T);
	for(int tt =1; tt<=T; tt++){
		int k,c,s;
		scanf("%d %d %d",&k, &c, &s);
		printf("Case #%d:",tt);
		if(c*s < k){
			printf(" IMPOSSIBLE\n");
			continue;
		}
		int need = (k+s-1) / s;
		int cur = k;
		while(cur>0){
			long long test = --cur;
			for(int cc = 1;cc<c; cc++){
				test = test * k;
				if(cur>0) test+= --cur;
			}
			printf(" %lld", test+1);
		}
		printf("\n");
		// can skip printing excess S
	}
	return 0;
}
