#include <iostream>
#include <fstream>
using namespace std;

bool test(long long n, long long r, long long t) {
	return 2*n*r+n*(2*n-1)<=t;
}


int main(int argc, char *argv[]) {
	ifstream fin("A-small-attempt0.in");
	ofstream fout("A-small-attempt0.out");
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		long long r,t;
		fin>>r>>t;
		long long n0=1,n1=2;
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

