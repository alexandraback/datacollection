#include <bits/stdc++.h>
using namespace std;
int TC, N;
double a[1005], b[1005];
int p[1005];
vector<int> adjList[1005];
bitset<1005> visited;
bool Aug(int x) {
	if (visited[x]) return 0;
	visited[x] = 1;
	for (vector<int>::iterator it = adjList[x].begin(); it != adjList[x].end(); ++it) {
		if (p[*it] == -1) {
			p[*it] = x;
			return 1;
		}
	}
	
	for (vector<int>::iterator it = adjList[x].begin(); it != adjList[x].end(); ++it) {
		if (Aug(p[*it])) {
			p[*it] = x;
			return 1;
		}
	}
	return 0;
}
int main () {
	freopen("deceitfulwar.in", "r", stdin);
	freopen("deceitfulwar.out", "w", stdout);
	
	
	scanf("%d", &TC);
	for (int T=1; T<=TC; ++T) {
		scanf("%d", &N);
		for (int i = 0; i < N; ++i) scanf("%lf", &a[i]);
		for (int i = 0; i < N; ++i) scanf("%lf", &b[i]);
		
		
		memset(p, -1, sizeof(p));
		for (int i = 0; i < N; ++i) {
			adjList[i].clear();
			for (int j = 0; j < N; ++j) {
				if (a[i] > b[j]) adjList[i].push_back(j);
			}
		}
		int X = 0;
		for (int i = 0; i < N; ++i) {
			visited.reset();
			X += Aug(i);
		}
		
		memset(p, -1, sizeof(p));
		for (int i = 0; i < N; ++i) {
			adjList[i].clear();
			for (int j = 0; j < N; ++j) {
				if (b[i] > a[j]) adjList[i].push_back(j);
			}
		}
		int Y = 0;
		for (int i = 0; i < N; ++i) {
			visited.reset();
			Y += Aug(i);
		}
		
		printf("Case #%d: %d %d\n", T, X, N-Y);

	}
}
