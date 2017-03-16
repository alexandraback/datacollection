#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int MAP[50][50];

int min(int a, int b){
	if(a < b)
		return a;
	return b;
}

int main(){
	int numTestCase = 0, numRow, numCol, numMine, numNonMine;
	bool possible = false;
	int i, j, temp, count;
	int testCase;
	
	scanf("%d", &numTestCase);
	
	for(testCase = 0; testCase < numTestCase; testCase++){	
		scanf("%d %d %d\n", &numRow, &numCol, &numMine);
		
		for(i = 0; i < numCol; i++){
			for(j = 0; j < numRow; j++){
				MAP[j][i] = -1;
			}
		}
		
		numNonMine = numRow*numCol-numMine;
		
		if(numRow == 1 || numCol == 1){
			count = 0;
			printf("Case #%d:\n", testCase+1);
			
			for(j = 0; j < numRow; j++){
				for(i = 0; i < numCol; i++){
					if(i == 0 && j == 0){
						printf("c");
						count++;
					}
					else if(count < numNonMine){
						printf(".");
						count++;
					}
					else{
						printf("*");
					}
				}
				printf("\n");
			}
		}
		else{
			int maxBase = min(min(numRow, numCol) ,(int)sqrt((float)numNonMine)), base;
			int leftSpace = numRow - maxBase + numCol - maxBase;
			int leftNonMine = numNonMine - maxBase*maxBase;
			int *x;
			
			for(base = maxBase; base >= 1; base--){
				
				for(i = base; i >= 2; i--){
					leftSpace = numRow - base + numCol - base;
					leftNonMine = numNonMine - base*base;
					x = (int*) malloc((base+1)*sizeof(int));
					
					for(j = 0; j < base+1; j++){
						x[j] = 0;
					}
					
					for(j = i; j >= 2; j--){
						x[j] = (int)(leftNonMine/j);
						leftSpace -= x[j];
						leftNonMine -= x[j]*j;
						
						if(leftSpace < 0){
							break;
						}
					}
					
					if(leftNonMine == 0){
						break;
					}
				}
				
				if(leftNonMine == 0){
					break;
				}
			}
			
			printf("Case #%d:\n", testCase+1);
			if(leftNonMine == 0){
				int leftRow = numRow - base, leftCol = numCol - base;
				int lastRow = base, lastCol = base;
				
				for(j = 0; j < base; j++){
					for(i = 0; i < base; i++){
						MAP[j][i] = 0;
					}
				}
				
				for(i = base; i >= 2; i--){
					while(x[i] > 0){
						if(leftRow > 0){
							for(j = 0; j < i; j++){
								MAP[lastRow][j] = 0;
							}
							leftRow--;
							lastRow++;
						}
						else{
							for(j = 0; j < i; j++){
								MAP[j][lastCol] = 0;
							}
							leftCol--;
							lastCol++;
						}
						x[i]--;
					}
				}
				
				for(j = 0; j < numRow; j++){
					for(i = 0; i < numCol; i++){
						if(MAP[j][i] == -1){
							// mine
							printf("*");
						} 
						else if(i == 0 && j == 0){
							// clicked point
							printf("c");
						}
						else{
							printf(".");
						}
					}
					printf("\n");
				}
			}
			else{
				printf("Impossible\n");
			}
		}	
	}
	
	return 0;
}
