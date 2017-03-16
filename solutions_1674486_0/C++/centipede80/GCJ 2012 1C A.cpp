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

int mem[1005];
vector<vector<int> > graph;
bool dfs(int v, int idx) {
	if(mem[v]==idx) return true;
	mem[v]=idx;
	for(int i=0;i<graph[v].size();i++) {
		if(dfs(graph[v][i],idx)) return true;
	}
	return false;
}

void doit(int testcase, ifstream &infile, ofstream &outfile) {
	int N;
	infile>>N;
	graph.clear();
	for(int i=0;i<N;i++) {
		int M;
		infile>>M;
		vector<int> adj;
		for(int j=0;j<M;j++) {
			int v;
			infile>>v;
			adj.push_back(v-1);
		}
		graph.push_back(adj);
	}
	string ret="No";
	memset(mem,-1,sizeof(mem));
	for(int i=0;i<N;i++) {
		if(dfs(i,i)) {
			ret="Yes";
			cout<<testcase<<" "<<i<<endl;
		}
	}
	outfile << "Case #" << testcase << ": " << ret << endl; 
}

int main()
{
	ifstream infile;
	//infile.open("in.txt");
	//ofstream outfile("out.txt");
	infile.open("A-small-attempt0.in");
	ofstream outfile("A-small-attempt0.out");
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