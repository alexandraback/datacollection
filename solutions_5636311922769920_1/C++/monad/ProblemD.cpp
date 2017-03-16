#include <stdio.h>

int main(){
	int nTestCases;
	scanf("%d",&nTestCases);
	for(int i=0;i<nTestCases;++i){
			int k,c,s;
			scanf("%d %d %d",&k,&c,&s);
			if(s < k ){
					printf("Case #%d: IMPOSSIBLE\n",i + 1);
			}
			printf("Case #%d:",i+1);
			for(int j=1;j<=k;++j){
					printf(" %d",j);
			}
			printf("\n");
	}
	return 0;
}
