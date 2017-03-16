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

int e[1001][1001];
int d[1001];
int f[1001];

int found=0;

void recur(int v){
	int i=0;
	f[v]=1;
	/*
	for(i=1;i<=1000;i++){
		if(f[i])
			printf("%d ",i);
	}
	*/
	//printf("\n");getchar();
	for(i=1;i<=d[v];i++){
		if(!f[e[v][i]]){
			recur(e[v][i]);
		}
		else {
			found=1;
			return;
		}
	}
}

int main(int argc,char **argv){
	FILE *fin,*fout;
	int cases=0;
	int N=0;
	int i=0,j=0,k=0;
	int num=0;
	clock_t t0;
	t0=clock();

	fin =fopen("A-small-attempt2.in","rt");
	fout=fopen("A-small-attempt2.out","wt");
	
	fscanf(fin,"%d\n",&cases);
	printf("%d\n",cases);
	for(i=1;i<=cases;i++){
		fscanf(fin,"%d",&N);
		printf("%d\n",N);
		for(j=1;j<=N;j++){
			fscanf(fin,"%d",&d[j]);
			printf("%d: ",d[j]);
			for(k=1;k<=d[j];k++){
				fscanf(fin,"%d",&e[j][k]);
				printf("%d ",e[j][k]);
			}
			printf("\n");
		}
		//getchar();
		found=0;
		for(j=1;j<=N;j++){
			memset(f,0x0,1001*4);
			recur(j);
			if(found)break;
		}

		if(found) fprintf(fout,"Case #%d: Yes\n",i);
		else fprintf(fout,"Case #%d: No\n",i);
	}

	fclose(fin);
	fclose(fout);
	printf("Time taken = %lf\n",(double)(clock()-t0)/(double)CLOCKS_PER_SEC);
	return 0;
}