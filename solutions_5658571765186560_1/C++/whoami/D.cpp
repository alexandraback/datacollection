#include <stdio.h>
char* process(int x,int n,int m){
	if(x==1)
		return "GABRIEL";
	else if(x==2){
		if((n*m)%2!=0)
			return "RICHARD";
		return "GABRIEL";
	}
	else if(x==3){
		if((n*m)%3!=0 || n==1 || m==1)
			return "RICHARD";
		return "GABRIEL";
	}
	else if(x==4){
		if((n*m)%4!=0 || n<=2 || m<=2)
			return "RICHARD";
		return "GABRIEL";
	}
	else if(x==5){
		if((n*m)%5!=0 || n<=2 || m<=2 || m*n == 15)
			return "RICHARD";
		return "GABRIEL";
	}
	else if(x==6){
		if((n*m)%6!=0 || n<=3 || m<=3)
			return "RICHARD";
		return "GABRIEL";
	}
	return "RICHARD";
}
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int testt;
	scanf("%d",&testt);
	for(int test=1;test<=testt;test++){
		int x,n,m;
		scanf("%d %d %d",&x,&n,&m);
		printf("Case #%d: %s\n", test, process(x,n,m));
	}
	return 0;
}
