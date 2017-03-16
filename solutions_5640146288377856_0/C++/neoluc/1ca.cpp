#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <fstream>
#include <queue>

using namespace std;
/*int r;
int c;
int wn;
int wr;
int wc;
string wt;
vector<string> v;
int inf = 1e9;
map< pair< vector<string>, pair<int, int> >, int> me;
int go() {
	bool win = true;
	for (int i = 0; i < wn; i++) {
		if (v[wr][wc + i] == '.') {
			win = false;
			break;
		}
	}
	if (win) {
		return 0;
	}
	pair< vector<string>, pair<int, int> > pa(v, make_pair(wr, wc));
	if (me.find(pa) != me.end()) {
		return me[pa];
	}
	int u = inf;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (v[i][j] == '.') {
				if (i == wr && j >= wc && j < wc + wn) {
					bool canhide = false;
					for (int k = 0; k < r; k++) {
						for (int l = 0; l < c - wn + 1; l++) {
							if (v[k].substr(l, wn) == wt) {
								canhide = true;
								int twr = wr;
								int twc = wc;
								wr = k;
								wc = l;
								v[i][j] = 'o';
								u = min(u, go() + 1);
								wr = twr;
								wc = twc;
								v[i][j] = '.';
							}
						}
					}
					if (!canhide) {
						v[i][j] = 'o';
						u = min(u, go() + 1);
						v[i][j] = '.';
					}
				} else {
					v[i][j] = 'o';
					u = min(u, go() + 1);
					v[i][j] = '.';
				}
			}
		}
	}
	return me[pa] = u;
}*/
void gcj_solve(int caseno, ifstream &in, ofstream &out) {
	int r, c, w;
	in >> r >> c >> w;
	int ans = c / w * r;
	ans += w - 1;
	if (c % w != 0) {
		ans += 1;
	}
	cout << "Case #" << caseno << ": " << ans << endl;
	out << "Case #" << caseno << ": " << ans << endl;
}
int google_code_jam() {
	ifstream in("A-small-attempt4.in");
	//ifstream in("input.in");
	ofstream out("output.out");
	if (!in.is_open() || in.eof() || !out.is_open()) {
		cout << "error" << endl;
		return -1;
	}
	int nc;
	in >> nc;
	for (int i = 1; i <= nc; i++) {
		if (in.eof()) {
			cout << "error 2" << endl;
			return -1;
		}
		gcj_solve(i, in, out);
	}
	in.close();
	out.close();
	return 0;
}

int main() {
	google_code_jam();
}