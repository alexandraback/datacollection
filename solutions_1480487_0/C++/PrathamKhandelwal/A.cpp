#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
	int T,N,M;
	int i,j,k,t;
	double d,f;
	double lo,hi,mid;
	int A[250];
	
	t = 1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		
		M = 0;
		for(i=0;i<N;i++){
			scanf("%d",&A[i]);
			M += A[i];
		}
				
		printf("Case #%d:",t);
		for(i=0;i<N;i++){
			lo = 0; hi = 100;
			for(j=0;j<100;j++){
				mid = lo + (hi-lo)/2;
				f = A[i] + ((mid/100)*M);
				for(k=0,d=0;k<N;k++)
					d += max(0.0,f-A[k]);
				
				if(d >= M)
					hi = mid;
				else
					lo = mid;
			}
			printf(" %lf",lo);
		}
		printf("\n");
		t++;
	}
	return 0;
}