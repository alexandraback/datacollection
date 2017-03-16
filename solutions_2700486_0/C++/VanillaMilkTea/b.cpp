#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

#define _USE_MATH_DEFINES
#define ARRHT 5
#define ARRLEN 2

using namespace std;

//int arr[ARRHT][ARRLEN]={{5,2},{3,4},{10,1},{2,3},{6,0}};
int arr[1416];

typedef unsigned long long ull;

double binom(int res, int tar){
	int i=0;
	double n=(double)res;
	double r=(double)tar;
	double prob=1.0;

	for(i=1;i<=tar;i++){
		prob=prob*(n+1.0-((double)i))/((double)i);
		//printf("%lf / %lf\n",(n+1.0-((double)i)),((double)i));
		//printf("%lf\n",prob);
	}

	return prob;
}

int BinarySearch2D(int arr[ARRHT][ARRLEN],int key, int val, int start, int end)
{
	int cur_pos = 0;
	//if (!arr) return -1;

	if (end < start)
		return -1;
	cur_pos = (start+end)>>1;
	if (arr[cur_pos][key] == val)
		return cur_pos;
	if (arr[cur_pos][key] > val)
		return BinarySearch2D(arr, key, val, start, cur_pos-1);
	else
		return BinarySearch2D(arr, key, val, cur_pos+1, end);
}

void quickSort2D(int arr[ARRHT][ARRLEN],int key, int left, int right) {
	int i = left, j = right, k=0;
	int tmp;
	int pivot = arr[(left + right) / 2][0];
	/* partition */
	while (i <= j) {
		while (arr[i][key] < pivot)
			i++;
		while (arr[j][key] > pivot)
			j--;
		if (i <= j) {
			for(k=0;k<ARRLEN;k++){
				tmp = arr[i][k];
				arr[i][k] = arr[j][k];
				arr[j][k] = tmp;
			}
			i++;
			j--;
		}
	};
	/* recursion */
	if (left < j)
		quickSort2D(arr, key, left, j);
	if (i < right)
		quickSort2D(arr, key, i, right);
}

int main(int argc,char **argv){
	FILE *fin,*fout;
	int cases=0;
	int N=0,X=0,Y=0;
	int i=0,j=0,k=0;
	clock_t t0;
	t0=clock();
	int pos=0,res=0;
	int tar=0,rem=0;
	float prob=0,tprob=0;

	//printf("binom 5 7 = %lf\n",binom(7,5));
	//return 0;

	fin =fopen("B-small-attempt2.in","rt");
	fout=fopen("B-small-attempt2.out","wt");

	arr[1]=1;
	for(i=2;i<1416;i++){
		arr[i]=arr[i-1]+i;
		//printf("arr[%d] = %d\n",i,arr[i]);
	}
	
	fscanf(fin,"%d\n",&cases);
	for(i=1;i<=cases;i++){
		fprintf(fout,"Case #%d: ",i);
		fscanf(fin,"%d %d %d",&N,&X,&Y);
		//printf("i = %d\n",i);

		if(N==1){
			if((X==0)&&(Y==0))
				fprintf(fout,"1.0\n");
			else
				fprintf(fout,"0.0\n");
			continue;
		}

		j=1;
		while(arr[j]<=N) j+=2;
		j-=2;
		res=N-arr[j];

		//printf("j = %d\n",j);

		if(abs(X)+abs(Y)<j){
			fprintf(fout,"1.0\n");
			//printf("1\n");
			continue;
		}

		if((X==0)&&(Y==(j+1))){
			fprintf(fout,"0.0\n");
			//printf("2\n");
			continue;
		}
		if((abs(X)+abs(Y))!=(j+1)){
			fprintf(fout,"0.0\n");
			//printf("3\n");
			continue;
		}
		if(Y>res){
			fprintf(fout,"0.0\n");
			//printf("4\n");
			continue;
		}

		tar=Y+1;
		if(tar<=(res-(j+1))){
			fprintf(fout,"1.0\n");
			continue;
		}

		rem=res-tar;
		
		//printf("i = %d, res = %d, tar = %d, rem = %d\n",i,res,tar,rem);
		tprob=0.0;
		for(k=tar;k<=res;k++){
			prob=1.0*pow(0.5,res);
			prob*=binom(res,k);
			tprob+=prob;
		}
		fprintf(fout,"%lf\n",tprob);
		//printf("arr[%d] = %d, N = %d\n",j,arr[j],N);
	}
	
	
	fclose(fin);
	fclose(fout);

	printf("Time taken = %lf\n",(double)(clock()-t0)/(double)CLOCKS_PER_SEC);
	return 0;
}