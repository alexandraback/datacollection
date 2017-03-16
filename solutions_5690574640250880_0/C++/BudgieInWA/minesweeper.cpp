#include<iostream>
#include<cstring>

using namespace std;

int main() {
	int kases;
	cin >> kases;
	for (int kase = 1; kase <= kases; kase++) {
		int r, c, m;
		cin >> r >> c >> m;
		int origm = m;
		m = r*c - m;
		char g[r][c];
		memset(g, '*', sizeof(char) * r * c);
		g[0][0] = 'c';
		bool possible = true;
		if (m == 1) {
			//done
		} else if (r == 1) {
			// fill only row
			for (int i = 1; i < m; i++) {
				g[0][i] = '.';
			}
		} else if (c == 1) {
			// fill only column
			for (int i = 1; i < m; i++) {
				g[i][0] = '.';
			}
		} else if (m == 2) {
			possible = false;
		} else if (r == 2 || c == 2) {
			// 2 rows or columns, only even numbers of mines works
			if (m % 2 == 0) {
				// fill the two rows or columns
				if (r == 2) {
					g[1][0] = '.';
					for (int i = 1; i < m/2; i++) {
						g[0][i] = '.';
						g[1][i] = '.';
					}
				} else {
					g[0][1] = '.';
					for (int i = 1; i < m/2; i++) {
						g[i][0] = '.';
						g[i][1] = '.';
					}
    			}
			} else {
				possible = false;
			}
		} else if(m == 3 || m == 5 || m == 7) {
			possible = false;
		} else {
			// fill the corner
			g[0][1] = '.';
			g[1][0] = '.';
			g[1][1] = '.';
			m -= 4;
			//cerr << m << endl;
			// now fill in pairs along one edge
			int pairs = 1; // index or last pair
			for (int i = 2; i < c && m >= 2; i++) {
				//cerr  << "pairs " << i << " " << m << endl;
				g[0][i] = '.';
				g[1][i] = '.';
				m -= 2;
				pairs = i;
			}
			// fill the rest, one by one in rows, making sure the last row has at least 2 cells
			for (int i = 2; i < r && m > 0; i++) {
				for (int j = 0; j < c && m > 0; j++) {
					//cerr << "rest " << i << " " << r <<" " << m << endl;
					g[i][j] = '.';
					m--;
					if (m == 0 && j == 0) {
						// steal a cell from the previous row, so there's not a single lonely cell
						if (i == 2) {
							//we only have 2 full rows, so we need to steal 2 cells
							g[i][1] = '.';
							g[i][2] = '.';
							g[0][pairs] = '*';
							g[1][pairs] = '*';
						} else {
							//simply steal the last cell from the last row (which was filled by
							//singles)
							g[i][1] = '.';
							g[i-1][c-1] = '*';
						}
					}
				}
			}
		}

		cout << "Case #" << kase << ": " << endl;
		//cerr << r << " " << c << " " << origm << endl;
		if (!possible) {
			cout << "Impossible" << endl;
		} else {
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					cout << g[i][j];
				}
				cout << endl;
			}
		}
	}
	return 0;
}
