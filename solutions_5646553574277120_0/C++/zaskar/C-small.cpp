#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

bool test(vector<char> D, int v) {
	for(int i=v;i>0;i--) { 
		if (D[i]=='s') {
			for(int j=v;j>i;j--) { 
				if (D[j]!='n') {
					if (j+i<=v && D[j+i]=='n') D[j+i]='f';
				}
			}
		}
	}
	for(int i=1;i<=v;i++) {  
		if (D[i]=='n') 
			return false;
	}
	return true;
}

bool fix(vector<char> D, int v, int rec) {
	if (rec==0) {
		return test(D,v);
	} else {
		for(int i=1;i<=v;i++) { 
			if (D[i]=='n') {
				D[i]='s';
				if (fix(D,v,rec-1)) return true;
				D[i]='n';
			}
		}
	}
	return false;
}


int main(int argc, char *argv[]) {
	ifstream fin("C-small-attempt1.in");
	ofstream fout("C-small-attempt1.out");
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		int c,d,v;
		fin>>c>>d>>v;
		vector<char> D(v+1,'n');
		for(int i=0;i<d;i++) {
			int x;
			fin>>x;
			if (x<=v) D[x]='s';
		}
		
		int r=0;
		while (!fix(D,v,r)) {
			r++;
		}
		
		fout<<"Case #"<<I+1<<": "<<r<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

