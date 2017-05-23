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

bool isCons(char c) {
	if(c=='a') return false;
	if(c=='e') return false;
	if(c=='i') return false;
	if(c=='o') return false;
	if(c=='u') return false;
	return true;
}

int mem[1000001];

long long doit(string s, int k) {
	//cout<<"<<<<<<<"<<endl;
	//cout<<s<<" "<<k<<endl;
	memset(mem,-1,sizeof(mem));
	bool state=false;
	int ct=0;
	int n=s.size();
	long long ret=0;
	for(int i=0;i<s.size();i++) {
		bool state2=isCons(s[i]);
		if(state2==state) ct++;
		else ct=1;
		state=state2;
		//cout<<state<<" "<<ct<<endl;
		if(state2 && ct>=k) {
			for(int j=i-k+1;j>=0;j--) {
				if(mem[j]!=-1) break;
				mem[j]=i;
			}
		}
	}
	for(int i=0;i<s.size();i++) {
		//cout<<mem[i]<<endl;
		if(mem[i]==-1) continue;
		ret+=(n-mem[i]);
	}
	return ret;
}

int main()
{
	ifstream infile;
	string prefix = "A-small-attempt0";
	//string prefix = "test";
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
		string s;
		int n;
		infile >> s >> n;
		outfile << "Case #" << (i+1) << ": " << doit(s,n) << endl; 
	}
	cout<<"DONE"<<endl;
	string zzz;
	cin>>zzz;
	outfile.close();
	return 0;
}