#include <stdio.h>

int main(){
	int T;
	int a, b, k;
	scanf("%d", &T);
	for(int t=1; t<=T; ++t){
		scanf("%d%d%d", &a, &b, &k);
		int ans = 0;
		for(int i=0; i<a; ++i){
			for(int j=0; j<b; ++j){
				if((i&j) < k) ++ans;
			}
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}

