#include<stdio.h>
void proc(int ii){
	int r,c,w;
	scanf("%d %d %d",&r,&c,&w);
	printf("Case #%d: %d\n",ii,r*(c/w) + w - (c%w == 0));
}
int main(){
	int qq;
	scanf("%d",&qq);
	for(int i =0;i<qq;i++){
		proc(i+1);
	}
	return 0;
}