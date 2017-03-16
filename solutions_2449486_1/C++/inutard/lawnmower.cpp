#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <complex>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
#include <cstring>

using namespace std;

typedef long double ld;
typedef long long ll;
typedef pair<ll, ll> pii;
typedef complex<ld> pt;

vector<int> row;
vector<int> col;
set<int> height;
int board[105][105];

bool remove_row(int r, int h) {
	int cnt = 0;
	for (int j = 0; j < col.size(); j++) {
		int c = col[j];
		if (board[r][c] == h) cnt++;
	}
	
	if (cnt == col.size())
		row.erase(find(row.begin(), row.end(), r));
	return (cnt == col.size());
}

bool remove_col(int c, int h) {
	int cnt = 0;
	for (int i = 0; i < row.size(); i++) {
		int r = row[i];
		if (board[r][c] == h) cnt++;
	}
	
	if (cnt == row.size())
		col.erase(find(col.begin(), col.end(), c));
	return (cnt == row.size());
}

bool solve() {
	while (!height.empty()) {
		int h = *height.begin(); height.erase(h);
		if (h > 100 || h < 1) return false;
		//testing for rows of h's
		for (int i = 0; i < row.size(); i++) {
			int r = row[i];
			if (remove_row(r, h)) {
				i--;
			}
		}
		
		// cout << "past row" << endl;
		// for (int i = 0; i < row.size(); i++) cout << row[i] << " ";
		// cout << endl;
		if (row.empty()) return true;
		
		//testing for cols of h's
		for (int i = 0; i < col.size(); i++) {
			int c = col[i];
			if (remove_col(c, h)) {
				i--;
			}
		}
		
		// cout << "past col" << endl;
		// for (int i = 0; i < col.size(); i++) cout << col[i] << " ";
		// cout << endl;
		if (col.empty()) return true;
		
	}
	
	return false;
}

int T, m, n;
int main()
{
	cin >> T;
	for (int c = 1; c <= T; c++) {
		row.clear(); col.clear(); height.clear();
		bool yes;
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int x; cin >> x;
				board[i][j] = x;
				height.insert(x);
			}
		}
		
		row.resize(n);
		col.resize(m);
		for (int i = 0; i < n; i++) row[i] = i;
		for (int j = 0; j < m; j++) col[j] = j;
		
		yes = solve();
		// for (int i = 0; i < n; i++) {
			// for (int j = 0; j < m; j++) {
				// cout << board[i][j] << " ";
			// }
			// cout << endl;
		// }
	
		cout << "Case #" << c << ": " << (yes ? "YES" : "NO") << endl;
	}
	return 0;
}