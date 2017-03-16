#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <math.h>
using namespace std;

ifstream f;
typedef long long int int64;

void process() {
	int j,p,s,k;
	int s_;						//o riginal shirt cnt
	f >> j >> p >> s >> k;	s_ = s;
	// don't need to consider j as it's most smallest
	int pmax = j*s*k;
//	if (pmax < j*k) pmax = j*k;
	if (p > pmax) p = pmax;		// maximum type of pants
	if (s > k) s = k;			// maximum type of shirts
	int t = j*p*s;
	cout << t << endl;
	int c_=1;
	for (int a=1; a<=j; a++)
		for (int b=1; b<=p; b++)
			for (int c=1; c<=s; c++) {
				cout << a << " " << b << " " << c_ << endl;
				c_++;
				if (c_ > s_) c_=1;
			}
}

int main(int argc, char** argv) {
	f.open(argc>=2?argv[1]:"input.txt");
	int n;	f >> n;
	for (int i=0; i<n; i++) {
		cout << "Case #" << i+1 << ": ";
		process();
	}
	f.close();
	return 0;
}
