#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
using namespace std;

vector<vector<int>> b(200, vector<int> (200));

int main() {
	int T; cin >> T;
	for (int tt = 1; tt <= T; ++tt) {
		int N; cin >> N;	
		int cv = 2 * N - 1;
		vector<vector<int>> a(cv);
		for (int i = 0; i < cv; ++i) {
			a[i].resize(N);
			for (int j = 0; j < N; ++j) {
				cin >> a[i][j];
			}
		}
		sort(a.begin(), a.end());
		b[0] = a[0];		
		a.erase(a.begin());
		cv--;
		cout << "Case #" << tt << ":";

		int pos = -1;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < cv; ++j) {
				if (b[0][i] == a[j][0]) {
					for (int k = 0; k < N; ++k) {
						b[k][i] = a[j][k];
					}
					a.erase(a.begin() + j, a.begin() + j + 1);
					cv--;
					j = 0;
				}
				else pos = i;
			}
		}
		if (pos == -1) {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < cv; ++j) {
					if (b[i][0] != a[j][0]) {
						pos = i;
					}
					break;
				}
			}
			for (int i = 0; i < N; ++i) {
				cout << " " << b[i][pos];
			}
		}
		else {
			for (int i = 0; i < N; ++i) {
				cout << " " << b[pos][i];
			}
		}
		cout << endl;


	}
	return 0;
}