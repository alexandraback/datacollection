#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <algorithm>

using namespace std;

int sol[4][4][4]={};

int main(int argc,char **argv){
	int caseno,i,j,k;
	int T;
	int X,R,C,pass;

	FILE *fin,*fout;

	fin=fopen("D-small-attempt0.in","rt");
	fout=fopen("D-small-attempt0.out","wt");
	
	
	fscanf(fin,"%d",&T);

	for(caseno=1;caseno<=T;caseno++){
		fscanf(fin,"%d %d %d",&X,&R,&C);

		if((R*C)%X!=0){
			fprintf(fout,"Case #%d: RICHARD\n",caseno);
			continue;
		}

		pass=1;

		//R <= C
		if(R>C){
			i=R; R=C; C=i;
		}


		if(X==3){
			if(R==1) pass=0;
		}
		else if(X==4){
			if(R==1) pass=0;
			if((R==2)&&(C==2)) pass=0;
			if((R==2)&&(C==4)) pass=0;
		}

		if(pass){
			fprintf(fout,"Case #%d: GABRIEL\n",caseno);
		}
		else {
			fprintf(fout,"Case #%d: RICHARD\n",caseno);
		}
	}
	fclose(fout);
	fclose(fin);

	return 0;
}