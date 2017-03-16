#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int solve(int a, int n, int *m) {
	int i=0;
	while (i<n && a>m[i]) { a+=m[i]; i++; }
	if (i==n) return 0;
	int r1=1+solve(a,n-i-1,m+i+1);
	if (a<2) return r1;
	int r2=0;
	while (a<=m[i]) {
		r2++; a+=(a-1);
	}
	r2+=solve(a,n-i,m+i);
	return r1>r2?r2:r1;
}

int main(int argc, char *argv[]) {
	ifstream fin("A-large.in");
	ofstream fout("A-large.out");
	int T;
	fin>>T;
	int m[1000];
	for(int I=0;I<T;I++) {
		int a,n;
		fin>>a>>n;
		for(int i=0;i<n;i++) { 
			fin>>m[i];
		}
		
		sort(m,m+n);
		int r=solve(a,n,m);
		fout<<"Case #"<<I+1<<": "<<r<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

