#include<stdio.h>
int tx,ty;
int up(){
	printf("SN");
	ty++;
}
int down(){
	printf("NS");
	ty--;
}
int left(){
	printf("EW");
	tx--;
}
int right(){
	printf("WE");
	tx++;
}

int main(){
	int t;
	scanf("%d",&t);
	for(int e  = 0 ; e< t ; e++ ){
		int gx,gy;
		tx = 0 ;
		ty = 0 ;
		scanf("%d %d",&gx,&gy);
		printf("Case #%d: ",e+1);
		for( ; tx < gx ; ) right();
		for( ; tx > gx ; ) left();
		for( ; ty < gy ; ) up();
		for( ; ty > gy ; ) down();
		printf("\n");
	}
}

		 
