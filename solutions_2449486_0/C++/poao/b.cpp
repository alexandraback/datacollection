#include <cstdio>
#include <algorithm>

int maxr[110], maxc[110], in[110][110], r, c, T;

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small.txt", "w", stdout);
	scanf("%d", &T);
	for(int tc=1; tc<=T; tc++) {
		scanf("%d%d", &r, &c);
		for(int i=0; i<r; i++)
			maxr[i] = 0;
		for(int j=0; j<c; j++)
			maxc[j] = 0;
		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++) {
				scanf("%d", &in[i][j]);
				maxr[i] = std::max( maxr[i], in[i][j] );
				maxc[j] = std::max( maxc[j], in[i][j] );
			}
		bool pos = true;
		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++)
				if( std::min(maxr[i],maxc[j]) > in[i][j] )
					pos = false;
		printf("Case #%d: %s\n", tc, pos?"YES":"NO");
	}
}
