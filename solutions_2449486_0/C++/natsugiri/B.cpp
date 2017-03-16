#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;

typedef long long LL;

int N, M, A[111][111];
int row[111], col[111];
int main() {
    int T; scanf("%d", &T);
    for (int tc=1; tc<=T; tc++) {
	scanf("%d%d", &N, &M);
	for (int i=0; i<N; i++) {
	    for (int j=0; j<M; j++) {
		scanf("%d", A[i]+j);
	    }
	}

	memset(row, 0, sizeof row);
	memset(col, 0, sizeof col);
	for (int i=0; i<N; i++) {
	    for (int j=0; j<M; j++) {
		col[i]=max(col[i], A[i][j]);
		row[j]=max(row[j], A[i][j]);
	    }
	}
	bool y=true;
	for (int i=0; y && i<N; i++) {
	    for (int j=0; y && j<M; j++) {
		y&=A[i][j]==min(col[i], row[j]);
	    }
	}
	printf("Case #%d: %s\n", tc, y?"YES":"NO");
    }

    return 0;
}
