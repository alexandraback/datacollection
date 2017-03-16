#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>

using namespace std;

int A[2000001];

int main() {
	int T;
	cin >> T;
	for (int t = 0; t < T; t++) {
		int N; cin >> N;
		memset(A,0,sizeof(A));
		vector<int> data;
		for (int i = 0; i < N; i++) {
			int val; cin >> val;
			data.push_back(val);
		}
		sort(data.begin(),data.end());
		vector<int> subsets;
		for (int i = 0; i < (1 << N); i++) {
			int sum = 0;
			for (int j = 0; j < N; j++) {
				if (i & (1 << j)) {
					sum += data[j];
				}
			}
			if (A[sum] != 0) {
				subsets.push_back(i);
				subsets.push_back(A[sum]);
				break;
			}
			A[sum] = i;
		}
		cout << "Case #" << (t+1) << ":\n";
		if (subsets.size() != 2) {
			cout << "Impossible\n";
		} else {
			for (int i = 0; i < subsets.size(); i++) {
				int mask = subsets[i];
				bool first = true;
				for (int j = 0; j < N; j++) {
					if (mask & (1 << j)) {
						if (!first) cout << " ";
						first = false;
						cout << data[j];
					}
				}
				cout << "\n";
			}
		}
	}
	return 0;
}