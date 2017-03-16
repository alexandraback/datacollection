#include <stdio.h>

int main(){

	//freopen("B/in.txt","r",stdin);
	//freopen("B/out.txt","w",stdout);

	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int X,Y;
		scanf("%d%d",&X,&Y);

		printf("Case #%d: ",t);
		int i=1;
		int x = 0,y=0;
		while (x != X){
			if(X<0){
				printf("E");
				x += i;
				i++;
				printf("W");
				x -= i;
				i++;
			}else{
				printf("W");
				x -= i;
				i++;
				printf("E");
				x += i;
				i++;
			}
		}

		while (y != Y){
			if(Y<0){
				printf("N");
				y += i;
				i++;
				printf("S");
				y -= i;
				i++;
			}else{
				printf("S");
				y -= i;
				i++;
				printf("N");
				y += i;
				i++;
			}
		}


		printf("\n");
	}
}

