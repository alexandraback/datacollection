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

int g[55][55];

string doit(vector<string> &zips) {
	int N=zips.size();
	vector<int> v;
	for(int i=0;i<N;i++) v.push_back(i);
	string ret="";
	do {
		string s="";
		for(int i=0;i<N;i++) {
			//if(s.size()) s=s+" ";
			s=s+zips[v[i]];
		}
		if(ret.size()>0&&s>ret) continue;

		vector<int> path;
		path.push_back(v[0]);
		bool isValid=true;
		for(int i=1;i<N;i++) {
			while(path.size()) {
				if(g[path[path.size()-1]][v[i]]) {
					path.push_back(v[i]);
					break;
				}
				path.pop_back();
			}
			if(path.size()==0) { isValid=false; break; }
		}
		if(isValid) {
			if(ret.size()==0||ret>s) ret=s;
		}
	} while(next_permutation(v.begin(),v.end()));
	return ret;
}

int main()
{
	ifstream infile;
	//string prefix = "B-large-practice";
	//string prefix = "practice";
	//string prefix = "B-large";
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
	for(int i=0;i<cases;i++) {
		int N,M;
		infile>>N>>M;
		for(int j=0;j<50;j++) for(int k=0;k<50;k++) g[j][k]=0;
		vector<string> zips;
		for(int j=0;j<N;j++) {
			string s;
			infile>>s;
			zips.push_back(s);
		}
		for(int j=0;j<M;j++) {
			int v,w;
			infile>>v>>w;
			v--; w--;
			g[v][w]=g[w][v]=1;
		}
		string ret=doit(zips);
		outfile << "Case #" << (i+1) << ": " << ret << endl; 
	}
	cout<<"DONE"<<endl;
	string zzz;
	cin>>zzz;
	outfile.close();
	return 0;
}