#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define MAXN 110

int T, N, M;

int G[MAXN][MAXN];
int myG[MAXN][MAXN];
int maxX[MAXN], maxY[MAXN];

void fill_right() {
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			myG[i][j] = min(myG[i][j], maxX[i]);
	return;
}

void fill_up() {
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			myG[i][j] = min(myG[i][j], maxY[j]);
	return;
}

bool is_equal() {
	for(int i=0; i<N; i++)
		for(int j=0; j<M; j++)
			if (myG[i][j] != G[i][j])
				return false;
	return true;
}

int main() {
	freopen("lawn.in", "r", stdin);
	scanf("%d", &T);
	for(int asdf=1; asdf<=T;asdf++) {
		memset(maxX, 0, sizeof(maxX));
		memset(maxY, 0, sizeof(maxY));
		for(int i=0; i<MAXN; i++)
			for(int j=0; j<MAXN; j++)
				myG[i][j] = 10000;

		scanf("%d%d", &N, &M);
		for(int i=0; i<N; i++) {
			for(int j=0; j<M; j++) {
				scanf("%d", &G[i][j]);
				maxX[i] = max(G[i][j], maxX[i]);
				maxY[j] = max(G[i][j], maxY[j]);
			}
		}
		for(int i=0; i< max(N, M)+3; i++) {
			fill_right();
			fill_up();
		}
		printf("Case #%d: ", asdf);
		(is_equal()) ? printf("YES\n") : printf("NO\n");
	}

	return 0;
}
