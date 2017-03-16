#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int main (){
	int T,X,Y,i;
    scanf("%d",&T);
    for (i=1;i<=T;i++){
    	scanf("%d %d",&X,&Y);
    	printf("Case #%d: ",i);
    	if (X<0){
    		for (i=X;i<=-1;i++){
    			printf("EW");
    		}
    	} else {
    		for (i=1;i<=X;i++){
    			printf("WE");
    		}
    	}
    	if (Y<0){
    		for (i=Y;i<=-1;i++){
    			printf("NS");
    		}
    	} else {
    		for (i=1;i<=Y;i++){
    			printf("SN");
    		}
    	}
    	printf("\n");
    }
	return 0;
}
