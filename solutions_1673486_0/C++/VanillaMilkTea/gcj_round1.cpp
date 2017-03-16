#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <vector>
#include <algorithm>
#include <map>

#define _USE_MATH_DEFINES

using namespace std;

int main(int argc,char **argv){
	FILE *fin,*fout;
	int cases=0;
	int A=0,B=0;
	int i=0,j=0,k=0;
	double prob[100000];
	int numChar=0;
	double best=0.0;
	int numBest=0;
	int extra=0;
	double cur1=0.0,cur2=0.0,cur=0.0;
	double exp=0.0;
	double totalProb=0.0;
	clock_t t0;
	t0=clock();

	fin =fopen("A-small-attempt1.in","rt");
	fout=fopen("A-small-attempt1.out","wt");
	
	fscanf(fin,"%d\n",&cases);
	printf("cases = %d\n",cases);
	for(i=1;i<=cases;i++){
		printf("case %d\n",i);
		fscanf(fin,"%d %d",&A,&B);
		
		best=A+B+1;
		totalProb=1.0;
		//printf("%0.6lf\n",best);
		for(j=0;j<A;j++){
			fscanf(fin,"%lf",&prob[j]);
			totalProb*=prob[j];
			//printf("%0.6lf\n",totalProb);
			//printf("%d\n",A-(j+1));
			//printf("%d\n",B-(j+1));
			extra=(A-(j+1))+(B-(j+1))+1;
			cur1=totalProb*((A-(j+1))+(B-(j+1))+1);
			cur2=(1.0-totalProb)*(B+1+extra);
			//printf("j = %d, %0.6lf, %0.6lf\n",j,cur1,cur2);
			cur=cur1+cur2;
			if(cur<best)
				best=cur;
		}
		cur=(double)(B+2);
		//printf("%0.6lf\n",cur);
		if(cur<best)
			best=cur;
		//printf("best = %0.6lf\n",best);getchar();
		fprintf(fout,"Case #%d: %0.6lf\n",i,best);
	}

	fclose(fin);
	fclose(fout);
	printf("Time taken = %lf\n",(double)(clock()-t0)/(double)CLOCKS_PER_SEC);
	return 0;
}