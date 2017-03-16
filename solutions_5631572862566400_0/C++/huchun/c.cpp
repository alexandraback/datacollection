#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <queue>
using namespace std;

int dfs(vector<bool>& visited, vector<int>& bff, vector<vector<int>>& rbff, int cur, int& res){
	visited[cur]=true;
	if (visited[bff[cur]]){
		if (bff[bff[cur]]==cur){
			queue<int> bfs;
			queue<int> level;
			bfs.push(cur);
			level.push(0);
			int maxlevel=0;
			while(!bfs.empty()){
				int tmp=bfs.front();
				maxlevel=level.front();
				bfs.pop();
				level.pop();
				for (int rb:rbff[tmp]){
					if (visited[rb]) continue;
					visited[rb]=true;
					bfs.push(rb);
					level.push(maxlevel+1);
				}
			}
			res=maxlevel+1;
			return cur;
		}
		else{
			res=1;
			return bff[cur];
		}
	}
	int tmp=dfs(visited,bff,rbff,bff[cur],res);
	if (tmp==-1) return tmp;
	else{
		res++;
		if (tmp==cur) return -1;
		else return tmp;
	}
}

int main(){
	ofstream myfile;
  	myfile.open ("outputc.txt");
  	int t;
	scanf("%d",&t);
	for (int i=1;i<=t;++i){
		int n;
		cin>>n;
		vector<int> bff;
		vector<vector<int>> rbff(n,vector<int>());
		for (int i=0;i<n;++i){
			int tmp;
			cin>>tmp;
			bff.push_back(tmp-1);
			rbff[tmp-1].push_back(i);
		}
		int maxres=0;
		vector<bool> visited(n,false);
		for (int i=0;i<n;++i){
			if (!visited[i]){
				int res;
				dfs(visited,bff,rbff,i,res);
				maxres=max(maxres,res);
			}
		}
		myfile<<"Case #"<<i<<": ";
		myfile<<maxres<<endl;
	}
  	myfile.close();
  	return 0;
}
