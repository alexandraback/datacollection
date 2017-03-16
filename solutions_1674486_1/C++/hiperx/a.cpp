#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int nt0, nt;

int n;
int m[1024], index[1024];
int adj[1024][1024];

bool processed[1024];

int ncolor;
bool color[1024][1024];

bool cmp(int x, int y) {
	return m[x] < m[y];
}

bool search(int k) {
	processed[k] = true;
			if(m[k] == 0) {
				color[k][ncolor++] = true;
			}
	for(int i=0 ; i<m[k] ; i++) {
		if(!processed[adj[k][i]]) if(search(adj[k][i])) return true;
		for(int j=0 ; j<ncolor ; j++)
			if(color[adj[k][i]][j]) {
				if (color[k][j]) return true;
				else color[k][j] = true;
			}
	}
	return false;
}

int main() {
	scanf(" %d", &nt0);
	for(nt = 1 ; nt <= nt0 ; nt++) {
		printf("Case #%d: ", nt);
		
		scanf(" %d", &n);

		ncolor = 0;
		for(int i=0 ; i<n ; i++) {
			index[i] = i;
			processed[i] = false;
			for(int j=0 ; j<n ; j++)
				color[i][j] = false;
		}
		
		for(int i=0 ; i<n ; i++) {
			scanf(" %d", &m[i]);
			for(int j=0 ; j<m[i] ; j++){
				scanf(" %d", &adj[i][j]);
				--adj[i][j];
			}
		}
		
		sort(index, index+n, cmp);
		
		bool ans = false;
		for(int i=0 ; i<n && !ans ; i++) {
			if(processed[index[i]]) continue;
			ans = ans | search(index[i]);
		}
		
		if(ans) puts("Yes");
		else puts("No");
	}

	return 0;
}
