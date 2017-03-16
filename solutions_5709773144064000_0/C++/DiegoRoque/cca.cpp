#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int main(){
	int T,t=0;
	scanf("%d",&T);
	long double aux,B,C,F,X;
	int k;
	while(T--){
		t++;
		printf("Case #%d: ",t);
		scanf("%llf %llf %llf",&C,&F,&X);
		B=X/2;
		for(long double i=2.0;;i+=F){
			aux=C/i-X/i+X/(i+F);
			if(aux>0){ break;}
			else{
				B+=aux;
			}
		}
		printf("%.7llf\n",B);
	}
}

