#include <iostream>
#include <stdio.h>
#include <stdlib.h>

void treatInput();

int main(int argc, char** argv){
	
	int nbr_of_inputs;
	scanf("%d", &nbr_of_inputs);
	
	int i;
	for (i=1; i<=nbr_of_inputs;i++){
		printf("Case #%d: ",i);
		treatInput();
		printf("\n");
	}
	
	return 0;

}

void treatInput(){
	
	int N, sum=0;
	scanf("%d", &N);
	
	int* s = (int*) malloc(sizeof(int)*N);
	
	int i;
	for (i=0; i<N; i++){
		scanf("%d",s + i);
		sum+=s[i];
	}
	
	float total = sum*2;
	float needed = total / N;
	int realConc = N;
	
	bool notBalanced = true;
	while (notBalanced){
		notBalanced = false;
		for (i=0; i<N; i++){
			if (s[i] > needed){
				total-=s[i];
				s[i]=-1;
				realConc--;
				needed = total / realConc;
				notBalanced = true;
				break;
			}
		}
	}
	
	for (i=0; i<N; i++){
		if ((s[i]>=needed) || (N==1) || s[i]==-1)
			printf("0 ");
		else {
			printf("%f ", (needed-s[i])/sum*100);
		}
	}
	
	return;
}
