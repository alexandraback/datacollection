#include <fstream>
#include <stdlib.h>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <iostream>
using namespace std;
int t, n, s[500];
map<int, set<int> > visited;
pair<int, set<int> > solution;
set<int>::reverse_iterator rit;
set<int>::iterator it;
bool DFS(pair<int, set<int> > loc){
	if(!visited[loc.first].empty()){
		solution = loc;
		return true;
	}
	visited[loc.first] = loc.second;
	rit = loc.second.rbegin();
	if(rit==loc.second.rend()){
		for(int i = 0;i<n;i++){
			loc.second.insert(i);
			loc.first += s[i];
			if(DFS(loc)) return true;
			loc.second.erase(i);
			loc.first -= s[i];
		}
	}else{
		for(int i = *rit+1;i<n;i++){
			loc.second.insert(i);
			loc.first += s[i];
			if(DFS(loc)) return true;
			loc.second.erase(i);
			loc.first -= s[i];
		}
	}
	return false;
}
int main(){
	ifstream fin("input.in");
	ofstream fout("output.txt");
	pair<map<int, set<int> >, int> current;
	fin >> t;
	for(int i = 1;i<=t;i++){
		fout << "Case #" << i << ":\n";
		fin >> n;
		for(int x = 0;x<n;x++){
			fin >> s[x];
		}
		set<int> lolempty;
		if(DFS(make_pair(0,lolempty))){
			set<int> derp;
			derp = solution.second;
			for(it = derp.begin();it!=derp.end();it++){
				fout << s[*it] << ' ';
			}
			fout << '\n';
			derp = visited[solution.first];
			for(it = derp.begin();it!=derp.end();it++){
				fout << s[*it] << ' ';
			}
			fout << '\n';
		}else fout << "Impossible\n";
		visited.clear();
		/*queue<pair<map<int, set<int> >, int> > BFSqueue;
		BFSqueue.insert(make_pair(0,-1));
		while(!BFSqueue.empty()){
			current = BFSqueue.front();
			BFSqueue.pop();
			for(int x = current->second;x<n;x++){
				current +=
			}
		}*/
	}
	return 0;
}
