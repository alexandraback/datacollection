#include <cmath>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

fstream in, out;

int t, n, m;

int grid[100][100];
int max_row[100];
int max_col[100];


int main() {
	in.open("B-large.in", fstream::in);
	out.open("probb.out", fstream::out);

	in >> t;
	int max = 0;
    for (int i = 0; i < t; i++) {
		max = 0;
		in >> n >> m;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				in >> grid[j][k];
				if (grid[j][k] > max) {
					max = grid[j][k];
				}
			}
		}

		for (int j = 0; j < n; j++) {
			max_row[j] = 0;
		}
		for (int k = 0; k < m; k++) {
			max_col[k] = 0;
		}

		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (grid[j][k] > max_row[j]) {
					max_row[j] = grid[j][k];
				}
				if (grid[j][k] > max_col[k]) {
					max_col[k] = grid[j][k];
				}
			}
		}
		
		string ans = "YES";
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (grid[j][k] < max_row[j] && grid[j][k] < max_col[k]) {
					ans = "NO";
				}
			}
		}

		out << "Case #" << i + 1 << ": " << ans << endl;
	}
    
	in.close();
	out.close();

	return 0;
}
