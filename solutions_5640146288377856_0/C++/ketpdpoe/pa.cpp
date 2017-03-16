#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main(){
	int T,I;
	scanf("%d",&T);
	for(I=0;I<T;I++){
		int r,c,w;
		scanf("%d %d %d",&r,&c,&w);
		printf("Case #%d: ",I+1);
		if(c%w==0){
			printf("%d\n",c/w-1+w);
		}
		else{
			printf("%d\n",c/w-1+w+1);
		}
	}
	return 0;
}