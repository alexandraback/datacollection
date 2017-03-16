#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include <iostream>

using namespace std;

/*int min(int a, int b){
	return (a<b)? a : b;
}*/

int absf(int a){
    return (a<0)?(-a):a;
}

int main(){
	
    int T,M,N,absM,absN, K;
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

    char *seq;

    for(int i=1; i<=T; i++){
    	fscanf(fi, "%d", &M);
    	fscanf(fi, "%d", &N);
        fprintf(fo, "Case #%d: ", i);
        absM=absf(M);
        absN=absf(N);
        K=ceil((sqrt(1+8*(absM+absN))-1)/2);
        if((absM+absN)%2==1){
            if(K%4==3) K++;
            if(K%4==0) K++;
        }
        if((absM+absN)%2==0){
            if(K%4==1) K++;
            if(K%4==2) K++;
        }
        seq=(char*)malloc((K+1)*sizeof(char));
        for(int j=K;j>=1;j--){
            if(absM>absN){
                if(M>0){
                    M=M-j;
                    seq[j-1]='E';
                } else {
                    M=M+j;
                    seq[j-1]='W';
                }
                absM=absf(M);
            } else {
                if(N>0){
                    N=N-j;
                    seq[j-1]='N';
                } else {
                    N=N+j;
                    seq[j-1]='S';
                }
                absN=absf(N);
            }
        }
        for(int j=0;j<=K-1;j++) fprintf(fo, "%c", seq[j]);
        fprintf(fo,"\n");
        free(seq);
    }
		
	fclose(fi);
	fclose(fo);
	
	return 0;
}
