#include <bits/stdc++.h>

#define debug(x) cout << #x << " = " << x << endl
#define fori(i, ini, lim) for(int i = int(ini); i < int(lim); i++)
#define ford(i, ini, lim) for(int i = int(ini); i >= int(lim); i--)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;

const int MAX = 1e3 + 5;
int n;
int bff[MAX];
int sz[MAX];
vector<int> adj[MAX], rvr[MAX];
bool visited[MAX];

void dfs(int source, vector<int> graph[MAX], vector<int> &cont) {
	visited[source] = true;
	for(auto &each : graph[source]) {
		if(!visited[each]) {
			dfs(each, graph, cont);
		}
	}
	cont.push_back(source);
}

int ANS;
void kosaraju() {
	vector<int> order;
	memset(visited, false, sizeof visited);
	fori(i, 1, n + 1) {
		if(!visited[i]) {
			dfs(i, adj, order);
		}
	}

	memset(visited, false, sizeof visited);
	while(!order.empty()) {
		int back = order.back();
		order.pop_back();

		if(!visited[back]) {
			vector<int> comp;
			dfs(back, rvr, comp);
			for(auto &each : comp) {
				sz[each] = comp.size();
			}
			ANS = max(ANS, (int) comp.size());
		}
	}
}

int best[MAX];
int in_degree[MAX];

void roll(int s, int dis) {
	if(sz[s] == 2) {
		best[s] = max(best[s], dis);
		return;
	}
	else if(sz[s] > 2) {
		return;
	}
	for(auto &each : adj[s]) {
		roll(each, dis + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);

	int kase = 1;
	int t;
	cin >> t;
	while(t--) {
		memset(sz, 0, sizeof sz);
		memset(in_degree, 0, sizeof in_degree);
		memset(best, 0, sizeof best);
		cin >> n;

		fori(i, 1, n + 1) {
			adj[i].clear();
			rvr[i].clear();
		}
		fori(i, 1, n + 1) {
			cin >> bff[i];
			adj[i].push_back(bff[i]);
			rvr[bff[i]].push_back(i);
			in_degree[bff[i]]++;
		}
		
		ANS = 0;
		kosaraju();

		fori(i, 1, n + 1) {
			if(!in_degree[i]) {
				roll(i, 0);
			}
		}

		int total_2 = 0;
		memset(visited, false, sizeof visited);
		fori(i, 1, n + 1) {
			if(sz[i] == 2 && !visited[i]) { 
				visited[i] = true;
				visited[bff[i]] = true;
				total_2 += best[i] + best[bff[i]] + 2;
			}
		}

		cout << "Case #" << kase++ << ": ";
		cout << max(total_2, ANS) << '\n';
	}
	return 0;
}
