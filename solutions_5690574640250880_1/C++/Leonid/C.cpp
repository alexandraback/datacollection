#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <ostream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cassert>
using namespace std;

void openFiles() {
#ifndef ONLINE_JUDGE
	freopen("C-large.in", "rt", stdin);
	//freopen("test.out", "wt", stdout);
#endif
}

struct Key {
	int n, m, b;
	friend ostream& operator<< (ostream& os, const Key& key) {
		os << key.n << " " << key.m << " " << key.b << endl;
		return os;
	}
};
bool operator<(const Key& a, const Key& b) {
	if (a.n != b.n) return a.n < b.n;
	if (a.m != b.m) return a.m < b.m;
	return a.b < b.b;
}
typedef vector<vector<vector<char> > > VVVC;
typedef vector<vector<char> > VVC;
typedef map<Key, VVVC> answers;
answers ans;

bool testit(vector<vector<int> >& isnearbomb, vector<vector<char> >& bombs, int nbombs) {
	int n = bombs.size(), m = bombs[0].size();
	vector<vector<int> > vis(n, vector<int>(m, 0));
	int viscount = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (isnearbomb[i][j] == 0) {
				vis[i][j] = 1;
				queue<pair<int, int> > q;
				q.push(make_pair(i, j));
				while (!q.empty()) {
					pair<int, int> p = q.front(); q.pop();
					for (int ii = max(0, p.first - 1); ii <= min(n - 1, p.first + 1); ii++) {
						for (int jj = max(0, p.second - 1); jj <= min(m - 1, p.second + 1); jj++) {
							if (!vis[ii][jj]) {
								vis[ii][jj] = 1;
								if (!isnearbomb[ii][jj]) {
									q.push(make_pair(ii, jj));
								}
							}
						}
					}
				}
				for (int ii = 0; ii < n; ii++) {
					for (int jj = 0; jj < m; jj++) {
						if (!vis[ii][jj] && bombs[ii][jj] == '.') {
							return false;
						}
					}
				}
				bombs[i][j] = 'c';
				return true;
			}
		}
	}
	// special case, all bombs but one
	if (nbombs == n * m - 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (bombs[i][j] == '.') {
					bombs[i][j] = 'c';
				}
			}
		}
		return true;
	}
	return false;
}

void bruteforce(int n, int m) {
	int bits = n * m;
	cerr << n << " " << m << endl;
	for (int i = 0; i < (1 << bits); i++) {
		vector<vector<char> > grid(n, vector<char>(m, '.'));
		vector<vector<int> > isnearbomb(n, vector<int>(m, 0));
		int bset = 0;
		for (int j = 0; j < bits; j++) {
			if ((i >> j) & 1) {
				bset++;
				int ii = j / m;
				int jj = j % m;
				grid[ii][jj] = '*';
				isnearbomb[ii][jj] = 1;
				for (int iii = max(0, ii - 1); iii <= min(n - 1, ii + 1); iii++) {
					for (int jjj = max(0, jj - 1); jjj <= min(m - 1, jj + 1); jjj++) {
						isnearbomb[iii][jjj] = 1;
					}
				}
			}
		}
		if (bset == n * m) continue; // all bombs test case is irrelevant

		// for (int ii = 0; ii < n; ii++) {
		// 	for (int jj = 0; jj < m; jj++) {
		// 		cout << grid[ii][jj];
		// 	}
		// 	cout << endl;
		// }
		// for (int ii = 0; ii < n; ii++) {
		// 	for (int jj = 0; jj < m; jj++) {
		// 		cout << isnearbomb[ii][jj];
		// 	}
		// 	cout << endl;
		// }

		bool good = testit(isnearbomb, grid, bset);
		//cout << good << endl << endl;
		Key k = {n, m, bset};
		if (good) {
			ans[k].push_back(grid);
		}
	}

}

bool analytical(int n, int m, int btarget) {
	//cout << n << " " << m << " " << btarget << endl;
	if (btarget == n * m - 1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (i < n - 1 || j < m - 1) {
					cout << '*';
				} else {
					cout << 'c';
				}
			}
			cout << endl;
		}
		return true;
	}
	for (int i = 0; i <= max(n - 2, 0); i++) {
		for (int j = 0; j <= max(m - 2, 0); j++) {
			// put corners in
			int b = i * m + j * n - i * j;
			// see how much more room there is
			int maxroom;
			int iroom = n - i - 2, jroom = m - j - 2;
			if (iroom > 0 && jroom > 0) {
				maxroom = iroom + jroom - 1;
			} else {
				maxroom = 0;
			}
			//cout << "[" << b << "; " << b + maxroom << "]" << endl;
			vector<vector<char> > g(n, vector<char>(m, '.'));
			//cout << i << " " << j << endl;
			int bstart = b, bend = b + maxroom;
			if (btarget >= bstart && btarget <= bend) {
				// initial set up
				for (int ii = 0; ii < i; ii++) for (int jj = 0; jj < m; jj++) g[ii][jj] = '*';
				for (int jj = 0; jj < j; jj++) for (int ii = 0; ii < n; ii++) g[ii][jj] = '*';
				// remaining bombs
				int rbombs = btarget - bstart;
				for (int ii = i; ii < n - 2 && rbombs > 0; ii++, rbombs--) {
					g[ii][j] = '*';
				}
				for (int jj = j + 1; jj < m - 2 && rbombs > 0; jj++, rbombs--) {
					g[i][jj] = '*';
				}
				g[n - 1][m - 1] = 'c';
				for (int ii = 0; ii < n; ii++) {
					for (int jj = 0; jj < m; jj++) {
						cout << g[ii][jj];
					}
					cout << endl;
				}
				return true;
			}
		}
	}
	return false;
}

void solve() {
	int n, m, k;
	scanf("%d %d %d ", &n, &m, &k);
	static int ntest = 0;
	printf("Case #%d:\n", ++ntest);
	bool ok = analytical(n, m, k);
	if (!ok) printf("Impossible\n");

	// Key key = {n, m, k};
	// VVVC v = ans[key];
	// static int ntest = 0;
	// printf("Case #%d:\n", ++ntest);
	// if (v.size() == 0) {
	// 	printf("Impossible\n");
	// } else {
	// 	for (int i = 0; i < n; i++) {
	// 		for (int j = 0; j < m; j++) {
	// 			cout << v[0][i][j];
	// 		}
	// 		cout << endl;
	// 	}
	// }
}

int main() {
	openFiles();
	// const int N = 4;
	// for (int i = 1; i <= N; i++) {
	// 	for (int j = 1; j <= N; j++) {
	// 		bruteforce(i, j);
	// 	}
	// }
	//cout << analytical(3, 1, 1) << endl;
	// for (int i = 0; i <= 25; i++) {
	// 	cout << analytical(2, 2, i) << endl;
	// }
	// for (answers::iterator ii = ans.begin(); ii != ans.end(); ii++) {
	// 	const VVVC& v = ii->second;
	// 	cout << ii->first << endl;
	// 	for (int k = 0; k < v.size(); k++) {
	// 		for (int i = 0; i < v[k].size(); i++) {
	// 			for (int j = 0; j < v[k][0].size(); j++) {
	// 				cout << v[k][i][j];
	// 			}
	// 			cout << endl;
	// 		}
	// 		cout << endl;
	// 	}
	// }

	int n; scanf("%d ", &n);
	for (int i = 0; i < n; i++) solve();

	return 0;
}
