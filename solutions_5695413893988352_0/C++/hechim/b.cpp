#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
using namespace std;

ifstream fin("b.in");
ofstream fout("b.out");

string C,J;
int n;

int p10[] = {1,10,100,1000};

int iabs(int x) {
	return (x<0)?-x:x;
}

string stringify(int x, int len) {
	string str(len,'0');
	int i=len-1;
	while(x>0) {
		str[i] = (char)('0'+(x%10));
		x /= 10;
		i--;
	}
	return str;
}

bool valid(int x, int y) {
	for(int i=0; i<n; i++) {
		int xd = (x/p10[i])%10;
		int yd = (y/p10[i])%10;
		int cd = (C[n-i-1]=='?')?-1:(int)(C[n-i-1]-'0');
		int jd = (J[n-i-1]=='?')?-1:(int)(J[n-i-1]-'0');

		if( (cd>=0 && xd!=cd) || (jd>=0 && yd!=jd) )
			return false;
	}
	return true;
}

pair<string,string> getscore() {
	int dmin = 1000;
	int x0 = 0;
	int y0 = 0;
	for(int x=0; x<p10[n]; x++) {
		for(int y=0; y<p10[n]; y++) {
			if(valid(x,y)) {
				if(iabs(x-y)<dmin || (dmin==iabs(x-y) && x<x0) || (dmin==iabs(x-y) && x==x0 && y<y0)) {
					dmin = iabs(x-y);
					x0 = x;
					y0 = y;
				}
			}
		}
	}
	cout << x0 << " " << y0 << endl;
	string c = stringify(x0,n);
	string j = stringify(y0,n);
	return make_pair<string,string>(c,j);
}

int main() {

	int T; fin>>T;
	for(int t=1; t<=T; t++) {
		fin >> C >> J;
		n = (int)C.size();
		pair<string,string> s = getscore();
		fout << "Case #" << t << ": " << s.first << " " << s.second << endl;
	}
	return 0;

}
