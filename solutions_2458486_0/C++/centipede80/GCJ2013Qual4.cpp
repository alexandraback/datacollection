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

int mem[1<<20];
int seen[1<<20];

int possible(vector<int> startKeys, int N, vector<int> &neededKeys, vector<vector<int> > &haveKeys, int mask) {
	if(mask==0) return true;
	if(seen[mask]) { return mem[mask]; }
	seen[mask]=1;
	int keys[55];
	memset(keys, 0, sizeof(keys));
	for(int i=0;i<startKeys.size();i++) keys[startKeys[i]]++;
	for(int i=0;i<N;i++) if(((1<<i)&mask)==0) {
		keys[neededKeys[i]]--;
		for(int j=0;j<haveKeys[i].size();j++) {
			keys[haveKeys[i][j]]++;
		}
	}
	//cout<<mask;
	//for(int i=0;i<4;i++) cout<<" "<<keys[i];
	//cout<<endl;
	for(int i=0;i<55;i++) if(keys[i]<0) return false;
	for(int i=0;i<N;i++) if(((1<<i)&mask)!=0) {
		if(keys[neededKeys[i]]>0) {
			if(possible(startKeys,N,neededKeys,haveKeys,mask^(1<<i))) {
				return mem[mask]=1;
			}
		}
	}
	return mem[mask]=0;
}

string doit(vector<int> startKeys, int N, vector<int> &neededKeys, vector<vector<int> > &haveKeys) {
	cout<<"Start keys" <<endl;
	for(int i=0;i<startKeys.size();i++) cout<<startKeys[i]<<" ";
	cout<<endl;
	cout<<"Needed keys" << endl;
	for(int i=0;i<neededKeys.size();i++) cout<<neededKeys[i]<<" ";
	cout<<endl;
	cout<<"Have keys" << endl;
	for(int i=0;i<haveKeys.size();i++) {
		for(int j=0;j<haveKeys[i].size();j++) {
			cout<<haveKeys[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"<<START>>"<<endl;
	memset(mem,0,sizeof(mem));
	memset(seen,0,sizeof(seen));
	if(!possible(startKeys,N,neededKeys,haveKeys,(1<<N)-1)) return "IMPOSSIBLE";
	int mask=(1<<N)-1;
	string ret="";
	while(mask>0) {
		bool found=false;
		for(int i=0;i<N;i++) {
			if(((1<<i)&mask)!=0) {
				int keys[55];
				memset(keys, 0, sizeof(keys));
				for(int j=0;j<startKeys.size();j++) keys[startKeys[j]]++;
				for(int j=0;j<N;j++) if(((1<<j)&mask)==0) {
					keys[neededKeys[j]]--;
					for(int k=0;k<haveKeys[j].size();k++) {
						keys[haveKeys[j][k]]++;
					}
				}
				if(keys[neededKeys[i]]>0&&possible(startKeys,N,neededKeys,haveKeys,mask^(1<<i))) {
					mask^=(1<<i);
					if(ret.size()) ret=ret+" ";
					stringstream ss;
					ss<<(i+1);
					ret=ret+ss.str();
					found=true;
					break;
				}
			}
		}
		if(!found) { cout<<"BAD!!!"<<endl; break; }
	}
	cout<<ret<<endl;
	return ret;
}

int main()
{
	ifstream infile;
	string prefix = "D-small-attempt4";
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
		int K,N;
		infile>>K>>N;
		vector<vector<int> > haveKeys;
		vector<int> neededKeys;
		vector<int> startKeys;
		for(int j=0;j<K;j++) {
			int key;
			infile>>key;
			startKeys.push_back(key);
		}
		for(int j=0;j<N;j++) {
			int openKey,numKeys;
			infile>>openKey>>numKeys;
			vector<int> keys;
			for(int k=0;k<numKeys;k++) {
				int key;
				infile>>key;
				keys.push_back(key);
			}
			neededKeys.push_back(openKey);
			haveKeys.push_back(keys);
		}
		outfile << "Case #" << (i+1) << ": " << doit(startKeys, N, neededKeys, haveKeys) << endl; 
	}
	cout<<"DONE"<<endl;
	string zzz;
	cin>>zzz;
	outfile.close();
	return 0;
}