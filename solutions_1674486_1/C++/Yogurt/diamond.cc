#include <vector>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

bool is_diamond(const vector< vector<int> > & graph) {
	int N = graph.size();
	for (int i = 0; i < N; ++i) {
		vector<bool> visited(N, false);
		vector<int> nodes;
		nodes.push_back(i);
		while (!nodes.empty()) {
			int curr = nodes.back();
			nodes.pop_back();
			if (visited[curr])
				return true;
			visited[curr] = true;
			copy(graph[curr].begin(), graph[curr].end(), back_inserter(nodes));
		}
	}
	return false;

}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i) {
		int N;
		cin >> N;
		vector< vector<int> > graph;
		while (N--) {
			int M;
			cin >> M;
			vector<int> parents;
			while (M--) {
				int parent;
				cin >> parent;
				parents.push_back(parent - 1);
			}
			graph.push_back(parents);
		}

		cout << "Case #" << i << ": ";
		if (is_diamond(graph))
			cout << "Yes";
		else
			cout << "No";
		cout << endl;
	}
}
