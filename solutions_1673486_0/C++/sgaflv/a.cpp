#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <iostream>
#include <sstream>
#include <string>

#include <algorithm>
#include <vector>
#include <map>

#define N 10000010

using namespace std;

double p[100000];
int A, B;

int main() {
	int T;
	double res;
	cin>>T;
	int cas=0;
	
	
	
	while (cas++<T) {
		cin>>A>>B;
		for (int i=0;i<A;i++) {
			cin>>p[i];
			if (i>0) {
				p[i]=p[i]*p[i-1];
			}
		}
		double mn=B+2;
		
		for (int d=0;d<A;d++) {
			
			double cur=p[A-1-d]*(B-A+1+2*d)+(1-p[A-1-d])*(B-A+2*d+1+B+1);
//		cout<<"Case #"<<cas<<" "<<p[A-1-d]<<": "<<cur<<endl;
		
			if (cur<mn) mn=cur;
		}
		
		res=mn;
		printf("Case #%d: %0.9lf\n", cas, res);
	}
	
    return 0;
}
