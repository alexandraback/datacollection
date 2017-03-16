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

//long long doit2(vector<long long> &v, vector<long long> &w, int type1, long long count1, int idx1, int type2, long long count2, int idx2) {
long long doit2(vector<long long> &v, vector<long long> &w, int idx1, long long used1, int idx2, long long used2) {
	if(idx1==v.size()||idx2==w.size()) return 0;
	long long ret=0;
	long long have1=v[idx1]-used1;
	long long have2=w[idx2]-used2;
	if(v[idx1+1]==w[idx2+1]) {
		long long add=min(have1,have2);
		cout<<v[idx1]<<" "<<used1<<" "<<w[idx2]<<" "<<used2<<" "<<idx1<<" "<<idx2<<endl;
		ret+=add;
		if(have1<have2) {
			return ret+doit2(v,w,idx1+2,0,idx2,used2+add);
		}
		else if(have1>have2) {
			return ret+doit2(v,w,idx1,used1+add,idx2+2,0);
		}
		else {
			return ret+doit2(v,w,idx1+2,0,idx2+2,0);
		}
	}
	else {
		ret=max(ret,doit2(v,w,idx1+2,0,idx2,used2));
		ret=max(ret,doit2(v,w,idx1,used1,idx2+2,0));
	}
	return ret;
}

void doit(int testcase, ifstream &infile, ofstream &outfile) {
	int N;
	infile>>N;
	int M;
	infile>>M;
	vector<long long> v;
	for(int i=0;i<N+N;i++) {
		long long x;
		infile>>x;
		v.push_back(x);
		cout<<x<<" ";
	}
	cout<<endl;
	vector<long long> w;
	for(int i=0;i<M+M;i++) {
		long long x;
		infile>>x;
		w.push_back(x);
		cout<<x<<" ";
	}
	cout<<endl;
	outfile << "Case #" << testcase << ": " << doit2(v,w,0,0,0,0) << endl; 
}

int main()
{
	ifstream infile;
	infile.open("in.txt");
	ofstream outfile("out.txt");
	//infile.open("C-small-attempt0.in");
	//ofstream outfile("C-small-attempt0.out");
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