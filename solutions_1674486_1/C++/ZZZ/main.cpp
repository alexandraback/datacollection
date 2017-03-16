#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>

#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>

#include <iomanip>
#include <algorithm>

using namespace std;
#define N 1001
int g[N][N];
int gg[N][N];
int n;
bool found;
void dfs(int root, int cur, int depth) {
	if(found)
		return ;
	//cout << depth << endl;
	if(depth == 0) return ;
	for(int i = 0; i < n; ++i) {
		if(g[cur][i]) {
			gg[root][i] += 1;
			if(gg[root][i] >= 2)
				found = true;
			dfs(root, i, depth-1);
		}
	}
}

int main() {
	int i, j, k;
	int t;
	freopen("D://data.in", "r", stdin);
	freopen("D://data.out", "w", stdout);

	cin >> t;
	int c;
	for(c = 0; c < t; ++c)
	{
		found = false;
		int mi, y;
		cin >> n;
		for(i = 0; i < n; ++i)
		for(j = 0; j < n; ++j) {
			g[i][j] = 0;
			gg[i][j] = 0;
		}

		for(i = 0; i < n; ++i) {
			cin >> mi;
			while(mi--) {
				cin >> y;
				gg[i][y-1] = g[i][y-1] = 1;
			}
		}

		for(int i = 0; i < n; ++i) 
			for(int j = 0; j < n; ++j) {
				if(g[i][j] == 1)
					dfs(i, j, n-1);
			}
		
	/*	for(i = 0; i < n; ++i) {
			for(j = 0; j < n; ++j) {
				cout << gg[i][j] << " ";
			}
		cout << endl;
		}*/

		printf("Case #%d: %s\n", c+1, (found? "Yes": "No"));
	}

	return 0;
}