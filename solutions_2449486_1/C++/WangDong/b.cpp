#include<string>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<vector>

using namespace std;

int T;
int n, m;
vector<vector<int>> a;

void init() {
	a.clear();
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		vector<int> c;
		for (int j=0; j<m; ++j) {
			int x;
			cin >> x;
			c.push_back(x);
		}
		a.push_back(c);
	}
}

bool check(int x, int y) {
	bool flag = true;
	for (int i=0; i<m; i++)
		if (a[x][i] > a[x][y]) flag = false;
	if (flag) return true;
	flag = true;
	for (int i=0; i<n; i++)
		if (a[i][y] > a[x][y]) flag = false;
	return flag;
}

string work() {
	for (int i=0; i<n; ++i)
		for (int j=0; j<m; ++j)
			if (!check(i,j))
				return "NO";
	return "YES";
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> T;
	for (int i=1; i<=T; i++) {
		init();
		cout << "Case #" << i << ": " << work() << endl;
	}
	return 0;
}