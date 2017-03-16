#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int> > origAdjList[64], adjList[64];
string codes[64];
int codesInInt[64];


bool vis[64];
void formTree(int cur, int parent) {
	if (vis[cur])
		return;
	vis[cur] = 1;
	if (parent != -1)
		adjList[parent].push_back(make_pair(codesInInt[cur], cur));
	for (unsigned int i = 0; i < origAdjList[cur].size(); ++i)
		formTree(origAdjList[cur][i].second, cur);
}

string dfs(int x) {
	string ret = codes[x];
	for (unsigned int i = 0; i < adjList[x].size(); ++i) {
		ret += dfs(adjList[x][i].second);
	}
	return ret;
}

int main() {
	freopen("C-small-attempt0.in", "rt", stdin);
	freopen("C-small-attempt0.out", "wt", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int T; cin >> T;
	for (int t = 0; t < T; ++t) {
		int M;
		cin >> N >> M;

		for (int i = 0; i < N; ++i)
			origAdjList[i].clear();

		for (int i = 0; i < N; ++i)
			cin >> codes[i], codesInInt[i] = atoi(codes[i].c_str());

		for (int i = 0; i < M; ++i) {
			int x, y; cin >> x >> y, --x, --y;
			origAdjList[x].push_back(make_pair(codesInInt[y], y));
			origAdjList[y].push_back(make_pair(codesInInt[x], x));
		}

		int mn = 1e9, mnI = -1;
		for (int i = 0; i < N; ++i)
			if (codesInInt[i] < mn)
				mn = codesInInt[i], mnI = i;

		for (int j = 0; j < N; ++j)
			adjList[j].clear();
		memset(vis, 0, sizeof(vis));
		formTree(mnI, -1);

		for (int i = 0; i < N; ++i)
			sort(adjList[i].begin(), adjList[i].end());

		cout << "Case #" << t + 1 << ": " << dfs(mnI) << "\n";
	}

	return 0;
}
