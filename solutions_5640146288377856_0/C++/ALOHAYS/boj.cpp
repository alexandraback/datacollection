#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <string.h>


using namespace std;
int T,R,C,W;
int map[33][33];


int main()
{
	FILE* fin=NULL;
	FILE* fout=NULL;
	fin = fopen("input.txt","r");
	fout = fopen("output.txt","w");
	fscanf(fin,"%d",&T);
	for(int t=1;t<=T;t++){
		fscanf(fin,"%d %d %d",&R,&C,&W);
		if(W==C){
			fprintf(fout,"Case #%d: %d\n",t,W);
		}
		else if(2*W>=C){
			fprintf(fout,"Case #%d: %d\n",t,W+1);
		}
		else if(W>1){
			if(C%W==0)
				fprintf(fout,"Case #%d: %d\n",t,C/W+W-1);
			else
				fprintf(fout,"Case #%d: %d\n",t,C/W+W);
		}
		else{
			fprintf(fout,"Case #%d: %d\n",t,C);
		}

	}
	return 0;
}