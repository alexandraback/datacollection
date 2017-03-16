#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	int t;
	cin >> t;

	for (int q = 0; q < t; q++) {
		int n, m;
		cin >> n >> m;

		vector< vector<int> > data(n);
		for (int i = 0; i < n; i++) {
			data[i].resize(m);
			for (int j = 0; j < m; j++)
				cin >> data[i][j];
		}

		vector<int> row_max(n), col_max(m);
		for (int i = 0; i < n; i++) {
			row_max[i] = -1;
			for (int j = 0; j < m; j++)
				row_max[i] = max(row_max[i], data[i][j]);
		}
		for (int i = 0; i < m; i++) {
			col_max[i] = -1;
			for (int j = 0; j < n; j++)
				col_max[i] = max(col_max[i], data[j][i]);
		}

		bool res = true;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (min(row_max[i], col_max[j]) != data[i][j])
					res = false;
		cout << "Case #" << q + 1 << ": ";
		if (res)
			cout << "YES";
		else
			cout << "NO";
		cout << endl;
	}
}