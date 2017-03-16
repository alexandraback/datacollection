#include <cstdio>

int main(){
	int T;
	scanf("%d",&T);
	for(int Case = 1;Case<=T;Case++){
		int k,c,s;
		scanf("%d%d%d",&k,&c,&s);
		printf("Case #%d:", Case);
		for(int i=0;i<k;i++){
			printf(" %d", i+1);
		}
		printf("\n");
	}
}