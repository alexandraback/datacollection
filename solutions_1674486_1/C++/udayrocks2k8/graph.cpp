#include<cstdio>
#include<vector>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<bool> vb;
vii edges;
vi outdegree;
vb visited;
bool dfs(int index) {
	if(visited[index]) return true;
	visited[index] = true;
	for(int i = 0; i < edges[index].size(); i++) {
		if(dfs(edges[index][i])) return true;
	}
	return false;
}
bool check() {
	for(int i = 0; i < edges.size(); i++) {
		if(outdegree[i] == 0) {
			visited = vb(edges.size(), false);
			if(dfs(i)) {
				return true;
			}
		}
	}
	return false;
}
int main() {
	int tc;
	scanf("%d", &tc);
	for(int t  = 1; t <= tc; t++) {
		int n;
		scanf("%d", &n);
		edges = vii(n);
		outdegree = vi(n);
		for(int i = 0; i < n; i++) {
			int m;
			scanf("%d", &m);
			outdegree[i] = m;
			for(int j = 0; j < m; j++) {
				int num;
				scanf("%d", &num);
				num--;
				edges[num].push_back(i);
			}
		}
		printf("Case #%d: ", t);
		if(check()) {
			printf("Yes\n");
		} else {
			printf("No\n");
		}
	}
	return 0;
}
