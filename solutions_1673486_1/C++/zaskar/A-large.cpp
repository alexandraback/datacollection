#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	ifstream fin("A-large.in");
	ofstream fout("A-large.out");
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		double r;
		int a,b;
		fin>>a>>b;
		double min=b+2, p=1,x;
		double x0=2*a+b+1;
		if (x0<min) min=x0;
		for(int i=1;i<=a;i++) {
			fin>>r;
			p*=r;
			int nok=(a-i+b-i+1);
			double pok=p*nok;
			int nbd=nok+b+1;
			double pbd=(1-p)*nbd;
			double x=pok+pbd;
			if (x<min) min=x;
		}
		cout<<"Case #"<<I+1<<": "<<min<<endl;
		fout<<"Case #"<<I+1<<": "<<min<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

