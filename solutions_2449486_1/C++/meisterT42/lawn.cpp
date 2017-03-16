#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
	int tc;
	cin >> tc;
	for (int c = 0; c < tc; c++) {
		cout << "Case #" << (c + 1) << ": ";
		int rows, cols;
		cin >> rows >> cols;
		vector<vector<int> > orig;
		vector<vector<int> > wanted;
		for (int i = 0; i < rows; i++) {
			vector<int> tmp;
			for (int j = 0; j < cols; j++) {
				int t;
				cin >> t;
				tmp.push_back(t);
			}
			wanted.push_back(tmp);
			vector<int> tmp2(cols,100);
			orig.push_back(tmp2);
		}
		for (int i = 0; i < rows; i++) {
			int maxi = wanted[i][0];
			for (int j = 1; j < cols; j++) {
				maxi = max(maxi, wanted[i][j]);
			}
			for (int j = 0; j < cols; j++) {
				orig[i][j] = min(maxi, orig[i][j]);
			}
		}
		for (int i = 0; i < cols; i++) {
			int maxi = wanted[0][i];
			for (int j = 1; j < rows; j++) {
				maxi = max(maxi, wanted[j][i]);
			}
			for (int j = 0; j < rows; j++) {
				orig[j][i] = min(maxi, orig[j][i]);
			}
		}
		bool same = true;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				if (orig[i][j] != wanted[i][j]) same = false;
			}
		}
		if (same) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}

