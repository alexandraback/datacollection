#include <stdio.h>

#include <stdlib.h>

#include <math.h>

#include <iostream>

using namespace std;

/*int min(int a, int b){
	return (a<b)? a : b;
}*/

int isconsonant(char a){
    if((a=='a')||(a=='e')||(a=='i')||(a=='o')||(a=='u')) return 0;
    else return 1;
}


int main(){
	
    int T,intdump;
    int *n, *L;
    //int *grid;
	
	FILE *fi;
    if(!(fi=fopen("./inputA", "r"))){
        printf("File \'inputA\' could not be opened!\n");
        exit(-1);
    }
    fscanf(fi, "%d", &T);
	//fscanf(fi, "%lg", z+i);
	
    FILE *fo;
    if(!(fo=fopen("./outputA", "w"))){
        printf("File \'outputA\' could not be opened!\n");
        exit(-1);
    }

    n=(int*)malloc(T*sizeof(int));
    L=(int*)malloc(T*sizeof(int));
    char dump,chread;
    int l;
    for(int i=0; i<=T-1; i++){
        fscanf(fi, "%c", &dump);
        l=0;
        do{
            fscanf(fi, "%c", &chread);
            l++;
        }while(chread!=' ');
        L[i]=l-1;
        fscanf(fi, "%d", n+i);
    }

    fclose(fi);
    if(!(fi=fopen("./inputA", "r"))){
        printf("File \'inputA\' could not be opened!\n");
        exit(-1);
    }

    fscanf(fi, "%d", &intdump);

    int conscount,x;
    unsigned long long substr;

    for(int i=0; i<=T-1; i++){
        fscanf(fi, "%c", &dump);
        conscount=0;
        x=0;
        substr=0;
        for(int j=1;j<=L[i];j++){
            fscanf(fi, "%c", &chread);
            if(isconsonant(chread)==1) conscount++;
            else conscount=0;
            if(conscount>=n[i]) x=j-n[i]+1;
            substr=substr+x;
        }
        fscanf(fi, "%c", &dump);
        fscanf(fi, "%d", &intdump);
        fprintf(fo,"Case #%d: %llu\n", i+1, substr);
    }

	fclose(fi);
    fclose(fo);
	
	return 0;
}
