#include<cstdio>
#include<memory.h>
#include<algorithm>
using namespace std;
bool d[2][6][1000];
int main() {
	int tc, z = 1;
	scanf("%d", &tc);
	freopen("out.txt", "w", stdout);
	while(tc--) {
		int e, r, n;
		memset(d, 0, sizeof(d));
		scanf("%d%d%d", &e, &r, &n);
		
		d[1][e][0] = true;
		int ans = 0;
		for(int i = 0 ; i < n ; i++) {
			int v;
			scanf("%d", &v);

			for(int j = 1 ; j <= e ; j++) {
				for(int k = 0 ; k < 1000 ; k++) {
					if( d[(i+1)%2][j][k] ) {
						for(int q = 0 ;  q <= j ; q++) {
							int w = (j-q+r)>=e?e:j-q+r;
							d[i%2][w][k+q*v] = true;
							ans = max(ans, k+q*v);
						}
					}
				}
			}
			memset(d[(i+1)%2], 0, sizeof(d[(i+1)%2]));
		}
		printf("Case #%d: %d\n",z++, ans);
	}
	fclose(stdout);
}