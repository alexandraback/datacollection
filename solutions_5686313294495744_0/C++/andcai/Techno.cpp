#include <fstream>
#include <string>
#include <cstring>
#include <map>
#include <set>
#include <iostream>

using namespace std;

int first[1000], second[1000];
int fdictsize, sdictsize;
set<int> fset[1000];
set<int> sset[1000];
bool fval[1000];
bool sval[1000];
int N;
bool tval[1000];	// topic/edge values
int maxcovE;
bool fvis[1000];
bool svis[1000];

bool DFS(int g, int p){
	bool rval = false;
	if(g == -1){
		for(int x = 0; x < fdictsize; x++){
			if(fval[x])
				continue;
			set<int>::iterator it = fset[x].begin();
			for(; it != fset[x].end(); it++){
				if(tval[*it]) continue;
				if(!sval[second[*it]]){
					fval[x] = true;
					sval[second[*it]] = true;
					tval[*it] = true;
					rval = true;
					maxcovE++;
					break;
				}else{
					fvis[x] = true;
					if(DFS(1, second[*it])){
						fval[x] = true;
						tval[*it] = true;
						rval = true;
						fvis[x] = false;
						break;
					}
					fvis[x] = false;
				}
			}
		}
	}else if(g == 1){
		if(svis[p])
			return false;
		set<int>::iterator it = sset[p].begin();
		for(; it != sset[p].end(); it++){
			if(fvis[first[*it]] || !tval[*it])
				continue;
			svis[p] == true;
			if(DFS(0, first[*it])){
				tval[*it] = false;
				svis[p] = false;
				return true;
			}
			svis[p] = false;
		}
		return false;
	}else if(g == 0){
		set<int>::iterator it = fset[p].begin();
		for(; it != fset[p].end(); it++){
			if(tval[*it]) continue;
			if(!sval[second[*it]]){
				sval[second[*it]] = true;
				tval[*it] = true;
				rval = true;
				maxcovE++;
				break;
			}else{
				fvis[p] = true;
				if(DFS(1, second[*it])){
					tval[*it] = true;
					rval = true;
					fvis[p] = false;
					break;
				}
				fvis[p] = false;
			}
		}
	}
	return rval;
}

int main(){
	ifstream fin ("C-small-attempt0.in");
	ofstream fout ("C-output.txt");
	int T;
	fin >> T;
	for(int i = 1; i <= T; i++){
		fin >> N;
		memset(fval, 0, 1000);
		memset(sval, 0, 1000);
		memset(tval, 0, 1000);
		maxcovE = 0;
		fdictsize = 0;
		map<string, int> fdict;
		sdictsize = 0;
		map<string, int> sdict;
		map<string, int>::iterator it;
		string s;
		for(int x = 0; x < N; x++){
			fin >> s;
			if((it=fdict.find(s))==fdict.end()){
				fset[fdictsize].clear();
				fdict.insert(make_pair<string, int>(s, fdictsize));
				first[x] = fdictsize++;
			}else{
				first[x] = it->second;
			}
			fin >> s;
			fset[first[x]].insert(x);
			if((it=sdict.find(s))==sdict.end()){
				sset[sdictsize].clear();
				sdict.insert(make_pair<string, int>(s, sdictsize));
				second[x] = sdictsize++;
			}else{
				second[x] = it->second;
			}
			sset[first[x]].insert(x);
		}
		bool cont = true;
		while(DFS(-1, 0));
		//cout << i << " maxcovE " << maxcovE << " fdsize " << fdictsize << " sdsize " << sdictsize << '\n';
		fout << "Case #" << i << ": " << N + maxcovE - fdictsize - sdictsize << '\n';
	}
	return 0;
}
