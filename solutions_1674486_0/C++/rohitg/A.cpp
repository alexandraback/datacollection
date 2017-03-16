#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
vector< vector<int> > graph;
int mark[1009];

bool markset(int n) {
	if(mark[n] == 1)
		return true;
	mark[n] = 1;
	int i;
	for(i=0; i<graph[n].size(); ++i) {
		if(markset(graph[n][i])) {
			return true;
		}
	}
	return false;

}

bool check(int s) {
	memset(mark, 0, sizeof(mark));
	int i;
	for(i=0; i<graph[s].size(); ++i) {
		if(markset(graph[s][i])) {
			return true;
		}
	}
	return false;

}

int main() {
	int t;
	scanf("%d",&t);
	int tp = 0;
	int n;
	int m;
	int j, mi;
	int i;
	while(t--) {
		graph.clear();
		tp++;
		scanf("%d", &n);
		for(i=0; i<n; ++i) {
			scanf("%d", &m);
			vector<int> dep;
			for(j=0; j<m; ++j) {
				scanf("%d", &mi);
				dep.push_back(mi-1);
			}
			graph.push_back(dep);
		}
		printf("Case #%d: ", tp);
		//n2 check
		int done = 0;
		for(i=0; i<n; ++i) {
					if(check(i)) {
						printf("Yes\n");
						done = 1;
						break;
					}
			}
		if(done == 0) {
		printf("No\n");
		}

	}
	return 0;
}
