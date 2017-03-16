#include <iostream>
#include <stdio.h>
#include <vector>
using namespace std;

#define plus asdplus

int t;
int n, m, b;
int xi, yi, cnt;
	int u[64][64];

void around(int x, int y) {
	for(int i = x - 1; i <= x + 1; ++i)
	if (i >= 0 && i < n)
	for(int j = y - 1; j <= y + 1; ++j)
	if (j >= 0 && j < m)
	if (u[i][j] == 0) {
		u[i][j] = 1;
		++cnt;
	}
}

void gen() {
	vector<pair<int, int> > v;
	for(int i = 0; i < n; ++i)
	for(int j = 0; j < m; ++j) {
		u[i][j] = 0;
		v.push_back(make_pair(i, j));
	}

	bool first = true;	
	cnt = 0;
	while(cnt < b) {
		int ind = rand() % v.size();
		int x = v[ind].first;
		int y = v[ind].second;
		if (first) {
			u[x][y] = 2;
			++cnt;
			around(x, y);
			first = false;
			xi = x;
			yi = y;
			swap(v[ind], v.back());
		} else if (u[x][y] == 1) {
			u[x][y] = 2;
			around(x, y);
			swap(v[ind], v.back());
		}
	}
}

int main() {
cin >> t;
for(int T = 0; T < t; ++T) {
	cout << "Case #" << T + 1 << ":\n";

	cin >> n >> m >> b;
	b = n * m - b;

	for(int q = 0; q < 10000; ++q) {
		gen();
		if (cnt == b) break;
	}

	if (b == 1) {
		 for(int i = 0; i < n; ++i)
         	for(int j = 0; j < m; ++j) {
			u[i][j] = 0;
		}
		xi = 0;
		yi = 0;
		cnt = 1;
	}

	if (cnt != b) cout << "Impossible" << endl; else {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < m; ++j) {
				if (i == xi && j == yi) cout << "c"; else
				if (u[i][j]) cout << "."; else cout << "*";
			}
			cout << endl;
		}
	}
cerr << T << endl;


	//cout << ans << endl;
}
	return 0;
}
