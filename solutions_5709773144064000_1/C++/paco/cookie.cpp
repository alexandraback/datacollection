#include<iostream>
#include<cstdio>

using namespace std;

int main() {

	int nCases;
	cin>>nCases;
	
	for(int n=0; n<nCases; n++) {
		double C,F,X;
		cin>>C;
		cin>>F;
		cin>>X;
		
		cout<<"Case #"<<n+1<<": ";
		
		double T0=X/2.;
		unsigned long long int m=0;
		while(1) {
			m++;
			double T=T0+X/(2.+m*F)-(X-C)/(2.+(m-1)*F);
			if(T>T0) break;
			T0=T;
		}
		printf("%.7f\n",T0);
		
	}

	return 0;
}
