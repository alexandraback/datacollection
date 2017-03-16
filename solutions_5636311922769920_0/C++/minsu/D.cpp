#include <bits/stdc++.h>
using namespace std;

int T,K,C,S;
int main(){
	scanf("%d",&T);
	for(int t=1; t<=T; t++){
		scanf("%d%d%d",&K,&C,&S);
		printf("Case #%d: ",t);
		for(int i=1; i<=K; i++)
			printf("%d ",i);
		printf("\n");
	}
	return 0;
}
