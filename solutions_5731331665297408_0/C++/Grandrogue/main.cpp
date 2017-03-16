#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

ifstream fin("C-small-attempt0.in");
ofstream fout("out.txt");

string zip[50];
vector<vector<int>> a;
vector<string> ans;
int n,m;

void check(vector<int> p) {
	string s="";
	bool used[50];
	int pos=0;
	memset(used,0,sizeof(used));
	for(int i=1;i<n;i++) {
		bool flag=false;
		while(!flag && pos>=0) {
			if(!used[pos])
			for(int j=0;j<a[p[i]].size();j++) {
				if(a[p[i]][j]==p[pos]) flag=true;
			}
			if(!flag) used[pos]=1,pos--;
		}
		if(pos==-1) return;
		pos=i;
	}
	for(int i=0;i<n;i++)
		s+=zip[p[i]];
	ans.push_back(s);
}

bool operator<(string a,string b) {
	for(int i=0;i<a.length();i++) {
		if(a[i]<b[i]) return true;
		if(a[i]>b[i]) return false;
	}
	return false;
}

int main() {
	int tests;
	fin>>tests;
	for(int _t=0;_t<tests;_t++) {
		string res="";
		fin>>n>>m;
		a.clear();
		a.resize(n);
		ans.clear();
		for(int i=0;i<n;i++)
			fin>>zip[i];
		for(int i=0;i<m;i++) {
			int x,y;
			fin>>x>>y;
			x--;
			y--;
			a[x].push_back(y);
			a[y].push_back(x);
		}
		vector<int> perm;
		for(int i=0;i<n;i++)
			perm.push_back(i);
		do {
			check(perm);
		} while(next_permutation(perm.begin(),perm.end()));
		res=ans[0];
		for(int i=0;i<ans.size();i++)
			if(ans[i]<res) res=ans[i];
		fout<<"Case #"<<_t+1<<": "<<res<<endl;
	}
	return 0;
}