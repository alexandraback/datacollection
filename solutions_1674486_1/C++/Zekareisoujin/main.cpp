#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

#define NMAX 1010

vector<int> adjList[NMAX];
int n;
bool visited[NMAX];
bool found;

void dfs(int v){
	visited[v] = true;
	for (int i=0; i<adjList[v].size(); i++){
		int next = adjList[v][i];
		if (visited[next]){
			found = true;
			return;
		}else
			dfs(next);
	}
}

int main(){
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int tc;
	cin >> tc;
	for (int tci=0; tci<tc; tci++){
		cin >> n;
		for (int i=0; i<n; i++)
			adjList[i].clear();
		int m, o;
		for (int i=0; i<n; i++){
			cin >> m;
			for (int j=0; j<m; j++){
				cin >> o; o--;
				adjList[i].push_back(o);
			}
		}

		found = false;
		for (int i=0; i<n; i++){
			memset(visited, false, sizeof visited);
			dfs(i);
			if (found)
				break;
		}

		printf("Case #%d: ", tci+1);
		if (found)
			printf("Yes\n");
		else
			printf("No\n");

	}
}