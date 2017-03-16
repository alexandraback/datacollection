#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(){
	FILE *INPUT = fopen("./input.in","r");
	FILE *OUTPUT = fopen("./output.in","w");
	rewind(INPUT);
	int T,R,C,W,D;
	fscanf(INPUT,"%d",&T);
	int sets=T;
	int rem;
	while(T>0)
	{
		fscanf(INPUT, "%d %d %d",&R,&C,&W);
		D=W;
		if(C%W!=0)
			D++;
		printf("\nCase #%d: %d",(sets-T+1),R*(C/W)+D-1);	
		fprintf(OUTPUT, "Case #%d: %d\n",(sets-T+1),R*(C/W)+D-1);	
		T--;
	}
	return 1;
}
