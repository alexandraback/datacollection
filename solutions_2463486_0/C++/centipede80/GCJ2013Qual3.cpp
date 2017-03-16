// GCJ 2011 Qual 1.cpp : main project file.

// Test.cpp : main project file.

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

vector<long long> v;
vector<long long> w;

bool isPal(long long n) {
	stringstream ss;
	ss << n;
	string s=ss.str();
	for(int i=0;i<s.size();i++) if(s[i]!=s[s.size()-1-i]) return false;
	return true;
}

void precompute() {
	for(long long i=1;i<=100000;i++) {
		if(isPal(i) && isPal(i*i)) {
			v.push_back(i*i);
		}
	}
	for(long long i=1;i<=10000;i++) {
		{
			long long suffix=0,prefix=i,j=i;
			while(j) {
				prefix*=10;
				suffix=suffix*10+j%10;
				j/=10;
			}
			long long num=prefix+suffix;
			if(isPal(num) && isPal(num*num)) {
				w.push_back(num*num);
			}
		}
		{
			long long suffix=0,prefix=i,j=i/10;
			while(j) {
				prefix*=10;
				suffix=suffix*10+j%10;
				j/=10;
			}
			long long num=prefix+suffix;
			if(isPal(num) && isPal(num*num)) {
				w.push_back(num*num);
			}
		}
	}
	sort(w.begin(),w.end());
	cout<<v.size()<<" "<<w.size()<<endl;
	for(int i=0;i<w.size();i++) {
		if(i<v.size()) {
			cout<<v[i]<<" "<<w[i]<<endl;
		}
	}
}

int doit(long long low, long long high) {
	int ret=0;
	for(int i=0;i<w.size();i++) if(w[i]>=low&&w[i]<=high) {
		ret++;
	}
	return ret;
}

int main()
{
	ifstream infile;
	string prefix = "C-small-attempt0";
	infile.open(prefix + ".in");
	ofstream outfile(prefix + ".out");
	int cases;
	if (infile.is_open()) {
		infile>>cases;
	}
	else {
		return 0;
	}
	precompute();
	for(int i=0;i<cases;i++) {
		long long low, high;
		infile>>low>>high; 
		outfile << "Case #" << (i+1) << ": " << doit(low,high) << endl; 
	}
	cout<<"DONE"<<endl;
	string zzz;
	cin>>zzz;
	outfile.close();
	return 0;
}