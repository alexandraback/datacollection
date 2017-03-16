#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

bool traverse(const vector<vector<int> > &graph, vector<bool> &visited, int v) {
	//cout << "Visiting " << v << endl;
	visited[v] = true;
	for (size_t i = 0; i < graph[v].size(); ++i) {
		if (visited[graph[v][i]])
			return true;
		if (traverse(graph, visited, graph[v][i]))
			return true;
	}
	
	return false;
}

bool solve(const vector<vector<int> > &graph) {
	for (size_t i = 0; i < graph.size(); ++i) {
		vector<bool> visited(graph.size());
		if (traverse(graph, visited, i))
			return true;
	}
	return false;
}

int main() {
	size_t cases;
	cin >> cases;
	for (size_t c = 0; c < cases; ++c) {
		size_t n;
		cin >> n;
		vector<vector<int> > graph(n);
		for (size_t i = 0; i < n; ++i) {
			size_t m;
			cin >> m;
			for (size_t j = 0; j < m; ++j) {
				int v;
				cin >> v;
				graph[i].push_back(v - 1);
			}
		}
		
		bool diamond = solve(graph);
		cout << "Case #" << c + 1 << ": " << (diamond ? "Yes" : "No") << endl;
	}
	return 0;
}