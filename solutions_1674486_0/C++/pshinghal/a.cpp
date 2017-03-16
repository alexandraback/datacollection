#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>

using namespace std;

typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<bool> vb;

#define For(i,a,b) for(i=a;i<b;i++)

vi topoSort;
vi AdjList[1000 + 10];
int dfs_num[1000 + 10];
bool found;
const bool DFS_BLACK = 1;
const bool DFS_WHITE = 0;

void dfs2(int u){
	dfs_num[u] = DFS_BLACK;
	for(int J = 0; J < (int)AdjList[u].size(); J++){
		int v = AdjList[u][J];
		if(dfs_num[v] == DFS_WHITE)
			dfs2(v);
	}
	topoSort.push_back(u);
}

void explore(int vert, int root){
	dfs_num[vert] = root;
	for(int I = 0; I < (int) AdjList[vert].size() && !found; I++){
		if(dfs_num[AdjList[vert][I]] == root)
			found = true;
		else
			explore(AdjList[vert][I], root);
	}
}

int main ()
{
	int T, I, J, N, M, K, curr;
	cin>>T;
	for(I = 0; I < T; I++){
		topoSort.clear();
		cin>>N;
		for(J = 1; J <= N; J++){
			cin>>M;
			AdjList[J].clear();
			for(K = 0; K < M; K++){
				cin>>curr;
				AdjList[J].push_back(curr);
			}
		}
		memset(dfs_num, DFS_WHITE, sizeof dfs_num);
		for(J = 1; J <= N; J++){
			if(dfs_num[J] == DFS_WHITE)
				dfs2(J);
		}
		reverse(topoSort.begin(), topoSort.end());
		memset(dfs_num, DFS_WHITE, sizeof dfs_num);
		found = false;
		for(J = 1; J <= N && !found; J++){
			if(dfs_num[J] == DFS_WHITE)
				explore(J, J);
		}
		cout<<"Case #"<<I+1<<": ";
		if(found)
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}
