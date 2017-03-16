#include <cstdio>
#include <vector>
#include <set>

using namespace std;

int T;
set<int> sources;
vector<int> edges[1005];
int visited[1005];

bool go(int a) {
	if(visited[a]) return false;
	visited[a] = true;
	for(vector<int>::iterator it = edges[a].begin(); it != edges[a].end(); it++) {
		if(!go(*it)) return false;
	}
	return true;
}

int main(void) {
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		int N;
		scanf("%d", &N);
		sources.clear();
		for(int i = 1; i <= N; i++) {
			sources.insert(i);
			edges[i].clear();
		}
		for(int i = 1; i <= N; i++) {
			int M;
			scanf("%d", &M);
			while(M --> 0) {
				int temp;
				scanf("%d", &temp);
				sources.erase(temp);
				edges[i].push_back(temp);
			}
		}
		bool good = true;
		for(set<int>::iterator it = sources.begin(); it != sources.end(); it++) {
			memset(visited, 0, sizeof(int) * (N + 1));
			if(!go(*it)) {
				good = false;
				break;
			}
		}
		printf("Case #%d: %s\n", t, good ? "No" : "Yes");
	}
	return 0;
}
