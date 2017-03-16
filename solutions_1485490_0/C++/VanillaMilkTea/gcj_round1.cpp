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

int N=0,M=0;
ull box=0;

void fitting(ull total,ull a[101][2],ull b[101][2],int pa,int pb){
	int i=0;
	ull min=0;
	ull aa[101][2];
	ull bb[101][2];
	//printf("%d,%d\n",pa,pb);
	if(pa>N)return;
	if(pb>M)return;
	for(i=1;i<=N;i++){
		aa[i][0]=a[i][0];
		aa[i][1]=a[i][1];
		//printf("%llu %llu ",a[i][0],a[i][1]);
	}
	//printf("\n");
	for(i=1;i<=M;i++){
		bb[i][0]=b[i][0];
		bb[i][1]=b[i][1];
		//printf("%llu %llu ",b[i][0],b[i][1]);
	}
	//printf("\n");getchar();
	if(aa[pa][1]==bb[pb][1]){
		min=aa[pa][0]>bb[pb][0]? bb[pb][0]:aa[pa][0];
		//printf("min = %llu\n",min);
		total+=min;
		if(box<total){
			box=total;
			//printf("%llu vs %llu\n",aa[pa][0],bb[pb][0]);
			//printf("found %llu\n",box);
		}
		aa[pa][0]-=min;
		bb[pb][0]-=min;
	}
	fitting(total,aa,bb,pa+1,pb);
	fitting(total,aa,bb,pa,pb+1);
}

int main(int argc,char **argv){
	FILE *fin,*fout;
	int cases=0;

	int i=0,j=0,k=0;
	ull a[101][2];
	ull b[101][2];
	clock_t t0;
	t0=clock();

	fin =fopen("C-small-attempt0.in","rt");
	fout=fopen("C-small-attempt0.out","wt");
	
	fscanf(fin,"%d\n",&cases);
	//printf("%d\n",cases);
	for(i=1;i<=cases;i++){
		fscanf(fin,"%d %d",&N,&M);
		//printf("%d %d\n",N,M);
		for(j=1;j<=N;j++){
			fscanf(fin,"%llu %llu",&a[j][0],&a[j][1]);
			//printf("%llu %llu ",a[j][0],a[j][1]);
		}
		//printf("\n");
		for(j=1;j<=M;j++){
			fscanf(fin,"%llu %llu",&b[j][0],&b[j][1]);
			//printf("%llu %llu ",b[j][0],b[j][1]);
		}
		//printf("\n");
		box=0;
		fitting(0,a,b,1,1);

		fprintf(fout,"Case #%d: %llu\n",i,box);
	}

	fclose(fin);
	fclose(fout);
	printf("Time taken = %lf\n",(double)(clock()-t0)/(double)CLOCKS_PER_SEC);
	return 0;
}