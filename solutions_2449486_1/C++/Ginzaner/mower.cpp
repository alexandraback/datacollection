#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

int a[105][105];
int rmax[105];
int cmax[105];

int main() {

	int test;
	scanf("%d", &test);
	
	for(int k = 1; k <= test; k++) {
		int n,m;
		scanf("%d %d", &n, &m);
		bool possible = true;
		memset(rmax,0,sizeof(rmax));
		memset(cmax,0,sizeof(cmax));
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				scanf("%d", &a[i][j]);
				if(a[i][j] > rmax[i]) rmax[i] = a[i][j];
				if(a[i][j] > cmax[j]) cmax[j] = a[i][j];
			}
		}
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if(a[i][j] < rmax[i] && a[i][j] < cmax[j]) {
					possible = false;
					j = m+1;
					i = n+1;
				}
			}
		}
		
		printf("Case #%d: ", k);
		printf(possible?"YES\n":"NO\n");
	}

	return 0;
}
