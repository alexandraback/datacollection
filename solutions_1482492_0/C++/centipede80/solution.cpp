#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <math.h>
#include <map>
#include <set>
#include <iomanip>

using namespace std;

double doit2(vector<double> ts, vector<double> xs, double d, double a) {
	if(xs.size()==1) {
		return sqrt(2*d/a);
	}
	double v=(xs[1]-xs[0])/(ts[1]-ts[0]);
	double t=(d-xs[0])/v;
	double t2=sqrt(2*d/a);
	return max(t,t2);
}

void doit(int testcase, ifstream &infile, ofstream &outfile) {
	double D;
	int N, A;
	infile>>D>>N>>A;
	vector<double> ts, xs;
	for(int i=0;i<N;i++) {
		double t, x;
		infile>>t>>x;
		ts.push_back(t);
		xs.push_back(x);
	}
	outfile << "Case #" << setiosflags(ios::fixed) << setprecision(8) << testcase << ":" << endl; 
	for(int i=0;i<A;i++) {
		double a;
		infile>>a;
		outfile << doit2(ts,xs,D,a) << endl;
	}
}

int main()
{
	ifstream infile;
	//infile.open("in.txt");
	//ofstream outfile("out.txt");
	infile.open("B-small-attempt0.in");
	ofstream outfile("B-small-attempt0.out");
	int cases;
	if (infile.is_open()) {
		infile>>cases;
	}
	else {
		return 0;
	}
	for(int i=0;i<cases;i++) {
		doit(i+1,infile,outfile);
	}
	cout<<"DONE"<<endl;
	string zzz;
	cin>>zzz;
	outfile.close();
	return 0;
}