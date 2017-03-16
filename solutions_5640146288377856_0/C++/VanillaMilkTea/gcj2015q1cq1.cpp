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

	fin=fopen("A-small-attempt0.in","rt");
	fout=fopen("A-small-attempt0.out","wt");
	
	
	fscanf(fin,"%d",&T);

	for(caseno=1;caseno<=T;caseno++){
		fscanf(fin,"%d %d %d",&R,&C,&W);

		if(C==W){
			fprintf(fout,"Case #%d: %d\n",caseno,W);
			continue;
		}
		if(C==1){
			fprintf(fout,"Case #%d: %d\n",caseno,W);
			continue;
		}
			
		if((C%W)==0){
			m = C/W+W-1;
		}
		else {
			m = C/W+W;
		}

		fprintf(fout,"Case #%d: %d\n",caseno,m);
	}
	fclose(fout);
	fclose(fin);

	return 0;
}