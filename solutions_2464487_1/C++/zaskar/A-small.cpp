#include <iostream>
#include <fstream>
using namespace std;

bool test(unsigned long long n, unsigned long long r, unsigned long long t) {
	return 2*n*r+n*(2*n-1)<=t;
}


int main(int argc, char *argv[]) {
	ifstream fin("A-large.in");
	ofstream fout("A-large.out");
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		unsigned long long r,t;
		fin>>r>>t;
		unsigned long long n0=1,n1=2;
		while (n0!=n1) {
			while (test(n1,r,t)) {
				n0=n1; n1*=2;
			}
			n1=(n0+n1)/2;
		}
		fout<<"Case #"<<I+1<<": "<<n0<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

