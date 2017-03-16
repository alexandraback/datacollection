#include <iostream>
#include <vector>

using namespace std;
		vector <vector <int> > gr;
vector <bool> c;


bool dfs(int v)
{
	if (c[v])
		return true;
	c[v] = true;
	for (int i = 0; i < gr[v].size(); ++i)
		if (dfs(gr[v][i]))
			return true;
	return false;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A.out", "w", stdout);
	int t;
	cin >> t;
	for (int tc = 1; tc <= t; tc ++) {
		bool ok = false;
		gr.clear();
		int n;
		cin >> n;
		gr.resize(n);
		for (int i= 0; i < n; ++ i ) {
			int m;
			cin >> m;
			for (int j = 0; j < m; ++j ) {
				int y;
				cin >> y;
				y --;
				gr[i].push_back(y);
			}
		}

		for (int i =0; i < n; ++i ) {
			c.assign(n, false);
			ok =ok || dfs(i);
		}

		if (ok) {
			cout << "Case #" << tc << ": Yes" << endl;
		} else {
			cout << "Case #" << tc << ": No" << endl;
		}
	}
	return 0;
}