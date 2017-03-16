#include <stdio.h>

int main(void) {
	int T,caseCount;
	scanf("%d",&T);
	for(caseCount=1;caseCount<=T;caseCount++) {
		int width,height;
		int a[100][100];
		int i,j;
		int allok;
		scanf("%d%d",&height,&width);
		for(i=0;i<height;i++) {
			for(j=0;j<width;j++) {
				scanf("%d",&a[i][j]);
			}
		}
		allok=1;
		for(i=0;i<height;i++) {
			for(j=0;j<width;j++) {
				int k;
				int nowng1=0,nowng2=0;
				for(k=0;k<width;k++) {
					if(a[i][k]>a[i][j]){nowng1=1;break;}
				}
				for(k=0;k<height;k++) {
					if(a[k][j]>a[i][j]){nowng2=1;break;}
				}
				if(nowng1 && nowng2){allok=0;i=height;break;}
			}
		}
		printf("Case #%d: %s\n",caseCount,allok?"YES":"NO");
	}
	return 0;
}
