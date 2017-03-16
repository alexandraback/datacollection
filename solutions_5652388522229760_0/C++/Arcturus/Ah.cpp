#include <stdio.h>
#include <string.h>

int main(){
	int jcase;
	long long N;
	bool sudah[10];
	int ctr, ctrSudah;
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	
	scanf("%d", &jcase);
	for(int icase=0; icase<jcase; icase++){
		scanf("%lld", &N);
		memset(sudah, 0, sizeof(sudah));
		ctr = 1;
		ctrSudah = 0;
		
		if(N == 0){ 
			printf("Case #%d: INSOMNIA\n", icase+1);
			continue;
		}
		while(1){
			long long now = N * ctr;
			
			while(now){
				int rem = now % 10;
				if(!sudah[rem]){
					sudah[rem] = true;
					ctrSudah++;
				}
				now = now / 10;
			}
			
			if(ctrSudah == 10) break;
			ctr++;
		}
		
		printf("Case #%d: %lld\n", icase+1, N * ctr);
	}
	
	return 0;
}
