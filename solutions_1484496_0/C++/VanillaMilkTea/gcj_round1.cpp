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
unsigned long long arr[512],arr1[512],arr2[512],arr3[512];
int e1=0,e2=0;
int pass=0;
int found=0;

void findSum(unsigned long long tar,unsigned long long sum,int next,int max,int elems){
	int i=0,j=0;
	
	if(found) return;
	if(sum+arr[next]>tar)
		return;
	if(next==max)return;
	//printf("%llu %llu\n",sum,arr[next]);getchar();
	for(i=next;i<max;i++){
		arr1[elems]=arr[i];
		if(tar==sum+arr[i]){
			if(pass==0){
				//printf("pass0\n");
				pass++;
				for(j=0;j<=elems;j++){
					arr2[j]=arr1[j];
					//printf("%d ",arr1[j]);
				}
				e2=elems;
				//printf("\n");
			}
			else if(pass==1){
				//printf("pass1\n");
				for(j=0;j<=elems;j++){
					//printf("%d ",arr1[j]);
					arr3[j]=arr1[j];
				}
				//printf("\n");getchar();
				e1=elems;
				found=1;
				return;
			}
		}
		findSum(tar,sum+arr[i],i+1,max,elems+1);
	}
}

int main(int argc,char **argv){
	FILE *fin,*fout;
	int cases=0;
	int N=0;
	int i=0,j=0,q=0;
	unsigned long long k=0;
	unsigned long long total,max,min;
	int possible=0;
	clock_t t0;
	t0=clock();

	fin =fopen("C-small-attempt0.in","rt");
	fout=fopen("C-small-attempt0.out","wt");
	
	fscanf(fin,"%d\n",&cases);
	printf("%d\n",cases);
	for(i=1;i<=cases;i++){
		fscanf(fin,"%d",&N);
		//printf("%d ",N);
		total=0;
		possible=0;
		for(j=0;j<N;j++){
			fscanf(fin,"%llu",&arr[j]);
			//printf("%llu ",arr[j]);
			total+=arr[j];
		}
		sort(arr,arr+N);

		for(j=0;j<N-1;j++){
			if(arr[j]==arr[j+1]){
				fprintf(fout,"Case #%d:\n%llu\n%llu\n",i,arr[j],arr[j]);
				possible=1;
				break;
			}
		}
		if(j==N-1){
			//printf("\n");
			//printf("%llu\n",total);
			if(arr[N-1]==(total-arr[N-1])){
				fprintf(fout,"Case #%d:\n%llu\n",i,arr[j]);
				for(j=0;j<N-1;j++)
					fprintf(fout,"%llu ",arr[j]);
				fprintf(fout,"\n");
				possible=1;
			}
			else {
				//printf("%llu %llu\n",arr[0]+arr[1],total-arr[N-1]);getchar();
				for(k=arr[0]+arr[1];k<=total-arr[N-1];k++){
					pass=0;found=0;
					//printf("find %d: ",k);
					findSum(k,0,0,N,0);
					if(found){
						unsigned long long cal=0;
						int v=0;
						fprintf(fout,"Case #%d:\n",i);
						//printf("Case #%d:\n",i);
						/*
						while(1){
							fprintf(fout,"%llu ",arr1[v]);
							printf("%llu ",arr1[v]);
							cal+=arr1[v];
							if(cal==k)break;
							v++;
						}
						fprintf(fout,"\n");printf("\n");
						v=0;cal=0;
						while(1){
							fprintf(fout,"%llu ",arr2[v]);
							printf("%llu ",arr2[v]);
							cal+=arr2[v];
							if(cal==k)break;
							v++;
						}
						fprintf(fout,"\n");printf("\n");
						*/
						for(q=0;q<=e1;q++){
							fprintf(fout,"%llu ",arr3[q]);
							//printf("%llu ",arr3[q]);
						}
						fprintf(fout,"\n");
						for(q=0;q<=e2;q++){
							fprintf(fout,"%llu ",arr2[q]);
							//printf("%llu ",arr2[q]);
						}
						fprintf(fout,"\n");
						//printf("\n");
						possible=1;
						break;
					}
					//printf("%d\n",pass);
				}
				//getchar();
			}
		}
		if(!possible)
			fprintf(fout,"Case #%d: Impossible\n",i);
	}

	fclose(fin);
	fclose(fout);
	printf("Time taken = %lf\n",(double)(clock()-t0)/(double)CLOCKS_PER_SEC);
	return 0;
}