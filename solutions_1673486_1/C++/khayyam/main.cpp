#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
#define MIN(a,b) (((a)<(b))?(a):(b))
double P[1000000];
double a[1000000];
int main(int argc, char *argv[]){
	int T,A,B;
	cin>>T;
	for(int c=1;c<=T;++c){
		cin>>A>>B;
		for(int i=0;i<A;++i){
			cin>>a[i];
		}
		P[0]=a[0];
		for(int i=1;i<A;++i){
			P[i]=P[i-1]*a[i];
		}
		double best=B+2;
		for(int i=0;i<A;++i){
			double opc=B-(A-i)+i+1+(B+1)*(1.0-P[A-i-1]);
			if(opc<best){
				best=opc;
			}
		}
		printf("Case #%d: %0.15lf\n",c, best);
	}
	
	return 0;
}

