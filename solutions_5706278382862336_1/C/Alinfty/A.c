#include <stdio.h>

int main(){
	int i,j,k;
	int T,t;
	char y;
	long long int P,Q;
	long long int R;
	long long int a[41];
	a[0]=1;
	for(i=1;i<41;i++){
		a[i]=2*a[i-1];
	}
	scanf("%d", &T);
	for(t=1;t<=T;t++){
		printf("Case #%d: ",t);
		scanf("%lld", &P);
		scanf("%c", &y);
		scanf("%lld", &Q);
		for(i=1;i<41;i++){
			if(Q%a[i]!=0) break;
		}
		i--;
		if(P%(Q/a[i])!=0){
			printf("impossible\n");
			continue;
		}
		R=P/(Q/a[i]);
		for(j=1;j<41;j++){
			if(R<a[j]) break;
		}
		j--;
		printf("%d\n", i-j);
	}
	return 0;
}
