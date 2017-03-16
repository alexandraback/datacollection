#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
int R, C, M;
const int MAX_N = 50;
char cell[MAX_N][MAX_N];

void solve()
{
	scanf("%d %d %d", &R, &C, &M);
	memset(cell, '*', sizeof(cell));
	int cells = R * C;
	int empty = cells - M;
	bool possible = false;

	if (empty == 1) {
		possible = true;
		cell[0][0] = 'c';
	} else {
		int cur = min(C, 2) * min(R, 2);
		int right = 1;
		int bottom = 1;
		pii br = make_pair<int>(0, 0);
		int line = 0;
		if (cur < empty) {
			if (R < C) {
				if(right < C - 1) {
					++right;
					cur += min(R, 2);
				}
				if (cur < empty && bottom < R - 1) {
					++bottom;
					cur += min(C, 2);
				}
			} else {
				if (bottom < R - 1) {
					++bottom;
					cur += min(C, 2);
				}
				if (cur < empty && right < C - 1) {
					++right;
					cur += min(C, 2);
				}
			}

			if (cur < empty) {
				if (C < R) {
					while (cur <= empty - min(C, 2) && bottom < R - 1) {
						++bottom;
						cur += min(C, 2);
					}
					while (cur <= empty - min(R, 2) && right < C - 1) {
						++right;
						cur += min(R, 2);
					}
				} else {
					while (cur <= empty - min(R, 2) && right < C - 1) {
						++right;
						cur += min(R, 2);
					}
					while (cur <= empty - min(C, 2) && bottom < R - 1) {
						++bottom;
						cur += min(C, 2);
					}
					// cout << cur << endl;
				}
			}

			// cout << cur << " " << empty << " " << right << " " << bottom << endl;
			if (cur < empty) {
				if (right > 1 && bottom > 1) {
					// cout << empty - cur << endl;
					int line = 2 + (empty - cur) / (right - 1);
					int col = 1 + (empty - cur) % (right - 1);
					if (((right - 1) * (line - 2) + col - 1) == empty - cur) {
						br.first = line;
						br.second = col;
						cur = empty;
						//cout << line << " " << col << endl;
					}
				}
			}
		}

		if (empty == cur) {
			possible = true;
			for (int i = 0; i <= bottom; ++i) {
				cell[i][0] = '.';
				cell[i][1] = '.';
			}
			for (int j = 0; j <= right; ++j) {
				cell[0][j] = '.';
				cell[1][j] = '.';
			}
			for (int i = 0; i <= bottom; ++i) {
				for (int j = 0; j <= right; ++j) {
					if (i < br.first) {
						cell[i][j] = '.';
					} else if (i == br.first && j <= br.second) {
						cell[i][j] = '.';
					}
				}
			}
			cell[0][0] = 'c';
		}
	}

	// int a = 0;
	if (possible == true) {
		for (int i = 0; i < R; ++i) {
			for (int j = 0; j < C; ++j) {
				printf("%c", cell[i][j]);
				// if (cell[i][j] == '*') {
				// 	++a;
				// }
			}
			printf("\n");
		}
		// if (a != M) {
		// 	printf("BAD\n");
		// }
	} else {
		printf("Impossible\n");
	}
    return;
}

int main()
{
    int nCases = 0;
    scanf("%d", &nCases);
    for (int i = 1; i <= nCases; ++i) {
        cout << "Case #" << i << ": " << endl;
        solve();
    }
}
