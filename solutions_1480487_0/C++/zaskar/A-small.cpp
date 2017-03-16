#include <iostream>
#include <fstream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main(int argc, char *argv[]) {
	ifstream fin("A-small-attempt4.in");
	ofstream fout("A-small-attempt4.out");
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		int n,sum=0;
		int j[200],j2[200];
		fin>>n;
		for(int i=0;i<n;i++) { 
			fin>>j[i];
			j2[i]=j[i];
			sum+=j[i];
		}
		sort(j2,j2+n);
		fout<<"Case #"<<I+1<<":";
		for(int i=0;i<n;i++) { 
			double d=0,d2,r=0; int c=0,k; bool me=false;
			for(k=0;k<n-1;k++) {
				d2=d;
				d+=double(j2[k+1]-j2[k])/sum*double(1+k);
				if (d>1) { d=d2; break; }
			}
			if (k<n-1 && j[i]>=j2[k+1]) r=0; else {
				r=(1-d)/double(k+1)+double(j2[k]-j[i])/double(sum);
			}
			fout<<" "<<setprecision(20)<<fixed<<100*r;
		}
		fout<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

