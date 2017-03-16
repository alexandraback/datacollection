#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int myabs(int x){
	if(x<0)return -x;
	return x;
}

int main(){
	int z;
	scanf("%d", &z);
	for(int t=0; t<z; t++){
		int a,b;
		scanf("%d%d", &a,&b);
		int K = 1;
		int x=0, y=0;
		int d=0;
		printf("Case #%d: ", t+1);
		while(a!=0 && K!=myabs(a)){
			if(d%2==0){
				y+=K;
				printf("N");
			}
			else{
				y-=K;
				printf("S");
			}
			d++;
			K++;
		}
		if(a<0)printf("W");
		else if(a>0) printf("E");
		int odl = myabs(y-b);
		if(y>b){
			for(int i=0; i<odl; i++){
				printf("N");
				printf("S");
			}
		}
		else if(y<b){
			for(int i=0; i<odl; i++){
				printf("S");
				printf("N");
			}
			
		}

		printf("\n"); 
	}
	return 0;
}
