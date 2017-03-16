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

typedef unsigned long long ull;

int main(int argc,char **argv){
	FILE *fin,*fout;
	int cases=0;
	int N=0,M=0;
	int i=0,j=0,k=0;
	clock_t t0;
	t0=clock();
	char tmp=0;
	int ht[100][100];
	int maxN[100],maxM[100],max=0,check=0;
	/*
	fout=fopen("testLarge.in","wt");
	fprintf(fout,"100\n");
	for(i=1;i<=100;i++){
		fprintf(fout,"100 100\n");
		for(j=0;j<100;j++){
			for(k=0;k<100;k++){
				fprintf(fout,"%d ",(rand()%101));
			}
			fprintf(fout,"\n");
		}
	}
	fclose(fout);
	return 0;
	*/
	fin =fopen("B-large.in","rt");
	fout=fopen("B-large.out","wt");
	
	fscanf(fin,"%d\n",&cases);
	for(i=1;i<=cases;i++){
		fprintf(fout,"Case #%d: ",i);
		//printf("case %d\n",i);
		fscanf(fin,"%d %d",&N,&M);
		//if((N==1)||(M==1)){
//			fprintf(fout,"YES\n");
			//continue;
		//}

		for(j=0;j<N;j++){
			for(k=0;k<M;k++)
				fscanf(fin,"%d",&(ht[j][k]));
		}

		for(j=0;j<N;j++){
			maxN[j]=0;
			for(k=0;k<M;k++)
				if(ht[j][k]>maxN[j]) maxN[j]=ht[j][k];
			//printf("maxN[%d] = %d\n",j,maxN[j]);
		}
		for(j=0;j<M;j++){
			maxM[j]=0;
			for(k=0;k<N;k++)
				if(ht[k][j]>maxM[j]) maxM[j]=ht[k][j];
			//printf("maxN[%d] = %d\n",j,maxM[j]);
		}

		check=1;
		for(j=0;j<N;j++){
			for(k=0;k<M;k++){
				if(maxN[j]>maxM[k]) tmp=maxM[k];
				else tmp=maxN[j];
				if(ht[j][k]!=tmp) {
					//printf("%d %d\n",j,k);
					check=0;
					break;
				}
			}
			if(check==0) break;
		}
		if(check) fprintf(fout,"YES\n");
		else fprintf(fout,"NO\n");
	}
	
	
	fclose(fin);
	fclose(fout);

	printf("Time taken = %lf\n",(double)(clock()-t0)/(double)CLOCKS_PER_SEC);
	return 0;
}