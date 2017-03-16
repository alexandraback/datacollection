#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

#define fi "C-small-attempt0.in"
#define fo "out.txt"
const int MAXN = 50 + 5;
const int INF = 1000000000;

int T, N, M;
int zip[MAXN];
int visited[MAXN], visitID;

string dfs(int, vector<int> []);
string toString(int);

int main() {
	freopen(fi, "r", stdin);
	freopen(fo, "w", stdout);

	cin >> T;
	visitID = 0;
	memset(visited, 0, sizeof visited);
	for (int t = 1; t <= T; ++t) {
		cout << "Case #" << t << ": ";
		visitID = t;
		vector<int> graph[MAXN];
		cin >> N >> M;
		for (int i = 0; i < N; ++i) {
			cin >> zip[i];
//			cout << toString(zip[i]) << endl;
		}
		for (int i = 0; i < M; ++i) {
			int u, v;
			cin >> u >> v;
			--u;
			--v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		int startIndex = 0;
		for (int i = 1; i < N; ++i) {
			if (zip[i] < zip[startIndex]) {
				startIndex = i;
			}
		}
//		cout << startIndex << endl;
		cout << dfs(startIndex, graph) << endl;
	}
}

string dfs(int u, vector<int> graph[]) {
//	cout << u << endl;
	string ret = toString(zip[u]);
//	cout << ret << endl;
	visited[u] = visitID;
	vector<pair<int, int> > nodes;
	for (int i = 0; i < graph[u].size(); ++i) {
		int v = graph[u][i];
		if (visited[v] != visitID) {
			nodes.push_back(make_pair(zip[v], v));
		}
	}
	sort(nodes.begin(), nodes.end());
	for (int i = 0; i < nodes.size(); ++i) {
		if (visited[nodes[i].second] != visitID) {
			ret += dfs(nodes[i].second, graph);
		}
	}
	return ret;
}

string toString(int x) {
	string ret = "";
	while (x != 0) {
		ret = char('0' + x % 10) + ret;
		x /= 10;
	}
	return ret;
}
