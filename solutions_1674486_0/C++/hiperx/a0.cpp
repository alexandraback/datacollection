#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

int nt0, nt;

int n;
int m[1024];
bool adj[1024][1024];

int main() {
	scanf(" %d", &nt0);
	for(nt = 1 ; nt <= nt0 ; nt++) {
		printf("Case #%d: ", nt);
		
		scanf(" %d", &n);
		
		for(int i=0 ; i<n ; i++) {
			for(int j=0 ;j<n ; j++)
				adj[i][j] = false;
			scanf(" %d", &m[i]);
			for(int j=0 ; j<m[i] ; j++){
				int k;
				scanf(" %d", &k);
				adj[i][k-1] = true;
			}
		}

		bool ans = false;
		for(int j=0 ; j<n && !ans; j++)
			for(int i=0;i<n && !ans ; i++)
				for(int k=0 ; k<n && !ans ; k++)
					if(adj[i][j] && adj[j][k]) {
						if(adj[i][k]) ans = true;
						adj[i][k] = true;
					}
		if(ans) puts("Yes");
		else puts("No");
	}

	return 0;
}
