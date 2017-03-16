#include<iostream>
#include<assert.h>
#include<fstream>
#include<vector>
#include<map>
#include<set>
#include<deque>
#include<queue>
#include<functional>
#include<algorithm>
#include<unordered_map>
#include<unordered_set>
#include<cstdlib>
#include<cstring>
#include<cmath>
using namespace std;

int T, N, M;

vector<int> cities;
vector<vector<int>> edges;
bool visited[100];
map<int, int> can_return;
int par[100];
vector<int> sol;

void solve1(int x, vector<int> & best_sol) {
	if(sol.size() == N) {
		if(sol < best_sol)
			best_sol = sol;
		return;
	}
	bool cango[51];
	for(int i = 0; i < N; ++i)
		cango[i] = 0;
	for(int i = 0; i < edges[x].size(); ++i)
		cango[edges[x][i]] = 1;
	for(int i = 0; i < N; ++i)
		if(visited[i])cango[i] = 0;
	if(par[x] != -1) {
		int nd = par[x];
		par[x] = -1;
		solve1(nd, best_sol);
		par[x] = nd;
	}
	for(int i = 0; i < N; ++i) {
		if(cango[i]) {
			visited[i] = 1;
			sol.push_back(cities[i]);
			par[i] = x;
			solve1(i, best_sol);
			par[i] = -1;
			sol.pop_back();
			visited[i] = 0;
		}
	}
}
int INF = 1000000000;
int main() {
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cin >> N >> M;
		cities.clear(); edges.clear();

		for(int i = 0; i < N; ++i) {
			int zip; cin >> zip; cities.push_back(zip);
		}
		edges.reserve(N);
		edges.clear();
		for(int i = 0; i < M; ++i) {
			int a, b; cin >> a >> b; a--; b--;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}
		cout << "Case #" << t << ": ";
		vector<int> best_sol;
		best_sol.push_back(INF);
		for(int i = 0; i < N; ++i) {
			sol.clear();
			memset(visited, 0, N);
			memset(par, -1, sizeof(int) * N);
			visited[i] = 1;
			can_return.clear();
			sol.push_back(cities[i]);
			solve1(i, best_sol);
		}
		assert(best_sol[0] != INF);
		assert(best_sol.size() == N);
		for(int i = 0; i < N; ++i)
			cout << best_sol[i];
		cout << endl;
	}
	return 0;
}
