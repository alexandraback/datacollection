#include <stdio.h>

int main(){
	int p[10],t,at;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d",&at);
		printf("Case #%d: ",i);
		if(at==0) printf("INSOMNIA\n");
		else{
			int n=at,aux;
			for(int j=0;j<10;j++) p[j]=1;
			for(int j=1,aux=0;aux<10;j++){
				while(n){
					aux+=p[n%10];
					p[n%10]=0;
					n/=10;
				}
				n=at*j;
			}
			n-=at;
			printf("%d\n",n);
		}
	}
	return 0;
}
			
			
