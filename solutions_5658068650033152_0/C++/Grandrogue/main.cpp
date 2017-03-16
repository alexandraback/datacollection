#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

ifstream fin("C-small-attempt0.in");
ofstream fout("out.txt");

string s[110];
vector<int> adj[110];


int main() {
	int tests;
	fin >> tests;
	for(int _t = 0; _t < tests; _t++) {
		int n,m,k;
		fin>>n>>m>>k;
		if(m<n) swap(n,m);
		if(n<3) fout << "Case #" << _t+1 << ": " << k << endl; else
		if(n==3 && m==3 && k>=5) fout << "Case #" << _t+1 << ": " << k-1 << endl; else
		if(n==3 && m==3 && k<5) fout << "Case #" << _t+1 << ": " << k << endl; else
		if(n==3 && m==4 && k>=5 && k<8) fout << "Case #" << _t+1 << ": " << k-1 << endl; else
		if(n==3 && m==4 && k>=8) fout << "Case #" << _t+1 << ": " << k-2 << endl; else
		if(n==3 && m==4 && k<5) fout << "Case #" << _t+1 << ": " << k << endl; else
		if(n==3 && m==5 && k>=5 && k<8) fout << "Case #" << _t+1 << ": " << k-1 << endl; else
		if(n==3 && m==5 && k>=8 && k<11) fout << "Case #" << _t+1 << ": " << k-2 << endl; else
		if(n==3 && m==5 && k>=11) fout << "Case #" << _t+1 << ": " << k-3 << endl; else
		if(n==3 && m==5 && k<5) fout << "Case #" << _t+1 << ": " << k << endl; else
		if(n==3 && m==6 && k>=5 && k<8) fout << "Case #" << _t+1 << ": " << k-1 << endl; else
		if(n==3 && m==6 && k>=8 && k<11) fout << "Case #" << _t+1 << ": " << k-2 << endl; else
		if(n==3 && m==6 && k>=11 && k<14) fout << "Case #" << _t+1 << ": " << k-2 << endl; else
		if(n==3 && m==6 && k>=14) fout << "Case #" << _t+1 << ": " << k-4 << endl; else
		if(n==3 && m==6 && k<5) fout << "Case #" << _t+1 << ": " << k << endl; else
		if(n==4 && m==4 && k<5) fout << "Case #" << _t+1 << ": " << k << endl; else
		if(n==4 && m==4 && k>=5 && k<8) fout << "Case #" << _t+1 << ": " << k-1 << endl; else
		if(n==4 && m==4 && k>=8 && k<11) fout << "Case #" << _t+1 << ": " << k-2 << endl; else
		if(n==4 && m==4 && k>=11 && k<12) fout << "Case #" << _t+1 << ": " << k-3 << endl; else
		if(n==4 && m==4 && k>=12) fout << "Case #" << _t+1 << ": " << k-4 << endl; else
		if(n==4 && m==5 && k<5) fout << "Case #" << _t+1 << ": " << k << endl; else
		if(n==4 && m==5 && k>=5 && k<8) fout << "Case #" << _t+1 << ": " << k-1 << endl; else
		if(n==4 && m==5 && k>=8 && k<11) fout << "Case #" << _t+1 << ": " << k-2 << endl; else
		if(n==4 && m==5 && k>=11 && k<12) fout << "Case #" << _t+1 << ": " << k-3 << endl; else
		if(n==4 && m==5 && k>=12 && k<14) fout << "Case #" << _t+1 << ": " << k-4 << endl; else
		if(n==4 && m==5 && k>=14 && k<=16) fout << "Case #" << _t+1 << ": " << 10 << endl; else
		if(n==4 && m==5 && k>16) fout << "Case #" << _t+1 << ": " << k-6 << endl;
	}
	/*int T; fin >> T;
	for (int tt = 1; tt <= T; tt++) {
		fout << "Case #" << tt << ": ";
		int N; fin >> N;
		for (int i = 0; i < N; i++) {
			fin >> s[i];
		}
		for (int i = 0; i < N; i++) {
			adj[i].clear();
			for (int j = 0; j < N; j++) {
				if (i == j) continue;
				if (s[i][s[i].length()-1] == s[j][0]) adj[i].push_back(j);
			}
		}

	}
	/*int tests;
	fin >> tests;
	for(int _t = 0; _t < tests; _t++) {
		int n;
		fin >> n;
		vector<int> per;
		
		int res=0;
		for(int i=0;i<n;i++) 
			per.push_back(i);
		for(int i=0;i<n;i++) {
			fin>>s[i];
			char cur=s[i][0];
			for(int j=1;j<s[i].length();j++) {
				if(s[i][j]==cur) s[i].erase(j,1),j--; else
					cur=s[i][j];
			}
		}
		do {
			string r="";
			for(int i=0;i<n;i++)
				r+=s[per[i]];
			set<char> a;
			char cur=r[0];
			for(int i=0;i<r.length();i++) {
				if(a.find(r[i])==a.end()) {
					cur=r[i];
					a.insert(r[i]);
					if(i==r.length()-1) res++;
				} else if(cur==r[i]){
					if(i==r.length()-1) res++;
				} else break;
			}
		} while(next_permutation(per.begin(),per.end()));
		fout << "Case #" << _t+1 << ": " << res << endl;
	}
	return 0;*/
}