#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <list>
#include <map>
#include <set>

using namespace std;

bool find_diamond(int source, const vector<vector<int> > &adj_list, vector<int> &visited)
{
	visited[source] = 1;
	for(vector<int>::const_iterator itr = adj_list[source].begin(); itr != adj_list[source].end(); ++itr) {
		if(visited[*itr] == 1) {
				return true;
		} else {
			if(find_diamond(*itr, adj_list, visited)) {
				return true;
			}
		}
	}
	return false;
}

void solve_case(void)
{
	int N;
	cin >> N;
	vector<vector<int> > adj_list(N);
	for (int i = 0; i < N; i++) {
		int num_inherits_from;
		cin >> num_inherits_from;
		for (int j = 0; j < num_inherits_from; j++) {
			int parent;
			cin >> parent;
			adj_list[i].push_back(parent - 1);
		}
	}
	for (int i = 0; i < N; ++i) {
		vector<int> visited(N, 0);
		if (find_diamond(i, adj_list, visited)) {
			cout << "Yes";
			return;
		}
	}
	cout << "No";
}

int main()
{
	int T;
	string input;
	getline(cin, input);
	stringstream ss(input);
	ss >> T;
	for (int i = 0; i < T; i++) {
		cout << "Case #" << i + 1 << ": ";
		solve_case();
		cout << endl;
	}
	return 0;
}
