#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int main(int argc,char **argv){
	int caseno,i,j;
	int T,N;
	double n[1000],k[1000];
	int score,newscore;
	FILE *fin,*fout;


	fin=fopen("D-large.in","rt");
	fout=fopen("D-large.out","wt");
	//fin=fopen("test.txt","rt");
	//fout=fopen("result.out","wt");



	fscanf(fin,"%d",&T);
	for(caseno=1;caseno<=T;caseno++){
		fscanf(fin,"%d",&N);
		for(i=0;i<N;i++)
			fscanf(fin,"%lf",&(n[i]));
		for(i=0;i<N;i++)
			fscanf(fin,"%lf",&(k[i]));

		sort(n,n+N,std::greater<double>());
		sort(k,k+N,std::greater<double>());

		score=0;
		for(i=0,j=0;(i<N)&&(j<N);i++){
			while((k[i]<n[j])&&(j<N)){
				j++;
			}
			if((k[i]>n[j])&&(j<N)){
				score++;
				j++;
			}
		}
		//printf("score = %d\n",score);

		newscore=0;
		for(i=0,j=0;(i<N)&&(j<N);i++){
			while((n[i]<k[j])&&(j<N)){
				j++;
			}
			if((n[i]>k[j])&&(j<N)){
				newscore++;
				j++;
			}
		}


		fprintf(fout,"Case #%d: %d %d\n",caseno,newscore,N-score);
	}
	fclose(fout);
	fclose(fin);

	return 0;
}