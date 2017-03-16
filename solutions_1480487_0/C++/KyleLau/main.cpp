#include <stdio.h>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <stdio.h>
#include <sstream>
#include <string>
#include <string.h>
#include <vector>
#include <math.h>
#include <map>
#define MaxLength INT_MAX
#define MaxNode 12
#define MN 2000005
using namespace std;

int M,T,N,S;
int mem[MN];
int size;
int main(){
	int i,j,k,l,tt,a,b;
	double res;
	long long total;
	scanf("%d",&T);
	for(tt=1; tt<=T;tt++){
		total = res = 0;
		scanf("%d",&N);
		for(i=0; i<N ;i++){
			scanf("%d",&mem[i]);
			total += mem[i];
		}
		printf("Case #%d:",tt);
		for(i=0; i<N; i++){
			double up = 1, lower =0;
			while(up>lower+1e-12){
				double mid = (up + lower)/2;
				if((mem[i]* (N) + total * mid * (N-1) >= (total + total * (1 - mid))+1e-10))
					up = mid;
				else
					lower = mid;
			}
			printf(" %.8lf",up*100);
		}
		puts("");
	}

	return 0;
}
