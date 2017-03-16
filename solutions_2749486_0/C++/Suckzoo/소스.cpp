#include <cstdio>

int x,y;
int T,Ti;
int main() {
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	scanf("%d",&T);
	for(Ti=1;Ti<=T;Ti++) {
		scanf("%d%d",&x,&y);
		int i;
		int ans=0;
		printf("Case #%d: ",Ti);
		if(x>0) {
			for(i=0;i<x;i++) {
				printf("WE");
			}
		} else if(x<0) {
			for(i=0;i<-x;i++) {
				printf("EW");
			}
		}
		if(y>0) {
			for(i=0;i<y;i++) {
				printf("SN");
			}
		} else if(y<0) {
			for(i=0;i<-y;i++) {
				printf("NS");
			}
		}
		printf("\n");
	}
	return 0;
}