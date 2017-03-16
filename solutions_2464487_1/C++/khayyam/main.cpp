#include <cmath>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <math.h>

using namespace std;
#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)<(b))?(b):(a))
#define ABS(x) (((x)<0)?(-(x)):(x))
#define SQR(x) ((x)*(x))
#define LL long long
int main(int argc, char *argv[]){
	int T;
	scanf("%d", &T);
	for(int c=1;c<=T;++c){
		LL r,t;
		cin>>r>>t;
		double lim=(LL)(sqrt((long double)(2*r-1)*(long double)(2*r-1)+8*(long double)(t)));
		lim=(lim-2*r)/4;
		LL M=lim;
		if(M<0){
			M=1;
		}
		while(M*(r*2-1+2*M)>t){
			M-=1;
		}
		while((M+1)*(r*2-1+2*(M+1))<=t){
			M+=1;
		}
		printf("Case #%d: %d\n", c, M);
	}
	return 0;
}

