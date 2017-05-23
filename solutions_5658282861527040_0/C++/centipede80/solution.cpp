#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

long long doit(long long A, long long B, long long K) {
	long long ret=0;
	for(long long i=0;i<A;i++) for(long long j=0;j<B;j++) if((i&j)<K) ret++;
	return ret;
}

int main()
{
	ifstream infile;
	//string prefix = "B-large-practice";
	//string prefix = "practice";
	//string prefix = "A-large";
	string prefix = "B-small-attempt0";
	infile.open(prefix + ".in");
	ofstream outfile(prefix + ".out");
	int cases;
	if (infile.is_open()) {
		infile>>cases;
	}
	else {
		return 0;
	}
	for(int i=0;i<cases;i++) {
		long long A,B,K;
		infile>>A>>B>>K;
		long long ret=doit(A,B,K);
		outfile << "Case #" << (i+1) << ": " << ret << endl; 
	}
	cout<<"DONE"<<endl;
	string zzz;
	cin>>zzz;
	outfile.close();
	return 0;
}