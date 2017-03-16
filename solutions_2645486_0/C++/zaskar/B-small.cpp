#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int func(int e0, int em, int e1, int *v, int n, int r) {
	if (n<=0) return 0;
	int mm=v[0], ii=0;
	for(int i=1;i<n;i++) if (v[i]>mm)  {mm=v[i]; ii=i;}
	
	int m=-1, im=0, mt=0, mr=0;
	int i=ii;
//	for(int i=0;i<n;i++) {
		int et=e0+i*r, er=0,ett; 
		if (et>em) ett=et=em; else ett=et;
		if (e1>=0 && (n-i)*r<e1) { er=(e1-(n-i)*r); et-=er; }
		if (et<0) 
			cout<<"AAA";
		int g=et*v[i];
		/*if (g>m)*/ { m=g; im=i; mt=ett; mr=er; }
//	}
	return func(e0,em,mt,v,im,r)+ m +func(mr+r,em,e1,v+im+1,n-im-1,r);
}

int main(int argc, char *argv[]) {
	
	ifstream fin("B-small-attempt2.in");
	ofstream fout("B-small-attempt2.out");
	
//	ifstream fin("B-sample.in") ;
//	ofstream fout("B-sample.out");
	int T;
	fin>>T;
	int *v=new int[100000];
	for(int I=0;I<T;I++) {
		int e,r,n;
		fin>>e>>r>>n;
		for(int i=0;i<n;i++) fin>>v[i];
		int g=func(e,e,-1,v,n,r);
		fout<<"Case #"<<I+1<<": "<<g<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

