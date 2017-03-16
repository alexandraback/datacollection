#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
//	string fname = "A-sample";
	string fname = "A-small-attempt0";
//	string fname = "A-large";
	ifstream fin(fname+".in");
	ofstream fout(fname+".out");
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		string S,r;
		fin>>S;
		r=S.substr(0,1);
		for(size_t i=1;i<S.size();i++) { 
			size_t j = 0;
			while (j<r.size() && S[i]==r[j]) j++;
			if (S[i]<r[j]) r+=string(1,S[i]);
			else r.insert(0,1,S[i]);
		}
		fout<<"Case #"<<I+1<<": "<<r<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

