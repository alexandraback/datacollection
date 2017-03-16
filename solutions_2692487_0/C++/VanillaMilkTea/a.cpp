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
int arr[110];

typedef unsigned long long ull;

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

void quickSort(int arr[100], int left, int right) {
	int i = left, j = right, k=0;
	int tmp;
	int pivot = arr[(left + right) / 2];
	/* partition */
	while (i <= j) {
		while (arr[i] < pivot)
			i++;
		while (arr[j] > pivot)
			j--;
		if (i <= j) {
			tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
			i++;
			j--;
		}
	};
	/* recursion */
	if (left < j)
		quickSort(arr, left, j);
	if (i < right)
		quickSort(arr, i, right);
}

int main(int argc,char **argv){
	FILE *fin,*fout;
	int T=0;
	int i=0,j=0,k=0;
	clock_t t0;
	t0=clock();
	int pos=0;
	int A=0,N=0,tmp=0,ops=0,jump=0,best=0;

	//for(i=0;i<5;i++){for(j=0;j<2;j++)printf("%d ",arr[i][j]);printf("\n");}printf("\n\n");
//	quickSort2D(arr,0,0,4);
	//for(i=0;i<ARRHT;i++){for(j=0;j<ARRLEN;j++)printf("%d ",arr[i][j]);printf("\n");}

//	pos=BinarySearch2D(arr,0,7,0,4);
//	printf("pos = %d\n",pos);

	fin =fopen("A-small-attempt2.in","rt");
	fout=fopen("A-small-attempt2.out","wt");
	
	fscanf(fin,"%d\n",&T);
	for(i=1;i<=T;i++){
		fprintf(fout,"Case #%d: ",i);
		//printf("case %d\n",i);
		fscanf(fin,"%d %d",&A,&N);
		for(j=0;j<N;j++)
			fscanf(fin,"%d",&(arr[j]));
		quickSort(arr,0,N-1);
		if(arr[N-1]<A){
			fprintf(fout,"0\n");
			continue;
		}

		k=0;
		while(A>arr[k]){
			A+=arr[k];
			k++;
			if(k==N)
				break;
		}
		if(k==N){
			fprintf(fout,"0\n");
			continue;
		}
		if((A==1)||(A==0)){
			fprintf(fout,"%d\n",(N-k));
			continue;
		}
		//if((k==0)||((A==1)&&(arr[k]==1))){
			//fprintf(fout,"%d\n",N);
		//}

		best=101;
		ops=0;
		//printf("k = %d\n",k);getchar();
		while(k!=N){
			//printf("k = %d, A = %d\n",k,A);
			if((ops+(N-k))<best) best=ops+(N-k);

			ops++;
			A+=(A-1);
			while(A>arr[k]){
				A+=arr[k];
				k++;
				if(k==N)
					break;
			}
			if((ops+(N-k))<best) best=ops+(N-k);
			/*
			tmp=A;jump=0;
			while(tmp<=arr[k]){
				tmp+=(tmp-1);
				jump++;
			}
			if(jump>=(N-k)){
				//ops+=(N-k);
				best=ops+(N-k);
				break;
			}
			else {
				
			}
			*/
			/*
			if((A+(A-1))>arr[k]){
				A+=(A-1);
				while(A>arr[k]){
					A+=arr[k];
					k++;
					if(k==N)
						break;
				}
			}
			else {
				N--;
			}
			*/
			//ops++;
		}
		fprintf(fout,"%d\n",best);
	}
	
	
	fclose(fin);
	fclose(fout);

	printf("Time taken = %lf\n",(double)(clock()-t0)/(double)CLOCKS_PER_SEC);
	return 0;
}