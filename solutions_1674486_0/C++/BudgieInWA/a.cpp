#include<iostream>
#include<stack>
#include<vector>

using namespace std;

int main() {
	int cases; cin >> cases;

	for (int cheese = 1; cheese <= cases; cheese++) {
		cout << "Case #" << cheese << ": ";

		int N; cin >> N;
		vector<vector<int> > edges(N, vector<int>());
		
		for (int i = 0; i < N; i++) {
			int M; cin >> M;
			for (int j = 0; j < M; j++) {
				int a; cin >> a;
				edges[i].push_back(a-1);
			}
		}

		bool done = false;
		for (int i = 0; i < N && !done; i++) {
			vector<bool> v(N, false);
			stack<int> s;
			s.push(i);
			v[i] = true;
			while( ! s.empty()) {
				int n = s.top();
				s.pop();
				for (int j = 0; j < edges[n].size(); j++) {
					if (v[edges[n][j]]) { done = true; break; }
					v[edges[n][j]] = true;
					s.push(edges[n][j]);
				}
			}
		}
		
		cout << (done ? "Yes" : "No" ) ;

		cout << endl;
	}
}
