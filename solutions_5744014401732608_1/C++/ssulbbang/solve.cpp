#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main(int argc, char** argv) {
	int t;
	cin >> t;
	for(int iter = 0; iter < t; iter++) {
		int n;
		long long m;
		cin >> n >> m;
		vector< vector<int> > g;
		g.resize(n);
		for(int i = 0; i < n; i++) {
			g[i].resize(n);
		}
		for(int i = 0; i < n - 1; i++) {
			for(int j = i + 1; j < n - 1; j++) {
				g[i][j] = 1;
			}
		}
		g[0][n - 1] = 1;
		m--;
		int node = 1;
		bool impossible = false;
		while(m > 0) {
			if(node == n - 1) {
				impossible = true;
				break;
			}
			if((m % 2) == 1) {
				g[node][n - 1] = 1;
			}
			m /= 2L;
			node++;
		}
		cout << "Case #" << iter + 1 << ": ";
		if(impossible) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			cout << "POSSIBLE" << endl;
			for(int i = 0; i < n; i++) {
				for(int j = 0; j < n; j++) {
					cout << g[i][j];
				}
				cout << endl;
			}
		}
	}
	return 0;
}
