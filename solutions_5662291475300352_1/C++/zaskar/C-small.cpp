#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

#define tipo long double

struct H {
	bool first;
	tipo t0;
	 long long d;
	tipo m;
	void ini() {
		t0=(m*(360-d))/360.0;
		first=true;
	}
	void next(tipo tnext) {
		first=false;
		t0+=m*( (tnext-t0)/m +1);
		while (t0-m>=tnext) t0-=m;
	}
	bool operator<(const H &o) const { return t0<o.t0; }
};

int main(int argc, char *argv[]) {
	ifstream fin("C-small-2-attempt5.in");
	ofstream fout("C-small-2-attempt5.out");
	H *g= new H[5000000];
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		cerr<<I<<endl;
		 long long ng=0;
		 long long n;
		fin>>n;
		for( long long i=0;i<n;i++) {
			 long long d,h,m;
			fin>>d>>h>>m;
			for( long long j=0;j<h;j++) {
				g[ng].d=d; 
				g[ng].m=(m+j)/**360*/; 
				g[ng].ini(); 
				ng++;
			}
		}
		long long r=ng, rmin=ng;
		sort(g,g+ng);
		while(r<2*rmin+ng) {
			tipo t=g[0].t0;
			long long ne=0;
			tipo nt=t+1;
			while (ne<ng&&g[ne].t0==t) ne++;
			if (ne<ng) nt=g[ne].t0;
			for( long long i=0;i<ne;i++) { 
				if (g[i].first) r--;  else r++;
				g[i].next(nt);
			}
			sort(g,g+ng);
//			for( long long i=0;i<ne;i++) { 
//				 long long  p=ne-i-1; 
//				while (p+1<ng && g[p].t0>g[p+1].t0) { 
//					swap(g[p],g[p+1]); p++;
//				}
//			}
			if (r<rmin) rmin=r;
		}
		
		fout<<"Case #"<<I+1<<": "<<rmin<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

