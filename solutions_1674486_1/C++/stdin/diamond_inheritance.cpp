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

			vector<bool> tbv(N, true);
			set<int> tbv2;
			
			tbv2.insert(val);
			while (!tbv2.empty()) {
				val = *tbv2.begin();
				tbv2.erase(val);
				if (tbv[val])
					ok = false;
				tbv[val] = false;

				for (int i=0; i<M[val]; i++) {
					if (tbv2.find(parents[val][i]) != tbv2.end()) {
						ok = false;
						goto policzone;
					}
					tbv2.insert(parents[val][i]);
				}
			}
		}
		policzone:

		cout << (ok ? "No" : "Yes") << endl;
	}
}
