#include <stdio.h>
int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++){
		int X,R,C;
		scanf("%d %d %d",&X,&R,&C);
		printf("Case #%d: ",t);
		if(X>=7)puts("RICHARD");
		else{
			if(X==1)puts("GABRIEL");
			else if(X==2){
				if((R%2==0||C%2==0)){
					puts("GABRIEL");
				}else{
					puts("RICHARD");
				}
			}else if(X==3){
				if((R%2==0&&C%3==0)||(R%3==0&&C%2==0)){
					puts("GABRIEL");
				}else{
					puts("RICHARD");
				}
			}else if(X==4){
				if((R<4&&C<4)||((R*C)%4!=0)||R<=2||C<=2){
					puts("RICHARD");
				}else{
					puts("GABRIEL");
				}
			}
		}
	}
	return 0;
}
