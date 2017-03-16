#include <stdio.h>
#include <stdlib.h>

typedef struct Instance_S Instance;
struct Instance_S{
	int x;
	int y;
	int xp;
	int yp;
	char move[500];
};

int main(){
	FILE* fp;
	Instance* inst;
	int i,j,k,n;

	// Open input file
	if(!(fp = fopen("B-small-attempt0.in","r"))){
		printf("There was a problem opening the input file\n");
	}
	// Read input file
	fscanf(fp,"%d\n",&n);
	inst = (Instance*)calloc(n,sizeof(Instance));
	for(i=0;i<n;i++){
		fscanf(fp,"%d %d\n",&inst[i].x,&inst[i].y);
	}
	// Close output file
	fclose(fp);


	// Solve
	for(i=0;i<n;i++){
		k = 0;
		for(j=0;j<500;j++){
			inst[i].move[j] = NULL;
		}
		inst[i].xp = 0;
		inst[i].yp = 0;
		// Get to x coordinate
		while(inst[i].x != inst[i].xp){
			if(inst[i].xp<inst[i].x){
				inst[i].move[k] = 'W';
				k++;
				inst[i].move[k] = 'E';
				k++;
				inst[i].xp++;
			}
			else{
				inst[i].move[k] = 'E';
				k++;
				inst[i].move[k] = 'W';
				k++;
				inst[i].xp--;
			}
		}
		// Get to y coordinate
		while(inst[i].y != inst[i].yp){
			if(inst[i].yp<inst[i].y){
				inst[i].move[k] = 'S';
				k++;
				inst[i].move[k] = 'N';
				k++;
				inst[i].yp++;
			}
			else{
				inst[i].move[k] = 'N';
				k++;
				inst[i].move[k] = 'S';
				k++;
				inst[i].yp--;
			}
		}
	}


	// Open output file
	if(!(fp=fopen("out.txt","w"))){
		printf("There was a problem opening the output file\n");
	}
	// Write output file
	for(i=0;i<n;i++){
		fprintf(fp,"Case #%d: %s\n",i+1,inst[i].move);
	}
	// Clost output file
	fclose(fp);
	// Free dynamic memory
	free(inst);
	return 0;
}