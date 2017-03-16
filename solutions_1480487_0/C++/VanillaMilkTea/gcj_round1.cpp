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
	int N=0,realN=0;
	int i=0,j=0,k=0;
	int total=0,realT=0;
	int arr[200];
	double val=0.0,avg=0.0,passing=0.0;
	clock_t t0;
	t0=clock();

	fin =fopen("A-small-attempt1.in","rt");
	fout=fopen("A-small-attempt1.out","wt");
	
	fscanf(fin,"%d\n",&cases);
	//printf("%d\n",cases);
	for(i=1;i<=cases;i++){
		fscanf(fin,"%d",&N);
		//printf("%d ",N);
		total=0;
		for(j=1;j<=N;j++){
			fscanf(fin,"%d",&arr[j]);
			//printf("%d ",arr[j]);
			total+=arr[j];
		}
		avg=(double)total*2.0/(double)N;
		realN=0;realT=0;
		for(j=1;j<=N;j++){
			if((double)arr[j]<avg){
				realN++;
				realT+=arr[j];
			}
		}
		passing=(double)(realT+total)/realN;
		printf("%d: %0.5lf\n",i,passing);
		
		fprintf(fout,"Case #%d: ",i);
		for(j=1;j<=N;j++){
			val=(passing-(double)arr[j])/(double)total*100.0;
			//val=(((double)total*2.0/(double)N)-(double)arr[j])/(double)total*100.0;
			if((double)arr[j]<avg)
				fprintf(fout,"%0.6lf ",val);
			else
				fprintf(fout,"0.000000 ");
		}
		fprintf(fout,"\n");
	}

	fclose(fin);
	fclose(fout);
	printf("Time taken = %lf\n",(double)(clock()-t0)/(double)CLOCKS_PER_SEC);
	return 0;
}