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

int mxSz=0;
set<string> words[11][26][26];
int mem[25][25];
int seen[25][25];
set<string> oneLetters;

int eval(string s, int idx, int lastChangeIdx);

int checkDiff(string s, int idx, string t, int lastChangeIdx) {
	int n=t.size();
	int ret=-1;
	if(t.size()==1) {
		if(oneLetters.count(t)) {
			return eval(s,idx+1,lastChangeIdx);
		}
		else {
			if(lastChangeIdx!=-1&&idx-lastChangeIdx<5) return -1;
			int val=eval(s,idx+1,idx);
			if(val==-1) return val;
			val=val+1;
			return val;
		}
	}
	for(char first='a';first<='z';first++) {
	for(char second='a';second<='z';second++) {
		if(lastChangeIdx!=-1&&first!=t[0]&&second!=t[1]) continue;
		if(lastChangeIdx!=-1&&first!=t[0]&&idx-lastChangeIdx<5) continue;
		if(lastChangeIdx!=-1&&second!=t[1]&&idx+1-lastChangeIdx<4) continue;
		for(set<string>::iterator it=words[n][first-'a'][second-'a'].begin();it!=words[n][first-'a'][second-'a'].end();++it) {
			string word=*it;
			int differences=0;
			bool ok=true;
			int lastChangeIdx2=lastChangeIdx;
			for(int i=0;i<n;i++) {
				if(word[i]==t[i]) continue;
				differences++;
				if(lastChangeIdx2>=0&&idx+i-lastChangeIdx2<5) {
					ok=false;
					break;
				}
				lastChangeIdx2=idx+i;
			}
			if(ok) {
				int val=eval(s,idx+n,lastChangeIdx2);
				if(val==-1) continue;
				val+=differences;
				if(ret==-1||ret>val) {
					ret=val;
				}
			}
		}
	}}
	return ret;
}

int eval(string s, int idx, int lastChangeIdx) {
	if(idx==s.size()) return 0;
	//cout<<mem[idx][lastChangeIdx+1]<<endl;
	if(seen[idx][lastChangeIdx+1]) return mem[idx][lastChangeIdx+1];
	seen[idx][lastChangeIdx+1]=1;
	int ret=-1;
	for(int sz=1;sz<=mxSz;sz++) {
		if(idx+sz>s.size()) break;
		string t=s.substr(idx,sz);
		//cout<<t<<endl;
		int val=checkDiff(s,idx,t,lastChangeIdx);
		if(val==-1) continue;
		if(ret==-1||ret>val) {
			ret=val;
			continue;
		}
	}
	return mem[idx][lastChangeIdx+1]=ret;
}

int doit(string s) {
	cout<<mxSz<<endl;
	memset(seen,0,sizeof(seen));
	memset(mem,-1,sizeof(mem));
	return eval(s,0,-1);
}

int main()
{
	ifstream infile;
	string prefix = "C-small-attempt2";
	//string prefix = "test";
	infile.open(prefix + ".in");
	ofstream outfile(prefix + ".out");
	ifstream dictionary;
	dictionary.open("dictionary.txt");
	if(dictionary.is_open()) {
		while (!dictionary.eof()) {
			string word;
			dictionary>>word;
			if(word.size()==1) {
				oneLetters.insert(word);
			}
			else if(word.size()>1) {
				int n=word.size();
				words[n][word[0]-'a'][word[1]-'a'].insert(word);
				if(word.size()>mxSz) mxSz=word.size();
			}
		}
	}
	int cases;
	if (infile.is_open()) {
		infile>>cases;
	}
	else {
		return 0;
	}
	for(int i=0;i<cases;i++) {
		string s;
		infile>>s;
		outfile << "Case #" << (i+1) << ": " << doit(s) << endl; 
	}
	cout<<"DONE"<<endl;
	string zzz;
	cin>>zzz;
	outfile.close();
	return 0;
}