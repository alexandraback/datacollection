#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
using std::vector;

//		#define out stdout
//		#define in stdin
	
int main(void)
{
#ifndef in
	FILE *in;
	in=fopen("A-large.in","rt");
	if(in==NULL){
		printf("\a");
		return -1;
	}
#endif
#ifndef out
	FILE *out;
	out=fopen("a.txt","wt");
	if(out==NULL){
		printf("\a");	
		return -1;
	}
#endif
	int T,t,A,N;
	fscanf(in,"%d",&T);
	for(t=1;t<=T;++t){
		fscanf(in,"%d %d",&A,&N);
		vector<int> num(N);
		for(int i=0;i<N;++i){
			fscanf(in,"%d",&num[i]);
		}
		sort(num.begin(),num.end());
		int sum=0;
		if(A==1)
			sum=N;
		else
		for(int i=0;i<N;++i){
			int tsum=0;
			while(A<=num[i]){
				A+=A-1;
				++tsum;
			}
			if(tsum>=N-i){
				sum+=N-i;
				break;
			}
			else
				sum+=tsum;
			A+=num[i];
		}
		fprintf(out,"Case #%d: %d\n",t,sum);
	}

#ifndef in
	fclose(in);
#endif
#ifndef out
	fclose(out);
#endif
	return 0;
}
