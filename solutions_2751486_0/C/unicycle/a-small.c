#include <stdio.h>
#include <stdlib.h>

typedef struct Instance_S Instance;
struct Instance_S{
	int n;
	int length;
	int y;
	char name[100];
};

int main(){
	FILE* fp;
	Instance* inst;
	int i,j,k,l,n;
	int num;
	int max;

	// Open input file
	if(!(fp = fopen("A-small-attempt0.in","r"))){
		printf("There was a problem opening the input file\n");
	}
	// Read input file
	fscanf(fp,"%d\n",&n);
	inst = (Instance*)calloc(n,sizeof(Instance));
	for(i=0;i<n;i++){
		fscanf(fp,"%s %d",&inst[i].name,&inst[i].n);
	}
	// Close output file
	fclose(fp);


	// Solve
	for(i=0;i<n;i++){
		inst[i].y = 0;
		inst[i].length = 0;
		for(j=0;j<100;j++){
			if(inst[i].name[j] != NULL){
				inst[i].length++;
			}
		}
		for(j=0;j<inst[i].length;j++){
			for(k=j;k<inst[i].length;k++){
				num = 0;
				max = 0;
				for(l=j;l<=k;l++){
					if(inst[i].name[l] == 'a' || inst[i].name[l] == 'e' || inst[i].name[l] == 'i' || inst[i].name[l] == 'o' || inst[i].name[l] == 'u'){
						num = 0;
					}
					else{
						num++;
						if(num>max){
							max = num;
						}
					}
				}
				if(max >= inst[i].n){
					inst[i].y++;
				}
			}
		}

	}


	// Open output file
	if(!(fp=fopen("out.txt","w"))){
		printf("There was a problem opening the output file\n");
	}
	// Write output file
	for(i=0;i<n;i++){
		fprintf(fp,"Case #%d: %d\n",i+1,inst[i].y);
	}
	// Clost output file
	fclose(fp);
	// Free dynamic memory
	free(inst);
	return 0;
}