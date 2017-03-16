#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory.h>
#include <algorithm>
#include <vector>
#include <cassert>

#define DB(x) cerr << #x << ": " << x << endl;

using namespace std;

const char* inputFile = "C-small-attempt0.in";
const char* outputFile = "C-small-attempt0.out";

// const char* inputFile = "file.in";
// const char* outputFile = "file.out";

class Solver {
public:
	Solver() {
	}

	string solveTest() {
		cin >> N >> M;
		colors.resize(N, 0);
		int startVertex = 0;
		for(size_t i = 0; i < N; ++i) {
			string s;
			cin >> s;
			codes.push_back(s);
			if (codes[i] < codes[startVertex]) {
				startVertex = i;
			}
		}

		edges.resize(N);
		for (size_t i = 0; i < M; ++i) {
			int a, b;
			cin >> a >> b;
			a--;
			b--;
			edges[a].push_back(b);
			edges[b].push_back(a);
		}

		string result = codes[startVertex];
		extendPath(startVertex);
		for(int i = 0; i < N - 1; ++i) {
			int nextStep = -1;
			int jStep = -1;
			vector<char> reachableNow(N, false);
			for(int j = 0; j < path.size(); ++j) {
				reachableNow = reachableSetsUnion(reachable(path[j]), reachableNow);
				if (allReachable(reachableNow)) {
					auto oneStep = oneStepReachable(path[j]);
					for (auto v : oneStep) {
						if ((nextStep == -1) || (codes[v] < codes[nextStep])) {
							nextStep = v;
							jStep = j;
						}
					}
				}
			}
			
			if (nextStep == -1) {
				cerr << "That's bad, " << i << endl;
				assert(false);
			}

			while (path.size() > jStep + 1) {
				path.pop_back();
			}
			extendPath(nextStep);
			result += codes[nextStep];
		}

		return result;
	}

	bool allReachable(const vector<char> &v) {
		for(size_t i = 0; i < v.size(); ++i) {
			if (v[i] || colors[i]) {
				continue;
			}
			return false;
		}
		return true;
	}

	vector<char> reachableSetsUnion(vector<char> v1, vector<char> v2) {
		vector<char> result(v1.size(), 0);
		for (size_t i = 0; i < result.size(); ++i) {
			result[i] = v1[i] || v2[i];
		}
		return result;
	}

	void dfs(int v, vector<char> &visited) {
		visited[v] = true;
		for(int i = 0; i < edges[v].size(); ++i) {
			int u = edges[v][i];
			if ((colors[u] == 0) && (!visited[u])) {
				dfs(u, visited);
			}
		}
	}

	vector<char> reachable(int v) {
		vector<char> visited(N, false);
		dfs(v, visited);
		return visited;
	}

	vector<int> oneStepReachable(int v) {
		vector<int> result;
		for(int i = 0; i < edges[v].size(); ++i) {
			int u = edges[v][i];
			if (colors[u] == 0) {
				result.push_back(u);
			}
		}
		return result;
	}

	void extendPath(int v) {
		path.push_back(v);
		colors[v] = 1;
	}

	vector<int> colors;
	vector<int> path;
	vector<string> codes;
	vector<vector<int>> edges;
	int N, M;
};

int main() {
	freopen(inputFile, "r", stdin);
	freopen(outputFile, "w", stdout);
	int T;
	scanf("%d", &T);

	for (int testNumber = 1; testNumber <= T; ++testNumber) {
		Solver solver;
		string verdict = solver.solveTest();
		printf("Case #%d: %s\n", testNumber, verdict.c_str());
	}
	return 0;
}
