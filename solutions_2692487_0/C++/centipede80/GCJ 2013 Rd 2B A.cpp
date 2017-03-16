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

int eval(int K, vector<int> v, int lim) {
	if(lim==0) return 0;
	else lim=v[lim-1];
	int pos=0;
	int ret=0;
	for(;;) {
		while(pos<v.size()&&K>v[pos]) {
			K+=v[pos];
			pos++;
		}
		if(K>lim) return ret;
		if(K==1) return 1<<30;
		K+=K-1;
		ret++;
		//cout<<K<<endl;
	}
	return ret;
}

int doit(int K, vector<int> v) {
	sort(v.begin(), v.end());
	int n=v.size();
	int ret=-1;
	for(int i=0;i<=v.size();i++) {
		int val=eval(K,v,i)+(n-i);
		//cout<<i<<" "<<val<<endl;
		if(ret==-1||ret>val) ret=val;
	}
	return ret;
}


int main()
{
	ifstream infile;
	string prefix = "A-small-attempt0";
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
		int K, N;
		infile>>K>>N;
		vector<int> v;
		for(int j=0;j<N;j++) {
			int t;
			infile>>t;
			v.push_back(t);
		}
		outfile << "Case #" << (i+1) << ": " << doit(K,v) << endl; 
		cout<<"--------------------"<<endl;
	}
	cout<<"DONE"<<endl;
	string zzz;
	cin>>zzz;
	outfile.close();
	return 0;
}