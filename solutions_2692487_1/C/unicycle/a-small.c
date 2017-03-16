#include <stdio.h>
#include <stdlib.h>

#define MAXINT 2147483647

typedef struct Instance_S Instance;
struct Instance_S{
	int y;
	int num;
	int size;
	int* motes;
};

int main(){
	FILE* fp;
	Instance* inst; 
	int n,i,j,k;
	int temp,min,index,count;

	// Open input file
	if(!(fp=fopen("A-large.in","r"))){
		printf("Error: There was a problem opening the input file!\n");
	}
	// Read input
	fscanf(fp,"%d",&n);
	inst = (Instance*) calloc(n,sizeof(Instance));
	for(i=0;i<n;i++){
		inst[i].y = 0;
		fscanf(fp,"%d %d",&inst[i].size, &inst[i].num);
		inst[i].motes = (int*)calloc(inst[i].num,sizeof(int));
		for(j=0;j<inst[i].num;j++){
			fscanf(fp,"%d",&inst[i].motes[j]);
		}
	}
	// Close input file
	fclose(fp);



	// Solve
	for(i=0;i<n;i++){
		// sort
		for(j=0;j<inst[i].num;j++){
			min = MAXINT;
			for(k=j;k<inst[i].num;k++){
				if(min > inst[i].motes[k]){
					min = inst[i].motes[k];
					index = k; 
				}
			}
			temp = inst[i].motes[j];
			inst[i].motes[j] = inst[i].motes[index];
			inst[i].motes[index] = temp;
		}
		count = 0;
		// absorb small
		for(j=0;j<inst[i].num;j++){
			if(inst[i].motes[j] < inst[i].size){
				inst[i].size += inst[i].motes[j];
				inst[i].motes[j] = 0;
			}
			else{
				inst[i].y++;
					inst[i].size += inst[i].size - 1;
			}
			for(k=0;k<inst[i].num;k++){
				if(inst[i].motes[k] < inst[i].size){
					inst[i].size += inst[i].motes[k];
					inst[i].motes[k] = 0;
				}
			}
		}

	}



	// Open output file
	if(!(fp=fopen("out.txt","w"))){
		printf("Error: There was a problem opening the output file!\n");
	}
	// Write output
	for(i=0;i<n;i++){
		fprintf(fp,"Case #%d: %d\n",i+1,inst[i].y);
	}
	// Close output file
	fclose(fp);
	// Free dynamic memory
	
	return 0;
}