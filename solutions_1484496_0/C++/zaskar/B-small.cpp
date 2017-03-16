#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

bool ok;
long long v[500];
int f[500];
int n1,n2;

void rec(long long d, int i,int n) {
	if (i==n) return;
	n1++; f[i]=1; if (n1>0 && n2>0 && d+v[i]==0) { ok=true; return; }
	rec(d+v[i],i+1,n); if (ok) return; n1--;
	n2++; f[i]=-1; if (n1>0 && n2>0 && d-v[i]==0) { ok=true; return; }
	rec(d-v[i],i+1,n); if (ok) return; n2--;
	f[i]=0; rec(d,i+1,n); if (ok) return;
}


int main(int argc, char *argv[]) {
	ifstream fin("C-small-attempt2.in");
	ofstream fout("C-small-attempt2.out");
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		int r,n;
		fin>>n;
		for(int i=0;i<n;i++) fin>>v[i];
		ok=false; n1=n2=0;
		memset(f,0,sizeof(f));
		rec(0,0,n);
		fout<<"Case #"<<I+1<<":"<<endl;
		if (ok) {
			bool p=false;
			for(int i=0;i<n;i++) { 
				if (f[i]>0) {
					if (p) fout<<" "; else p=true; 
					fout<<v[i];
				}
			}
			fout<<endl;
			p=false;
			for(int i=0;i<n;i++) { 
				if (f[i]<0) {
					if (p) fout<<" "; else p=true;
					fout<<v[i];
				}
			}
			fout<<endl;
		} else
			fout<<"Impossible"<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

