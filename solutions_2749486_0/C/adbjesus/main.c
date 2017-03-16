#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int T,X,Y;

int solve(){
	int x,y,i;
	i=1;
	x=0;
	y=0;
	while(x!=X){
		if(x-i<X){x+=i;i++;printf("E");}
		else{x-=i;i++;printf("W");}
	}
	while(y!=Y){
		if(y-i<Y){y+=i;i++;printf("N");}
		else{y-=i;i++;printf("S");}
	}
}

int main(void){
	int t;
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		scanf("%d %d",&X,&Y);
		printf("Case #%d: ",t);
		solve();
		printf("\n");
	}
	return 0;
}
