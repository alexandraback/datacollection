#include <iostream>
#include <string.h>

using namespace std;

FILE * fin = fopen("A.in","r");
FILE * din = fopen("dict.txt","r");
FILE * fout = fopen("A1.out","w");

int to[30];


bool legal(char c){
    if(c=='\n' or c==' ') return true;
    if(c>='a' and c<='z') return true;
    return false;
}

char nextC(){
    char c;
    do{
	fscanf(fin,"%c", &c);
    }while(!legal(c));
    return c;
}

int main(){
    for(int i=0; i<26; i++){
	fscanf(din,"%d", &to[i]);
    }
    int lnum=0, N;
    fscanf(fin,"%d", &N);
    char c = nextC();
    fprintf(fout,"Case #%d: ", 1); 
    while(lnum<N){
	c=nextC();
	if(c=='\n' or c==' ')
	    fprintf(fout,"%c",c);
	else
	    fprintf(fout,"%c", to[c-'a']+'a');
	if(c=='\n'){ 
	    lnum++;
	    if(lnum<N)
	    fprintf(fout,"Case #%d: ", lnum+1); 
	}
    }
    
}
