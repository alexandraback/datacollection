#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char *argv[]) {
	ifstream fin("B-large.in");
	ofstream fout("B-large.out");
	int C; fin>>C;
	for(int c=0;c<C;c++) { 
		int n,s,p,t,r=0,b,m;
		fin>>n>>s>>p;
		for(int i=0;i<n;i++) { 
			fin>>t;
			b=t/3; m=t%3;
			if (m==0) {
				if (b>=p) r++;
				else if (t &&s && b+1==p) { r++; s--; }
			} else if (m==1) {
				if (b+1>=p) r++;
			} else if (m==2) {
				if (b+1>=p) r++;
				else if (s && b+2==p) { r++; s--; }
			}
		}
		fout<<"Case #"<<c+1<<": "<<r<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

