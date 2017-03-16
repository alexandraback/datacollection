#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

vector<int> bff[1010];
vector<int> bfr[1010];
int b[1010];

bool visited[1010];

int dfsf(int first, int node) {
	if (visited[node]) {
		if (node == first) {
			return 0;
		} else {
			return -1;
		}
	}
	visited[node] = true;
	
	int big = -1;
	for (int i = 0; i < (int) bff[node].size(); i++) {
		int now = dfsf(first, bff[node][i]);
		if (now != -1 && now > big) {
			big = now;
		}
	}
	
	visited[node] = false;
	if (big == -1) return big;
	
	return big + 1;
}

int dfsr(int node, int cant) {
	if (node == cant) {
		return -1;
	}
	
	if (visited[node]) {
		return 0;
	}
	
	visited[node] = true;
	
	int big = 0;
	for (int i = 0; i < (int) bfr[node].size(); i++) {
		int now = dfsr(bfr[node][i], cant);
		if (now != -1 && now > big) {
			big = now;
		}
	}
	
	visited[node] = false;
	if (big == -1) return big;
	
	return big + 1;
}

int N;
int main() {
	int T, el;
	
	scanf("%d", &T);
	
	for (int test = 1; test <= T; test++) {
		printf("Case #%d: ", test);
		
		scanf("%d", &N);
		
		memset(b, 0, sizeof(b));
		memset(visited, 0, sizeof(visited));
		for (int i = 1; i <= N; i++) {
			bff[i].clear();
			bfr[i].clear();
		}
		
		for (int i = 1; i <= N; i++) {
			scanf("%d", &el);
			bff[i].push_back(el);
			bfr[el].push_back(i);
			b[i] = el;
		}
		
		int best = 0;
		
		for (int i = 1; i <= N; i++) {
			int now = dfsf(i, i);
			if (now > best) {
				best = now;
			}
		}
		
		int duple = 0;
		for (int i = 1; i <= N; i++) {
			if (b[b[i]] == i) {
				duple += dfsr(i, b[i]) + dfsr(b[i], i) 	;
				if (duple > best) {
					best = duple;
				}
				visited[i] = visited[b[i]] = true;
			}
		}
		
		printf("%d\n", best);
	}
	return 0;
}