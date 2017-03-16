#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <math.h>
using namespace std;
#define LL __int64
#define MIN(a,b) (((a)<(b))?(a):(b))
int main(int argc, char *argv[]){
	int T;
	cin>>T;
	for(int c=1;c<=T;++c){
		double D;
		int N,A;
		cin>>D>>N>>A;
		double t0,x0,t1,x1;
		cin>>t0>>x0;
		if(N>1){
			cin>>t1>>x1;
		}
		printf("Case #%d:\n",c);
		for(int i=0;i<A;++i){
			double a;
			cin>>a;
			if((N<2) || (D<x0)){
				double th=sqrt(2*D/a);
				printf("%0.9lf\n",th);
			}else{
				double th=t1*(D-x0)/(x1-x0);
				double ah=2*D/(th*th);
				if(ah<=a){
					printf("%0.9lf\n",th);
				}else{
					th=sqrt(2*D/a);
					printf("%0.9lf\n",th);
				}
			}
		}
	}

	return 0;
}

