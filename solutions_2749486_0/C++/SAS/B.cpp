#include<stdio.h>
#include<stdlib.h>
int main(){
	int T;
	int X,Y;
	scanf("%d",&T);
	for(int ca = 0; ca < T; ca++){
		scanf("%d %d",&X,&Y);
		printf("Case #%d: ",ca + 1);
		if(X > 0){
			for(int i=0;i<X;i++){
				printf("WE");
			}
		}else{
			for(int i=0;i<-X;i++){
				printf("EW");
			}
		}


		if(Y > 0){
			for(int i=0;i<Y;i++){
				printf("SN");
			}
		}else{
			for(int i=0;i<-Y;i++){
				printf("NS");
			}
		}
		printf("\n");
	}
	return 0;
}
