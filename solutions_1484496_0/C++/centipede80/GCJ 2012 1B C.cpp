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

const int MX=4000001;
int mem[MX];
int mem2[MX];
int p[MX];

void doit(int testcase, ifstream &infile, ofstream &outfile) {
	int n;
	infile >> n;
	vector<int> v;
	cout<<"*"<<endl;
	for(int i=0;i<n;i++) {
		int j;
		infile>>j;
		v.push_back(j);
		cout<<j<<endl;
	}
	memset(mem,0,sizeof(mem));
	memset(mem2,0,sizeof(mem2));
	memset(p,0,sizeof(mem));
	mem[MX/2]=1;
	mem2[MX/2]=1;
	for(int i=0;i<n;i++) {
		for(int j=0;j<MX;j++) if(mem[j]) {
			if(j+v[i]<MX&&!p[j+v[i]]) {
				mem2[j+v[i]]=1;
				p[j+v[i]]=-v[i];
				if(i<5) cout<<j<<" "<<-v[i]<<endl;
			}
			if(j-v[i]>=0&&!p[j-v[i]]) {
				mem2[j-v[i]]=1;
				p[j-v[i]]=v[i];
				if(i<5) cout<<j<<" "<<v[i]<<endl;
			}
		}
		for(int j=0;j<MX;j++) mem[j]=mem2[j];
	}
	if(p[MX/2]==0) {
		outfile << "Case #" << testcase << ": " << "Impossible" << endl; 
	}
	else {
		outfile << "Case #" << testcase << ":" << endl; 
		vector<int> v1, v2;
		int val=MX/2;
		int idx3=0;
		do {
			if(p[val]<0) {
				v1.push_back(-p[val]);
			} else {
				v2.push_back(p[val]);
			}
			cout<<val<<endl;
			val=val+p[val];
			idx3++;
			if(idx3>25) break;
		} while(val!=MX/2);
		for(int i=0;i<v1.size();i++) {
			if(i) outfile << " ";
			outfile << v1[i];
		}
		outfile << endl;
		for(int i=0;i<v2.size();i++) {
			if(i) outfile << " ";
			outfile << v2[i];
		}
		outfile << endl;
	}
}

int main()
{
	ifstream infile;
	infile.open("C-small-attempt0.in");
	ofstream outfile("C-small-attempt0.out");
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