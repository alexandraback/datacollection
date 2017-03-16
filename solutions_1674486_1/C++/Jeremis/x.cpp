#include <iostream>
#include <vector>
#include <set>
#include <memory.h>
#include <map>
#include <algorithm>
#include <string>
using namespace std;


bool was[1111];
vector < vector <int> > *g;
void dfs(int t) {
	was[t] = true;
	for (int i=0;i<(*g)[t].size();i++) {
		if (was[(*g)[t][i]]) throw 1; else dfs((*g)[t][i]);
	}
}

int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);

	int t;
	cin >> t;
	for (int z=0;z<t;z++) {
		int n;
		cin >> n;
		vector < vector <int> > v;
		v.resize(n);
		g = &v;
		int c;
		for (int i=0;i<n;i++) {
			cin >> c;
			if (c) v[i].resize(c);
			for (int j=0;j<c;j++) {
				cin >> v[i][j];
				--v[i][j];
			}
		}
		cout << "Case #" << z+1 << ": ";
		try {
			for (int i=0;i<n;i++) {
				memset(was,0,sizeof(was));
				dfs(i);
			}
			cout << "No" << endl;
		} catch(int) {
			cout << "Yes" << endl;
		}
	}
}