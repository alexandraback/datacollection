#include <iostream>
#include <vector>

using namespace std;

bool connected[1000][1000];

bool dfs(vector<vector<int> > adjlist, 
		 int start, 
		 vector<bool>& visited) {
	if (visited[start] == true)
		return true;
	visited[start] = true;
	bool out = false;
	for (int i = 0; i < adjlist[start].size(); ++i) {
		if (visited[adjlist[start][i]])
			return true;
		else {
			out = out || dfs(adjlist, adjlist[start][i], visited);
		}
	}
	return out;
}
int main() {
	int cases;
	cin >> cases;
	for (int c = 0; c < cases; ++c) {
		int N;
		cin >> N;
		vector<int> degree(N,0);
		vector<int> tmp;
		vector<vector<int> > adjlist(N, tmp);
		for (int i =0;i <N; ++i) {		
			cin >> degree[i];
			for (int d = 0; d < degree[i]; ++d) {
				int neigh;
				cin >> neigh;
				adjlist[i].push_back(neigh -1);
			}
		}
		bool found = false;
		// run dfs for each node;
		for (int i = 0; i < N; ++i) {
			vector<bool> visited(N, false);
			if (dfs(adjlist, i, visited)) {
				found = true;
				break;
			}
		}
		if (found) 
			cout << "Case #" << c +1 << ": Yes" << endl;
		else
			cout << "Case #" << c +1 << ": No" << endl;
	}
}