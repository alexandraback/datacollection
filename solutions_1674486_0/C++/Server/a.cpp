#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
#define pb push_back
vector <int > a[59];
int n;
int ok, was[59];
void dfs(int u) {	
	was[u] = 1;
	int i, j, v;
	for (i = 0; i < a[u].size(); i++) {
		v = a[u][i];
		if (was[v] == 0) 
			dfs(v);
		else ok = 1;
	}
}

int main () {
	freopen("a2.in", "r", stdin);
	freopen("a.txt", "w", stdout);
	int t, i, j, x, y;
	scanf("%d", &t);
	for (int w = 1; w <= t; w++) {
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			a[i].clear();
			scanf("%d", &x);
			for (j = 1; j <= x; j++) {
				scanf("%d", &y);
				a[i].pb(y);
			}
		}            
		ok = 0;
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) was[j] = 0;
			dfs(i);
		}
		printf("Case #%d: ", w);
		if (ok) cout << "Yes\n";
		else cout << "No\n";
	}
		


}