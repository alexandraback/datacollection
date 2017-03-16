#include <math.h>
#include <stdbool.h>
#include <stdio.h>

void go(void){
	int r,c,m;
	int i,j;
	scanf("%d %d %d",&r,&c,&m);
	int n = r*c-m;
	bool rot = false;
	if(r<c){
		rot = true;
		int temp = r;
		r = c;
		c = temp;
	}
	char board[r][c];
	if(n==1 || c==1){
		for(j=0; j<r; j++){
			for(i=0; i<c; i++){
				if(n>0){
					board[j][i]='.';
					if(i==0 && j==0) board[0][0]='c';
					n--;
				} else {
					board[j][i]='*';
				}
			}
		}
	} else{
		int l;
		for(l=2; l<=c; l++){
			if(l*r >= n){
				if(n/l>=2 && (n%l != 1)){
					for(j=0; j<r; j++){
						for(i=0; i<c; i++){
							if(n>0 && i<l){
								board[j][i]='.';
								if(i==0 && j==0) board[0][0]='c';
								n--;
							} else {
								board[j][i]='*';
							}
						}
					}		
					break;
				} else if(l>=3 && n/l >= 3){
					for(j=0; j<r; j++){
						for(i=0; i<c; i++){
							if((n>2 && i<l) || (n>0 && n<=2 && i<2)){
								board[j][i]='.';
								if(i==0 && j==0) board[0][0]='c';
								n--;
							} else {
								board[j][i]='*';
							}
						}
					}	
					break;
				}
			}
		}
		if(l==c+1){
			printf("Impossible\n");
			return;
		}
	}
	
	if(rot){
		for(i=0; i<c; i++){
			for(j=0; j<r; j++){
				printf("%c",board[j][i]);
			}
			printf("\n");
		}	
	} else {
		for(j=0; j<r; j++){
			for(i=0; i<c; i++){
				printf("%c",board[j][i]);
			}
			printf("\n");
		}	
	}
}

int main(int argc, char** argv){
	int t;
	scanf("%d",&t);
	int i;
	for(i=1; i<=t; i++){
		printf("Case #%d:\n",i);
		go();
	}
	return 0;
}
