#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <math.h>
#include <map>
#include <set>

using namespace std;

const int MX=4000001;
int mem[MX];
int mem2[MX];
int p[MX];

double doit2(vector<int> &v, int sum, int idx) {
	double lo=0.0,hi=1.0;
	for(int i=0;i<100;i++) {
		double mid=(lo+hi)/2;
		double myScore=v[idx]+sum*mid;
		double audienceSum=mid;
		for(int j=0;j<v.size();j++) {
			if(j==idx) continue;
			if(v[j]>=myScore) continue;
			double needed=(myScore-v[j])/sum;
			audienceSum+=needed;
		}
		if(audienceSum>=1.0) {
			hi=mid;
		} else {
			lo=mid;
		}
	}
	return lo;
}

void doit(int testcase, ifstream &infile, ofstream &outfile) {
	int N;
	vector<int> v;
	int sum=0;
	infile >> N;
	for(int i=0;i<N;i++) {
		int j;
		infile >> j;
		v.push_back(j);
		sum+=j;
	}
	outfile << "Case #" << testcase << ":"; 
	for(int i=0;i<N;i++) {
		outfile << setiosflags(ios::fixed) << setprecision(8) << " " << doit2(v,sum,i)*100.0;
	}
	outfile << endl;
}

int main()
{
	ifstream infile;
	infile.open("A-small-attempt0.in");
	ofstream outfile("A-small-attempt0.out");
	//infile.open("in.txt");
	//ofstream outfile("out.txt");
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