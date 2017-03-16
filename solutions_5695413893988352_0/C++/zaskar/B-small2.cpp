#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

int mind=-1, minc, minj;
string rC, rJ;
void solve(string C, string J, bool inv=false, bool sec=false) {
	for(size_t i=0;i<C.size();i++) { 
		if (C[i]=='?') {
			for(int j=0;j<10;j++) { 
				C[i]='0'+j;
				solve(C,J,inv);
			}
			return;
		}
	}
	if (!sec) solve(J,C,!inv,true);
	else {
		if (inv) swap(C,J);
		int nc = atoi(C.c_str()), nj=atoi(J.c_str());
		int d = abs(nc-nj);
		if (mind==-1 || d<mind || (d==mind && (nc<minc || (nc==minc && nj<minj)))) {
			mind=d; minc=nc; minj=nj;
			rC=C; rJ=J;
		}
	}
	
}

int main(int argc, char *argv[]) {
//	string fname = "B-sample";
	string fname = "B-small-attempt4";
	//	string fname = "B-large";
	ifstream fin(fname+".in");
	ofstream fout(fname+".out");
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		fin>>rC>>rJ;
		mind=-1;
		solve(rC,rJ);
		cout<<rC<<" "<<rJ<<endl;
		fout<<"Case #"<<I+1<<": "<<rC<<" "<<rJ<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

