#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <complex>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <gmpxx.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (n); ++i)
#define foreach(it, a) for (__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)

template<typename T> inline void ignore(T) {
}

int n;
vector<vector<int> > lists;
vector<int> listToRow; // list index -> currently assigned row
vector<int> rowToList; // row -> assigned list
vector<int> colToList; // col -> assigned list

bool isValidSotution(int c) {
	// Ensure all rows have been assigned
	forn(r, n) {
		if (rowToList[r] < 0) {
			return false;
		}
	}

	colToList.assign(n, -1);
	colToList[c] = 2*n-2;
	forn(i, 2*n-2) {
		if (listToRow[i] == -1) {
			// Find a column to assign
			bool hasBeenAssigned = false;
			forn(c2, n) {
				if (colToList[c2] != -1) {
					continue;
				}
				bool colIsOk = true;
				forn(r, n) {
					if (lists[rowToList[r]][c2] != lists[i][r]) {
						colIsOk = false;
						break;
					}
				}
				if (colIsOk) {
					colToList[c2] = i;
					hasBeenAssigned = true;
					break;
				}
			}
			if (!hasBeenAssigned) {
				return false;
			}
		}
	}
	return true;
}

bool assignRow(int i, int c) {
	if (i == 2*n-2) {
		// Check solution
		return isValidSotution(c);
	}
	// Try assign
	forn(r, n) {
		if (rowToList[r] == -1 && lists[i][c] == lists.back()[r]) {
			listToRow[i] = r;
			rowToList[r] = i;
			//cout << i << " -> r" << r << endl;
			if (assignRow(i+1, c)) {
				return true;
			}
			//cout << ".." << endl;
			rowToList[r] = -1;
			listToRow[i] = -1;
		}
	}
	// Try skip
	assert(listToRow[i] == -1);
	if (assignRow(i+1, c)) {
		return true;
	}
	return false;
}

vector<int> solve() {
	// Try to assign column 1 to n to the first list
	colToList.assign(n, -1);
	bool ok = false;
	for (int iter = 0; !ok && iter <= n; ++iter) {
		forn(c, n) {
			listToRow.assign(2*n-2, -1);
			rowToList.assign(n, -1);
			//cout << "c=" << c << endl;
			if (assignRow(0, c)) {
				ok = true;
				break;
			}
		}
		if (!ok) {
			//cout << "swap!" << endl;
			swap(lists[iter], lists.back());
		}
	}
	assert(ok);
	// Find column with no list
	vector<int> missing(n);
	forn(c, n) {
		if (colToList[c] == -1) {
			forn(r, n) {
				missing[r] = lists[rowToList[r]][c];
			}
		}
	}
	return missing;
}

int main(void) {
	int t; cin >> t;
	forn(k, t) {
		cin >> n;
		lists.assign(2*n-1, vector<int>(n));
		forn(i, 2*n-1) {
			forn(j, n) {
				cin >> lists[i][j];
			}
		}
		vector<int> ans = solve();
		cout << "Case #" << (k+1) << ":";
		forn(i, n) {
			cout << ' ' << ans[i];
		}
		cout << endl;
	}
	return 0;
}
