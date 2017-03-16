#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc,char **argv){
	FILE *fin,*fout;
	int i=0,j=0,k=0,cases=0;
	int a=0,b=0;
	int digits=0,tmp=0,residue=0,coeff=0;
	int numPairs=0;
	clock_t t0;
	t0=clock();

	fin =fopen("C-large.in","rt");
	fout=fopen("C-large.out","wt");
	
	fscanf(fin,"%d\n",&cases);
	
	for(i=0;i<cases;i++){
		fscanf(fin,"%d %d\n",&a,&b);

		tmp=a;
		for(digits=0;tmp>=1;digits++)tmp/=10;

		if(digits==1){
			printf("Case #%d: 0\n",i+1);
			fprintf(fout,"Case #%d: 0\n",i+1);
			continue;
		}
		for(j=0,coeff=1;j<digits-1;j++)
			coeff*=10;

		numPairs=0;

		for(j=a;j<=b;j++){
			vector< int > arr;
			tmp=j;
			for(k=0;k<digits-1;k++){
				tmp=(tmp/10)+(tmp%10)*coeff;
				if((tmp>j) && (tmp<=b)){
					arr.push_back(tmp);
				}
			}
			
			if(arr.size()>0){
				numPairs++;
				
				sort(arr.begin(),arr.end());
				for(k=0;k<arr.size()-1;k++){
					if(arr[k+1]!=arr[k]){
						numPairs++;
					}
				}
			}
		}
		printf("Case #%d: %d\n",i+1,numPairs);
		fprintf(fout,"Case #%d: %d\n",i+1,numPairs);
	}

	fclose(fin);
	fclose(fout);
	printf("Time taken = %lf\n",(double)(clock()-t0)/(double)CLOCKS_PER_SEC);
	return 0;
}