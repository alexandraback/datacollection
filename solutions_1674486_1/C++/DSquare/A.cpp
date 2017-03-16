#include<iostream>
#include<vector>
#include<queue>

using namespace std;


int main() {

	int T;
	cin >> T;
	int caso = 1;
	while (caso <= T) {
		int N;
		cin >> N;
		vector<vector<int> > path(N+1, vector<int> (0));
		
		for (int e = 1; e < N + 1; ++e) {
			int inh;
			cin >> inh;
			for (int h = 0; h < inh; ++h) {
				int p;
				cin >> p;
				path[e].push_back(p);
			}
		}
		bool trobat = false;
		for (int i = 1; i < N + 1; ++i) {
			vector<bool> b(N+1, false);
			queue<int> q;
			q.push(i);
			while (not trobat and not q.empty()) {
				int pos = q.front();
				q.pop();
				if (b[pos] == true)	trobat = true;
				b[pos] = true;
				for (int j = 0; j < path[pos].size(); ++j) {
					q.push(path[pos][j]);
				}
			}
			
			if (trobat) break;
			
		}
		
		cout << "Case #" << caso << ": ";
		if (trobat) cout << "Yes";
		else cout << "No";
		cout << endl;
		caso++;
	}
}