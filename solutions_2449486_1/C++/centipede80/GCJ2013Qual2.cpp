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

using namespace std;

string doit(vector<vector<int> > w, int m, int n) {
	for(int i=0;i<m;i++) for(int j=0;j<n;j++) {
		bool ok=true;
		for(int i2=0;i2<m;i2++) if(w[i2][j]>w[i][j]) ok=false;
		if(ok) continue;
		ok=true;
		for(int j2=0;j2<n;j2++) if(w[i][j2]>w[i][j]) ok=false;
		if(ok) continue;
		cout<<w[i][j]<<endl;
		return "NO";
	}
	return "YES";
}

int main()
{
	ifstream infile;
	string prefix = "B-large";
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
		int m, n;
		infile>>m>>n;
		vector<vector<int> > vs;
		for(int j=0;j<m;j++) {
			vector<int> v;
			for(int k=0;k<n;k++) {
				int h;
				infile>>h;
				v.push_back(h);
			}
			vs.push_back(v);
		}	
		outfile << "Case #" << (i+1) << ": " << doit(vs,m,n) << endl; 
	}
	cout<<"DONE"<<endl;
	string zzz;
	cin>>zzz;
	outfile.close();
	return 0;
}