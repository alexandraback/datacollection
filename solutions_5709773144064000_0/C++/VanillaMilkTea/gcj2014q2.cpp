#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc,char **argv){
	int caseno,i,j,k;
	int T;
	double C,F,X;
	double c,rate,time,t0,t1;
	FILE *fin,*fout;

	fin=fopen("B-small-attempt2.in","rt");
	fout=fopen("B-small-attempt2.out","wt");
	
	fscanf(fin,"%d",&T);
	for(caseno=1;caseno<=T;caseno++){
		fscanf(fin,"%lf %lf %lf",&C,&F,&X);
		if(X==0.0) {
			fprintf(fout,"Case #%d: 0.0\n",caseno);
			continue;
		}
		if(C==F){
			fprintf(fout,"Case #%d: %0.7lf\n",(X/2.0));
			continue;
		}

		time=0;
		c=0;
		rate=2.0;

		while(true){
			if((C/rate)>=(X/rate)){
				time+=(X/rate);
				break;
			}

			t0=X/rate;
			t1=(C/rate)+(X/(rate+F));
			if(t0<=t1){
				time+=(X/rate);
				break;
			}
			else{
				time+=(C/rate);
				rate+=F;
			}
		}
		
		fprintf(fout,"Case #%d: %.7lf\n",caseno,time);
	}
	fclose(fout);
	fclose(fin);

	return 0;
}