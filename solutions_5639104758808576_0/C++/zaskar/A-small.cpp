#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	ifstream fin("A-small-attempt0.in");
	ofstream fout("A-small-attempt0.out");
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		int Smax;
		fin>>Smax;
		fin.ignore(1);
		int r=0, up=0;
		for(int i=0;i<=Smax;i++) { 
			char c;
			fin>>c;
			int x = c-'0';
			if (c==0) continue;
			if (up<i) {
				r += i-up;
				up=i;
			}
			up += x;
		}
		fout<<"Case #"<<I+1<<": "<<r<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

