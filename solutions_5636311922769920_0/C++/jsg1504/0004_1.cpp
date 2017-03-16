#include <cstdio>

int main(){
	int T;
	scanf("%d",&T);

	for(int test_case = 1; test_case <= T; test_case++){
		int K,C,S;
		scanf("%d %d %d",&K,&C,&S);

		printf("Case #%d: ",test_case);
		for(int i = 1 ; i <= K ; i++){
			printf("%d ",i);
		}
		printf("\n");
	}

	return 0;
}
