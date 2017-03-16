#include <stdio.h>

int t,resp,tam;
char c[112];

int main(){
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		resp=0;
		scanf(" %c",&c[0]);
		for(tam=1; c[tam-1]=='+' || c[tam-1]=='-' ;tam++) scanf("%c",&c[tam]);
		for(int j=1;j<tam-1;j++) resp+=(c[j]!=c[j-1]);
		resp+=(c[tam-2]=='-');
		printf("Case #%d: %d\n",i,resp);
	}
	return 0;
}
	
