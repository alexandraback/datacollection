#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

using number = unsigned long long;

int main(int argc, char *argv[]) {
	ifstream fin("D-large.in");
	ofstream fout("D-large.out");
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		int k,c,s;
		fin>>k>>c>>s;
		
		int rs = k/c;
		if (rs*c<k) ++rs;
		
		if (rs>s) {
			fout << "Case #"<<I+1<<": IMPOSSIBLE"<<endl;
		} else {
			vector<number> p(rs,0);
			int ndone = k;
			for(int i=0;i<c;i++) {
				for(int j=0;j<rs;j++) { 
					p[j] = p[j]*k + (ndone>0?(--ndone):0);
				}
			}
			fout << "Case #"<<I+1<<":";
			for(number x:p) fout<<" "<<x+1;
			fout << endl;
		}
	}
	fin.close();
	fout.close();
	return 0;
}

