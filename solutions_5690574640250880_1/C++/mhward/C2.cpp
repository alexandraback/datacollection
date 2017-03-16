#include <iostream>
#include <cmath>

using namespace std;


int ans[50][50];

int r, c, m;

bool valid(int i, int j) {
	if (i < 0 || i > r-1)
		return false;
	if (j < 0 || j > c-1)
		return false;
	return true;
}


void dfs(int i, int j) {
	//cout << i << " " << j << endl;
	if (ans[i][j] == -2)
		return;
	int n = 0;
	for (int a = -1; a < 2; ++a)
		for (int b = -1; b < 2; ++b)
			if (valid(i+a, j+b) && ans[i+a][j+b] == -2)
				++n;
	ans[i][j] = n;
	if (n == 0) {
		for (int a = -1; a < 2; ++a) {
			for (int b = -1; b < 2; ++b) {
				if (valid(i+a, j+b) && ans[i+a][j+b] == -1 && (a != 0 || b != 0) ) {
					dfs(i+a, j+b);
				}
			}
		}
	}
}

bool allDone() {
	for (int i = 0; i < r; ++i)
		for (int j = 0; j < c; ++j) 
			if (ans[i][j] == -1)
				return false;
	return true;
}

bool isSolution(int rows, int cols) {
	int mines = 0;
	int cspace = c - cols;
	int lastMR, lastMC;
	for (int i = r-1; i > -1; --i) {
		for (int j = c-1; j > -1; --j) {
			
			int mleft = m - mines;
			
			if ((i < rows && j < cols) || mines == m)
				ans[i][j] = -1;
			else {
				lastMR = i;
				lastMC = j;
				// cout << i << " " << j << " " << mleft << " " << c-j-1 << endl;
				ans[i][j] = -2;
				++mines;
			}
		}
	}

	// cout << mines << " m = " << m << endl;

	if (mines != m)
		return false;

	dfs(0, 0);

	bool done = allDone();

	if (!done && lastMR > 0 && c > 1) {
		for (int i = 0; i < r; ++i)
			for (int j = 0; j < c; ++j)
				ans[i][j] = (ans[i][j] == -2) ? -2 : -1;
		ans[lastMR][lastMC] = -1;
		ans[lastMR-1][c-1] = -2;

		dfs(0, 0);

		return allDone();

	}
	else return done;
}

int main() {
	int kases;
	cin >> kases;

	for (int kase = 0; kase < kases; ++kase) {
		cin >> r >> c >> m;
		int f = r*c - m;
		cout << "Case #" << kase+1 << ":" << endl;

		
		bool done = false;
		for (int i = 1; i <= r; ++i) {
			if (done)
				break;
			for (int j = 1; j <= c; ++j) {
				
				if (i*j > f)
					continue;

				if (isSolution(i,j)) {
					ans[0][0] = 99;
					for (int i = 0; i < r; ++i) {
						for (int j = 0; j < c; ++j) {
							if(ans[i][j] == -2)
								cout << '*';
							else if(ans[i][j] == 99)
								cout << 'c';
							else
								cout << '.';
						}
						cout << endl;
					}
					done = true;
					break;


				}
				// else {
				// 	for (int i = 0; i < r; ++i) {
				// 		for (int j = 0; j < c; ++j) {
				// 			if(ans[i][j] == -2)
				// 				cout << '*';
				// 			else if(ans[i][j] == 99)
				// 				cout << 'c';
				// 			else
				// 				cout << '.';
				// 		}
				// 		cout << endl;
				// 	}
				// }
				// cout << "-------" << endl;
			}
		}

		if (!done)
			cout << "Impossible" << endl;

	}

	return 0;
}