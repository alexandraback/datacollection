#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <string.h>
#include <stdio.h>
#include <vector>
#include <utility>
#include <cmath>
#include <queue>

using namespace std;

vector <vector<int> > adj;
vector<bool> seen;
/*
bool dfs(int v){
	seen[v] = true;
	for (int i = 0 ; i < adj[v].size() ; i++){
		//cout << adj[v][i] << endl;
		if (!seen[adj[v][i]]) return dfs(adj[v][i]);
		else {
			cout << "WTF" << endl;
			return true;
		}
	}
	cout << v << endl;
	return false;
}
*/
bool bfs(int s){
	seen[s] = true;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for (int i = 0 ; i < adj[v].size() ; i++){
			int u = adj[v][i];
			if (!seen[u]){
				q.push(u);
				seen[u] = true;
			}
			else return true;
		}
	}
	return false;
}

int main(){
	int T, N, M;

	cin >> T;
	for (int i = 0 ; i < T ; i++){
		cin >> N;
		adj.clear();
		seen.clear();
		bool b = false;
		for (int j =0 ; j < N ; j++){
			cin >> M; 
			vector <int> vi;
			for (int k = 0 ; k < M ; k++){
				int x;
				cin >> x;
				vi.push_back(x-1);
			}
			adj.push_back(vi);
		}
		//cout << "hi" << endl;
		for (int j = 0 ; j < N ; j++){
			if (adj[j].size() == 0) continue;
			seen.clear();
			for (int k = 0 ; k < N ; k++) seen.push_back(false);
			b = bfs(j);
			if (b) break;
			//cout << "hey" << endl;
		}

		printf("Case #%d: ", i+1);
		if (b) cout << "Yes";
		else cout << "No";
		cout << endl;
	}

	return 0;
}
