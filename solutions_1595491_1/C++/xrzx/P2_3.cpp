#include<stdio.h>
#include<iostream>
#include<string>

using namespace std;
			// 0 , 1, 2, 3, 4, 5, 6, 7, 8, 9,10
int  ns[11] = {0 , 1, 4, 7,10,13,16,19,22,25,28};
int   s[11] = {0 , 1, 2, 5, 8,11,14,17,20,23,26};
	
int main(){
	int T;
	scanf("%d",&T);
	
	int N, S, p;
	
	int i,j,x;
	int counter;
	for ( i = 0 ; i < T ; i++ ){
		counter = 0;
		scanf("%d %d %d",&N, &S, &p);
		//printf("%d %d %d ",N, S, p);
		for (j = 0 ; j < N ; j++){
			scanf("%d",&x);
			//printf("%d ",x);
			if (x >= ns[p]){
				//printf("NS %d %d\n",x,ns[p]);
				counter++;
			} else if ((x >=s[p]) && (S > 0)){
				//printf(" S %d %d\n",x,s[p]);
				counter++;
				S--;
			}
		}
		printf("Case #%d: %d\n",i+1,counter);
	}
	
	return 0;
}