#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include <iostream>

using namespace std;

/*int min(int a, int b){
	return (a<b)? a : b;
}*/


int main(){
	
    int T,M,N;
    //int *grid;
	
	FILE *fi;
    if(!(fi=fopen("./inputB", "r"))){
        printf("File \'inputB\' could not be opened!\n");
        exit(-1);
    }
    fscanf(fi, "%d", &T);
	//fscanf(fi, "%lg", z+i);
	
	FILE *fo;
    if(!(fo=fopen("./outpuB", "w"))){
        printf("File \'outputB\' could not be opened!\n");
        exit(-1);
    }
    
    for(int i=1; i<=T; i++){
    	fscanf(fi, "%d", &M);
    	fscanf(fi, "%d", &N);
        fprintf(fo, "Case #%d: ", i);
        if(M>0) for(int j=1;j<=M;j++) fprintf(fo, "WE", i);
        if(M<0) for(int j=-1;j>=M;j--) fprintf(fo, "EW", i);
        if(N>0) for(int j=1;j<=N;j++) fprintf(fo, "SN", i);
        if(N<0) for(int j=-1;j>=N;j--) fprintf(fo, "NS", i);
        fprintf(fo,"\n");
    }
		
	fclose(fi);
	fclose(fo);
	
	return 0;
}
