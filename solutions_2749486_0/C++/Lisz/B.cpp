#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	freopen("B-small-attempt0(1).in","rt",stdin);
	freopen("out.out","wt",stdout);
	int cas , casn = 1 ;
	scanf("%d",&cas);
	while(cas--){
		int x,y ;
		scanf("%d%d",&x,&y);
		printf("Case #%d: ",casn++);
		if(x!=0){
			if( x > 0 ){
				while( x -- ){
					printf("WE");
				}
			}else{
				while( x++ ){
					printf("EW");
				}
			}
		}
		if(y!=0){
			if( y > 0 ){
				while( y -- ){
					printf("SN");
				}
			}else{
				while( y ++ ){
					printf("NS");
				}
			}
		}
		puts("");
	}
	return 0;
}