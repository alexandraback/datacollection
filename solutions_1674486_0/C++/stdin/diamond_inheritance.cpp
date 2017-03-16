#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int case_nr, T;

	cin >> T;

	for (case_nr=1; case_nr<=T; case_nr++) {
		cout << "Case #" << case_nr << ": ";

		int N;
		cin >> N;

		vector<int> M(N);
		vector< vector<int> > parents(N);
		for (int i=0; i<N; i++) {
			cin >> M[i];

			parents[i].resize(M[i]);

			for (int j=0; j<M[i]; j++) {
				int tmp;
				cin >> tmp;
				tmp--;
				parents[i][j] = tmp;
			}
		}

		bool ok = true;
		
		for (int x=0; x<N; x++) {
			int val = x;

			set<int> tbv;
			for (int i=0; i<N; i++)
				tbv.insert(i);
			queue<int> tbv2;
			
			tbv2.push(val);
			while (!tbv2.empty()) {
				val = tbv2.front();
				tbv2.pop();
				if (tbv.find(val) == tbv.end())
					ok = false;
				tbv.erase(val);

				for (int i=0; i<M[val]; i++) {
					tbv2.push(parents[val][i]);
				}
			}
		}

		cout << (ok ? "No" : "Yes") << endl;
	}
}
