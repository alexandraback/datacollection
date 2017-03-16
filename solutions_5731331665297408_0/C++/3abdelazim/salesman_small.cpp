#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define For(i,a,b) for (int i = a; i < b; i++)

int p[55];
int n, m, z[55];
set <int> g[55];
string res;
set <int> v;

string getstr(int n) {
	char s[11];
	sprintf(s, "%d", n);
	return s;
}

string getstr() {
	string ret = "";
	For (i,0,n) {
		ret += getstr(z[p[i]]);
	}
	return ret;
}

void updateRes() {
	string res2 = getstr();
	if (res == "" || res2 < res)
		res = res2;
}

int dfs(int node, int idx) {
	idx++;
	while(idx < n && g[node].count(p[idx])) {
		idx = dfs(p[idx], idx);
	}
	return idx;
}

int main() {
	freopen("small.in", "r", stdin);
	freopen("small.out", "w", stdout);
	
	int tt;
	cin >> tt;
	For (t, 1, tt+1) {
		cin >> n >> m;
		For (i,0,n) {
			cin >> z[i+1];
		}
		For (i,0,55)
			g[i].clear();
		For (i,0,m) {
			int v1, v2;
			cin >> v1 >> v2;
			g[v1].insert(v2);
			g[v2].insert(v1);
		}
		
		For (i,0,n) {
			p[i] = i+1;
		}
		res = "";
		do {
			if (dfs(p[0], 0) == n)
				updateRes();
		} while(next_permutation(p, p+n)) ;
		cout << "Case #" << t << ": " << res << endl;
	}
} 
