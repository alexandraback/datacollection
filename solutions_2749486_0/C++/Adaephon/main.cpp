#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cmath>


void Numbers(int X, int Y, int case_num){
	
	FILE *f1;
	f1 = fopen("output_small.out", "a");
	fprintf(f1, "Case #%d: ", case_num);
	for(int i=0; i<abs(X); ++i){
		if(X < 0){
			fprintf(f1, "EW");
		}
		if(X>0){
			fprintf(f1, "WE");
		}
	}
	for(int i=0; i<abs(Y); ++i){
		if(Y < 0){
			fprintf(f1, "NS");
		}
		if(Y>0){
			fprintf(f1, "SN");
		}
	}
	fprintf(f1, "\n");
	fclose(f1);


	
}

int main(){
	int num_cases;
	int X, Y;
	FILE *f1;


	f1 = fopen("B-small-attempt0.in", "r");
	fscanf(f1, "%d\n", &num_cases);
	for(int i=0; i<num_cases; i++){
		fscanf(f1, "%d %d\n", &X, &Y);
		Numbers(X, Y,i+1);
	}
	fclose(f1);



	return 0;
}