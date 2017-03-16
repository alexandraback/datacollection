#include<stdio.h>
int tcn,tc;
int x,n,m;
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++){
		scanf("%d%d%d",&x,&n,&m);
		printf("Case #%d: ",tc);
		if(x>=7){
			puts("RICHARD");
		}
		else if(n+m<=x){
			puts("RICHARD");
		}
		else if((n*m)%x!=0){
			puts("RICHARD");
		}
		else if((n<(x+1)/2||m<(x+1)/2)){
			puts("RICHARD");
		}
		else if(x>3&&(n<(x+3)/2||m<(x+3)/2)){
			puts("RICHARD");
		}
		else{
			puts("GABRIEL");
		}
	}
}