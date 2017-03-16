#include <iostream>
#include <vector>

using namespace std;

int main()
{
	freopen("B-small-attempt0.in", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int t;
	cin >> t;
	for (int x = 0; x < t; x++) {
		long long n, m;
		cin >> n >> m;
		cout << "Case #" << x + 1 << ": ";
		long long maxm = pow(2, n - 2);
		if (m > maxm) {
			cout << "IMPOSSIBLE" << endl;
			continue;
		}
		else {
			cout << "POSSIBLE" << endl;
		}
		vector<vector<int> > mat(n, vector<int>(n));
		for (int i = 0; i < n - 1; i++) {
			for (int j = i + 1; j < n - 1; j++) {
				if (i != j) mat[i][j] = 1;
			}
		}
		vector<int> twoes;
		for (int p = n - 3; p >= 1; p--) {
			if (m >= pow(2, p)) {
				twoes.push_back(p);
				m -= pow(2, p);
			}
		}
		for (int i = 0; i < twoes.size(); i++) {
			mat[twoes[i] + 1][n - 1] = 1;
		}
		if (m == 2) {
			mat[0][n - 1] = 1;
			mat[1][n - 1] = 1;
		}
		else if (m == 1) {
			mat[0][n - 1] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << mat[i][j];
			}
			cout << endl;
		}
	}
    return 0;
}

