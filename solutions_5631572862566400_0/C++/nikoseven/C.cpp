#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int p[5000], n;
bool vis[5000];
vector<int> G[5000];

int len(int u) {
	int l = 0;
	for(auto &v : G[u]) if( p[u] != v )
		l = max(l, len(v) + 1);
	return l;
}

int calc() {
	int mx = 0;
	for(int a=1; a<=n; ++a) if( p[a] > a && p[p[a]] == a ) {
		int b = p[a];
		mx += 2 + len(a) + len(b);
	}
	return mx;
}

int main() {
	int T, ics = 0;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) G[i].clear();
		for(int i=1; i<=n; ++i) {
			scanf("%d", &p[i]);
			G[p[i]].push_back(i);
			//printf("%d -> %d\n", i, p[i]);
		}
		
		int mxc = calc();
		for(int i=1; i<=n; ++i) {
			int nc = 1, z = p[i];
			for(int j=1; j<=n; ++j) vis[j] = false;
			while( z != i && !vis[z] ) {
				vis[z] = true;
				z = p[z];
				++ nc;
			}
			if( z == i )
				mxc = max(mxc, nc);
		}
		printf("Case #%d: %d\n", ++ics, mxc);
	}
	return 0;
}

