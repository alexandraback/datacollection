#include <iostream>

using namespace std;

int board[110][110];

int main () {
	int t;
	cin >> t;
	for (int caso = 1; caso <= t; caso++) {
		cout << "Case #" << caso << ": ";
		int n,m;
		cin >> n >> m;

		for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
		bool stop = false;
		for (int i = 0; i < n && !stop; i++)
		for (int j = 0; j < m && !stop; j++) {
			bool can = true;
			// vert
			for (int z = 1; z < n && can; z++) {
				int ni = i+z;
				if (ni < n && board[ni][j] > board[i][j]) can = false;
				ni = i-z;
				if (ni >= 0 && board[ni][j] > board[i][j]) can = false;
			}
			if (can) continue;
			can = true;
			// horiz
			for (int z = 1; z < m && can; z++) {
				int nj = j+z;
				if (nj < m && board[i][nj] > board[i][j]) can = false;
				nj = j-z;
				if (nj >= 0 && board[i][nj] > board[i][j]) can = false;
			}
			if (can) continue;
			cout << "NO" << endl;
			stop = true;
		}
		if (!stop) cout << "YES" << endl;
	}
	return 0;
}
