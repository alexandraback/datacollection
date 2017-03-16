#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main(){
	ifstream inf("in.txt");
	ofstream of("out.txt");
	int qN;
	inf>>qN;

	const string R="RICHARD";
	const string G="GABRIEL";
	for(int q=0; q<qN; ++q){
		int x,r,c; inf>>x>>r>>c;
		string win=G;
		int m=max(r,c);
		if (x>m) win=R; //larger than big
		if ((r*c)%x!=0) win=R; //not fill
		if (x>=7) win=R; //doom
		if (x==4 && min(r,c)<=2) win=R;
		if (x==5 && min(r,c)<=3) win=R;
		if (x==6 && min(r,c)<=3) win=R;

		of<<"Case #"<<q+1<<": "<<win<<endl;
	}
}