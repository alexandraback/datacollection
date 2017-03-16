#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char *argv[]) {
	ifstream fin("C-large.in");
	ofstream fout("C-large.out");
	int C; fin>>C;
	for(int c=0;c<C;c++) {
		int r=0,n,m,d[10],p[10];
		fin>>n>>m;
		if (n>m) r=0; else {
			char *done=new char[m-n+1];
			memset(done,0,m-n+1);
			for(int i=n;i<=m;i++) { 
				int x=i, D=0,P=0,b;
				while (x) { d[D++]=x%10; x/=10; }
				for(int j=0;j<D;j++) { 
					x=0,b=1;
					for(int k=0;k<D;k++) { 
						x+=d[(k+j)%D]*b; b*=10;
					}
					if (x<n||x>m) continue;
					if (!done[x-n]) {
						bool valid=true;
						for(int k=0;k<P;k++) { 
							if (p[k]==x) { valid=false; break; }
						}
						if (valid) p[P++]=x;
						done[x-n]=1;
					}
				}
				x=0;
				for(int k=0;k<P;k++) { 
//					cerr<<p[k]<<" ";
					x+=k;
				}
//				cerr<<x<<endl;
				r+=x;
			}
			delete []done;
		}
		fout<<"Case #"<<c+1<<": "<<r<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

