#include <iostream>
#include <fstream>
#include <map>
#include <vector>
using namespace std;

int grow(map<int,int> &md, map<int,vector<int>> &mi, int f1, int f2) {
	int r = 1;
	for(auto &x:mi[f1]) {
		if (x!=f2) {
			int r2 = 1+grow(md,mi,x,f1);
			if (r2>r) r=r2;
		}
	}
	return r;
}

int get_ans(map<int,int> &md, map<int,vector<int>> &mi){
	int rn = 0, rr = 0;
	for(auto &p:md) {
		if (md[md[p.first]]==p.first) {
			rr += grow(md,mi,p.first,md[p.first]);
		} else {
			int cur = p.first, r = 1, n=md.size();
			while (md[cur]!=p.first && r<=n) {
				cur=md[cur]; ++r;
			}
			if (md[cur]==p.first && r>rn) rn=r;
		}
	}
	return rr>rn ? rr:rn;
}

int main(int argc, char *argv[]) {
//	string fname = "C-sample";
	string fname = "C-small-attempt1";
//	string fname = "C-large";
	ifstream fin(fname+".in");
	ofstream fout(fname+".out");
	int T;
	fin>>T;
	for(int I=0;I<T;I++) {
		map<int,vector<int>> mi;
		map<int,int> md;
		int x,n;
		fin>>n;
		for(int i=0;i<n;i++) {
			fin >> x;
			md[i+1] = x;
			mi[x].push_back(i+1);
		}
		fout<<"Case #"<<I+1<<": "<<get_ans(md,mi)<<endl;
	}
	fin.close();
	fout.close();
	return 0;
}

