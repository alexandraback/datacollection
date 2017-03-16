#include <stdio.h>

int a[1000], b[1000];

int main(){
	int T;
	scanf("%d", &T);
	for(int TT = 1; TT<=T; TT++){
		int n;
		scanf("%d", &n);
		for(int i=0;i<n;i++)
			scanf("%d%d", &a[i], &b[i]);
		int star[1000]={0};
		int all = 0;
		int times = 0;
		bool ok = true;
		while(all < n*2){
			bool changed = false;
			for(int i=0;i<n;i++){
				if(b[i] <= all && star[i]!=2){
					all += 2-star[i];
					star[i] = 2;
					changed = true;
					times++;
				}
			}
			if(!changed){
				int maxi = -1;
				int maxp = -1;
				for(int i=0;i<n;i++){
					if(a[i] <= all && star[i]==0){
						if(b[i] > maxi){
							maxi = b[i];
							maxp = i;
						}
					}
				}
				if(maxi != -1){
					star[maxp] = 1;
					all++;
					changed = true;
					times++;
				}
			}
			if(!changed){
				ok = false;
				break;
			}
		}
		if(ok)
			printf("Case #%d: %d\n", TT, times);
		else
			printf("Case #%d: Too Bad\n", TT);
	}
}