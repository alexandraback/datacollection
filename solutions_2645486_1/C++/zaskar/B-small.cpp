#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#define _unsigned unsigned
_unsigned long long func(_unsigned long long e0, _unsigned long long em, _unsigned long long e1, _unsigned long long *v, _unsigned long long n, _unsigned long long r) {
	if (n<=0) return 0;
	_unsigned long long mm=v[0], ii=0;
	for(_unsigned long long i=1;i<n;i++) if (v[i]>mm)  {mm=v[i]; ii=i;}
	
	_unsigned long long m=-1, im=0, mt=0, mr=0;
	_unsigned long long i=ii;
//	for(_unsigned long long i=0;i<n;i++) {
		_unsigned long long et=e0+i*r, er=0,ett; 
		if (et>em) ett=et=em; else ett=et;
		if (e1>=0 && (n-i)*r<e1) { er=(e1-(n-i)*r); et-=er; }
		if (et<0) { et=0; 
		cout<<"AAA";}
		_unsigned long long g=et*v[i];
		/*if (g>m)*/ { m=g; im=i; mt=ett; mr=er; }
//	}
	return func(e0,em,mt,v,im,r)+ m +func(mr+r,em,e1,v+im+1,n-im-1,r);
}

int main(int argc, char *argv[]) {
	
	ifstream fin("B-large.in");
	ofstream fout("B-large.out");
	
//	ifstream fin("B-sample.in") ;
//	ofstream fout("B-sample.out");
	_unsigned long long T;
	fin>>T;
	_unsigned long long *v=new _unsigned long long[100000];
	for(_unsigned long long I=0;I<T;I++) {
		_unsigned long long e,r,n;
		fin>>e>>r>>n;
		for(_unsigned long long i=0;i<n;i++) fin>>v[i];
		_unsigned long long g=func(e,e,-1,v,n,r);
		fout<<"Case #"<<I+1<<": "<<g<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

