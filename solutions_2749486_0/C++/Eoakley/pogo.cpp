#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>

using namespace std;

int px, py;
//int dmax = 0;
bool valid(int x, int y, int n, int it) {
	int d = abs(x-px) + abs(y-py);
	int an = (n+(it-1))*1;
	if(an < 0) return false;
	int max = (n + an) * it / 2;
	if(d > max) return false;
	else return true;
	
}

string jump(int x, int y, int n, int it) {
//if(abs(x) + abs(y) > dmax) dmax = abs(x) + abs(y);
	if(it < 1 && px != x && py != y) return "0";
	if(!valid(x,y,n,it)) return "0";
	string ret = "0";
	if(px == x && py == y) return "";
	
	else {
		string r;
		r = jump(x+n,y,n+1,it-1);
		if(r != "0") {return "E" + r; }
		
		r = jump(x-n,y,n+1,it-1);
		if(r != "0") {return "W" + r; }
		
		r = jump(x,y+n,n+1,it-1);
		if(r != "0") {return "N" + r; }
		
		r = jump(x,y-n,n+1,it-1);
		if(r != "0" ) {return "S" + r; }
	}
	return "0";
}

int main() {
	int T;
	cin >> T;
	int C=1;
	while(T-- > 0) {
		
		cin >> px >> py;
		
		string resp;
		for(int i=1;i<500;i++) {
		//cout << i <<" dmax " <<dmax<<endl;
			string s = jump(0,0,1,i);
			if(s != "0") { resp = s; break;}
			//if(min < 500) break;
		}
		
		
		cout << "Case #"<<C++<<": "<<resp<<endl;
	}

	return 0;
}

