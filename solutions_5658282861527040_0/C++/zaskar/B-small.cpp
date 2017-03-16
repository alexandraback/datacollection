#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	ifstream fin("B-small-attempt1.in");
	ofstream fout("B-small-attempt1.out");
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		long long a,b,k;
		fin>>a>>b>>k;
		if (k>a && k>b) {
			fout<<"Case #"<<I+1<<": "<<a*b<<endl;
			cerr<<"asdaf "<<I+1<<endl;
		} else {
			if (a<b) { long long x=a; a=b; b=x; }
			long long r=k*b;
			if (b>k) {
				r+=k*(a-k); 
				for(long long i=k;i<a;i++) {
					for(long long j=k;j<b;j++) {
						if ((i&j)<k) r++;
					}
				}
			} else r+=b*(a-k);
			fout<<"Case #"<<I+1<<": "<<r<<endl;
		}
	}
	fin.close();
	fout.close();
	return 0;
}

