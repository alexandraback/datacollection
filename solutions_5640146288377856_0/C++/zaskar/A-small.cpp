#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;


int res(int c,int w) {
	if (c==w) return w;
	int x=c/w-1;
	if (x==0) {
		if (w==c) return w;
		else return w+1;
	}
	return x+res(c-w*x,w);
	
//	if (c==w) return w;
//	if (w==1) return c;
//	if (w==2) return c/w+((c%2)==0?1:2);
//	return c/w+w;
}

int main(int argc, char *argv[]) {
	ifstream fin("A-small-attempt2.in");
	ofstream fout("A-small-attempt2.out");
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		int r,c,w;
		fin>>r>>c>>w;
		fout<<"Case #"<<I+1<<": "<< r*res(c,w) <<endl;
	}
	fin.close();
	return 0;
}

