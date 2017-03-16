//============================================================================
// Name        : GCJ.cpp
// Author      : Dung
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cassert>
#include <cmath>
#include <cstdlib>

#define rep(i,j,n) for (int i=j ; i < (int)n; ++i)
#define add push_back
#define ms(mat,val) memset(mat,val,sizeof(mat))


using namespace std;

typedef long long LL;
typedef unsigned long long ULL;


int main() {
	ifstream in("input");
	ofstream out("output");
	int T;
	in >> T;
	for(int t = 1; t <= T;++t) {
		int xx,yy;
		in >> xx >> yy;
		int x = abs(xx);
		int y = abs(yy);
		int sum = 0;
		string N = "SN", S = "NS", E = "WE", W = "EW";
		string res;
		rep(i,0,y) {
			if (yy >0)
				res += N;
			else
				res += S;
		}
		rep(i,0,x) {
			if (xx > 0)
				res += E;
			else
				res += W;
		}
		out << "Case #" << t << ": " << res << endl;
	}
	return  0;
}
