#include <iostream>
#include <fstream>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <list>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <functional>
#include <limits>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;

const double pi = acos(-1.0);

#define oned(a, x1, x2) { cout << #a << ":"; for(int _i = (x1); _i < (x2); _i++){ cout << " " << a[_i]; } cout << endl; }
#define twod(a, x1, x2, y1, y2) { cout << #a << ":" << endl; for(int _i = (x1); _i < (x2); _i++){ for(int _j = (y1); _j < (y2); _j++){ cout << (_j > y1 ? " " : "") << a[_i][_j]; } cout << endl; } }
#define mp(x, y) make_pair(x, y)

int n;
vector<vector<int> > g;

void solve(int test) {
	bool yes = false;
	for(int i = 0; i < n && !yes; i++) {
		vector<int> vis(n, false);
		vis[i] = true;
		queue<int> Q;
		Q.push(i);
		while(!Q.empty() && !yes) {
			int v = Q.front(); Q.pop();
			for(int j = 0; j < (int)g[v].size(); j++) {
				int u = g[v][j];
				if(!vis[u]) {
					vis[u] = true;
					Q.push(u);
				} else {
					yes = true;
					break;
				}
			}
		}
	}

	cout << "Case #" << test << ": " << (yes ? "Yes" : "No") <<endl;
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	
	int testNumber; scanf("%d\n", &testNumber);
	for(int test = 1; test <= testNumber; test++) {
		cin >> n;
		g = vector<vector<int> >(n);
		for(int i = 0; i < n; i++) {
			int m; cin >> m;
			for(int j = 0; j < m; j++) {
				int k; cin >> k;
				k--;
				g[i].push_back(k);
			}
		}
		solve(test);
	}
}
