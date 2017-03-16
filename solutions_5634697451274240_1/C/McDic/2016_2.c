#include <stdio.h>

int main(void){
	
	int i, j, testcase;
	
	int length, status;
	
	freopen("B-large.in", "r", stdin);
	freopen("output_2016_2_large.txt", "w", stdout);
	
	char pancakes[105];
	int pancakeint[105]={0,};
	
	scanf("%d", &testcase);
	for(j=1; j<=testcase; j++){
		
		scanf("%s", pancakes);
		length=0;
		for(i=0; pancakes[i]!=0; i++){
			if(pancakes[i]=='-') pancakeint[i]=0; // - 0
			else pancakeint[i]=1;					// + 1
			length++;
		}
		
		status=0;
		for(i=1; i<length; i++){
			if(pancakeint[i]==0 && pancakeint[i-1]==1) status++;
			else if(pancakeint[i]==1 && pancakeint[i-1]==0) status++;
		}
		
		if(pancakeint[length-1]==0) status++;
		
		printf("Case #%d: %d\n", j, status);
	}
	
	return 0;
}
