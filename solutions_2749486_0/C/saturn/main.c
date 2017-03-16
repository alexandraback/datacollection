#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void exchange(int* arr,int p,int r){
	int temp = arr[p];
	arr[p] = arr[r];
	arr[r] = temp;
}
 
int partition(int* arr,int p,int r){
	int x = arr[r];
	int i=p-1;
	int j=0;
	for(j=p;j<r;j++){
		if(arr[j]<=x){
			i++;
			exchange(arr,i,j);
		}
	}
	exchange(arr,i+1,r);
	return i+1;
}
 
void quickSort(int* arr,int p,int r){
	int q =0;
	if(p<r){
		q = partition(arr,p,r);
		quickSort(arr,p,q-1);
		quickSort(arr,q+1,r);
	}
}


void printChar(char c,FILE* out){
	fprintf(out,"%c",c);
}

void printAns(int fx,int fy,FILE* out){
	int i = 0;
	if(fx <0){
		
		for(i=0;i<(-1*fx);i++){
			printChar('E',out);
			printChar('W',out);
		}
	}
	else{
		for(i=0;i<(fx);i++){
			printChar('W',out);
			printChar('E',out);
		}
	}
	if(fy <0){
		
		for(i=0;i<(-1*fy);i++){
			printChar('N',out);
			printChar('S',out);
		}
	}
	else{
		for(i=0;i<(fy);i++){
			printChar('S',out);
			printChar('N',out);
		}
	}
	fprintf(out,"\n");
	
	
	
}

int main(void) {
	FILE* inp = fopen("inp.txt","r");
	FILE* out = fopen("out.txt","w");

	int test = 0,i,caseCount;
	int x,y;
	int ans = 0;
	fscanf(inp,"%d",&test);
	for(caseCount =1;caseCount<=test;caseCount++){
		fscanf(inp,"%d",&x);
		fscanf(inp,"%d",&y);
	
		fprintf(out,"Case #%d: ",caseCount);
		printAns(x,y,out);
	}
	
	
	fclose(inp);
	fclose(out);
	
	return 0;
}
