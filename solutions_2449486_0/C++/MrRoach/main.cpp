#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

int t;
int n, m;
int map[100][100];

int main() {
	cin >> t;
	for (int caseNum = 0; caseNum < t; ++caseNum) {
		cin >> n >> m;
		for (int i = 0 ; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> map[i][j];
			}
		}
		bool shear = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				bool vertMax = true;
				bool horiMax = true;
				for (int k = 0; k < m; ++k) {
					if (map[i][k] > map[i][j]) {
						vertMax = false;
						break;
					}
				}
				for (int k =0 ; k < n; ++k) {
					if (map[k][j] > map[i][j]) {
						horiMax = false;
						break;
					}
				}
				if (!vertMax && !horiMax) {
					shear = false;
					break;
				}
			}
			if (!shear) break;
		}
		cout << "Case #" << caseNum + 1 << ": " 
			 << (shear ? "YES" : "NO") << endl;
	}
	return 0;
}