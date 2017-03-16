#include <iostream>
using namespace std;

int T;
int N,M;
int mxH[105],mxV[105];
int grid[105][105];

bool check() {
	for (int i=0;i<N;i++) {
		mxH[i] = 0;
		for(int j=0;j<M;j++) {
			mxH[i] = max(mxH[i], grid[i][j]);
		}
	}
	for (int i=0;i<M;i++) {
		mxV[i] = 0;
		for(int j=0;j<N;j++) {
			mxV[i] = max(mxV[i], grid[j][i]);
		}
	}

	for(int i=0;i<N;i++) {
		for(int j=0;j<M;j++) {
			if(grid[i][j] != min(mxH[i], mxV[j]))
				return false;
		}
	}
	return true;
}

int main() {
	freopen("Text.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	scanf("%d", &T);
	for(int c=1;c<=T;c++) {
		scanf("%d", &N);
		scanf("%d", &M);
		for(int i=0;i<N;i++) {
			for(int j=0;j<M;j++) {
				scanf("%d", grid[i]+j);
			}
		}
		printf("Case #%d: %s\n", c, check() ? "YES":"NO");
	}
	return 0;
}