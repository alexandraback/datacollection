#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

struct H {
	bool first;
	unsigned long long t0;
	unsigned long long d,m;
	void ini() {
		t0=m*(360-d)/360;
		first=true;
	}
	void next() {
		first=false;
		t0+=m;
	}
	bool operator<(const H &o) const { return t0<o.t0; }
};

int main(int argc, char *argv[]) {
	ifstream fin("C-small-1-attempt1.in");
	ofstream fout("C-small-1-attempt1.out");
	H *g= new H[500000];
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		unsigned long long ng=0;
		unsigned long long n;
		fin>>n;
		for(unsigned long long i=0;i<n;i++) {
			unsigned long long d,h,m;
			fin>>d>>h>>m;
			for(unsigned long long j=0;j<h;j++) {
				g[ng].d=d; 
				g[ng].m=(m+j)*360; 
				g[ng].ini(); 
				ng++;
			}
		}
		unsigned long long not_done=ng;
		unsigned long long r=ng, rmin=ng, t=0;
		sort(g,g+ng);
		while(not_done!=0) {
			t=g[0].t0;
			while (g[0].t0==t) {
				if (g[0].first) { r--; not_done--; } else r++;
				g[0].next();
				unsigned long long  p=0; 
				while (p+1<ng && g[p].t0>g[p+1].t0) { 
					swap(g[p],g[p+1]); p++;
				}
			}
			if (r<rmin) rmin=r;
		}
		
		fout<<"Case #"<<I+1<<": "<<rmin<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

