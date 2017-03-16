#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <algorithm>

using namespace std;

int main(int argc,char **argv){
	int caseno,i,j,k;
	int T;
	int R,C,W,m;
	int *p;

	FILE *fin,*fout;

	fin=fopen("A-large.in","rt");
	fout=fopen("A-large.out","wt");
	
	
	fscanf(fin,"%d",&T);

	for(caseno=1;caseno<=T;caseno++){
		fscanf(fin,"%d %d %d",&R,&C,&W);

		m=0;

		if(C==W){
			m=R-1+W;
			fprintf(fout,"Case #%d: %d\n",caseno,m);
			continue;
		}
		if(C==1){
			m=R*C;
			fprintf(fout,"Case #%d: %d\n",caseno,m);
			continue;
		}
		
		if(R!=1){
			m = (R-1) * (C/W);
			/*
			if((C%W)==0){
				m = (R-1) * (C/W);
			}
			else {
				m = (R-1) * (C/W+1);
			}
			*/
		}

		if((C%W)==0){
			m += C/W+W-1;
		}
		else {
			m += C/W+W;
		}

		fprintf(fout,"Case #%d: %d\n",caseno,m);
	}
	fclose(fout);
	fclose(fin);

	return 0;
}