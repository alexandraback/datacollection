#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int T, X, R, C, u;

int f(){
	if(X>=7) return 0;
	if((R*C)%X != 0) return 0;
	if(X <= 2) return 1;
	if(X == 3){
		if(R==1 || C==1) return 0;
		else return 1;
	}
	if(X == 4){
		if(R==1 || C==1) return 0;
		if(R==2 || C==2) return 0;
		return 1;
	}
	if(X == 5){
		if(R==1 || C==1) return 0;
		if(R==2 || C==2) return 0;
		if(R==3 || C==3) return 0;
		return 1;
	}
	if(X == 6){
		if(R==1 || C==1) return 0;
		if(R==2 || C==2) return 0;
		if(R==3 || C==3) return 0;
		return 1;
	}
	return 0;
}

int main(){
	scanf(" %d", &T);
	u=0;
	while(u<T){
		u++;
		scanf(" %d %d %d", &X, &R, &C);
		
		int resp = f();
		
		if(resp == 1) printf("Case #%d: GABRIEL\n", u);
		else printf("Case #%d: RICHARD\n", u);
	}
	return 0;
}
