#include <iostream>
#include <algorithm>

using namespace std;

typedef struct {
	int up;
	int left;
	int down;
	int right;
}M;

int main () {
	int cases;

	cin >> cases;

	for (int c=1; c<=cases; c++) {
		cout << "Case #" << c << ": ";
		int n, m;
		cin >> n >> m;
		int data[110][110];
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++)
				cin >> data[i][j];
		}

		bool valid = true;

		M dp[110][110];
		for (int i=0; i<n; i++) {
			dp[i][0].left = data[i][0];
			for (int j=1; j<m; j++) {
				dp[i][j].left = max (dp[i][j-1].left, data[i][j]);
			}

			dp[i][m-1].right = data[i][m-1];
			for (int j=m-2; j>=0; j--) {
				dp[i][j].right = max (dp[i][j+1].right, data[i][j]);
			}
		}

		for (int j=0; j<m; j++) {
			dp[0][j].up = data[0][j];
			for (int i=1; i<n; i++) {
				dp[i][j].up = max (dp[i-1][j].up, data[i][j]);
			}

			dp[n-1][j].down = data[n-1][j];
			for (int i=n-2; i>=0; i--) {
				dp[i][j].down = max (dp[i+1][j].down, data[i][j]);
			}
		}

		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				bool local = false;
				if (data[i][j]>=dp[i][j].up && data[i][j]>=dp[i][j].down)
					local = true;
				if (data[i][j]>=dp[i][j].left && data[i][j]>=dp[i][j].right)
					local = true;
				if (!local) {
					valid = false;
					break;
				}
			}
		}
		if (valid)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
