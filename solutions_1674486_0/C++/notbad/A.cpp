#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <functional>

using namespace std;

bool bfsed[1024] ;
vector< vector<int> > graph;

bool bfs(int vv)
{
	queue<int> qq;
	qq.push(vv);
	bool flag[1024] = {0};
	//flag[vv] = true;
	bfsed[vv] = true;
	while (!qq.empty()){
		int v = qq.front();
		qq.pop();
		if (flag[v]){
			return true;
		}
		flag[v] = true;
		for (int i = 0 ;i < graph[v].size() ;++i){
			qq.push(graph[v][i]);
			bfsed[graph[v][i]] = true;
		}
	}
	return false;
}


int main()
{
	freopen("A-small-attempt0.in" ,"r" ,stdin);
	freopen("test.out" ,"w" ,stdout);
	int T;
	cin >> T;
	for (int t = 1 ;t <= T ;++t){
		int N;
		cin >> N ;
		graph.clear();
		graph.resize(N+1);
		for (int i = 1 ;i <= N ;++i){
			int m;
			cin >> m;
			for (int j = 0 ;j < m ;j++){
				int v;
				cin >> v;
				graph[i].push_back(v);
			}
		}
		bool yes = false;
		memset(bfsed ,0 ,sizeof(bfsed));
		for (int i = 1 ;i <= N ;i++){
			if (!bfsed[i]){
				if (bfs(i)){
					yes = true;
					break;
				}
			}
		}
		cout << "Case #" << t << ": ";
		if (yes){
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}
	return 0;
}
