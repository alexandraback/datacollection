#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int A[2000][2];
int P[2000];
bool B[2000];
bool B1[2000];
int N;

int calc() {
	int lev = 0;
	int res = 0;
	memset(B, 0, sizeof(B));
	memset(B1, 0, sizeof(B1));
	for (int i=0; i<=N; i++) {
		for(;;) {
			bool f = false;
			for (int j=0; j<N; j++) {
				if (A[j][1]<=lev && !B[j]) {
					lev++;
					if (!B1[j])
						lev++;
					res++;
					B[j] = true;
					f = true;
				}
			}
			if (!f) break;
		}
		if (i==N) break;
		if (B[P[i]]) continue;
		if (A[P[i]][0]>lev) return 2*N+1;
		lev++;
		B1[P[i]] = true;
		res++;
	}
	for (int i=0; i<N; i++)
		if (!B[i]) return 2*N+1;
	return res;
}

int main() {
	freopen("B.txt", "r", stdin);
	int T;
	scanf("%d", &T);
	for (int I=0; I<T; I++) {
		scanf("%d", &N);
		for (int i=0; i<N; i++) {
			scanf("%d%d", &A[i][0], &A[i][1]);
		}
		for (int i=0; i<N; i++)
			P[i] = i;
		int res = 2*N+1;
		do {
			int r = calc();
			if (res > r)
				res = r;
		} while (next_permutation(P, P+N));
		printf("Case #%d: ", I+1);
		if (res >= 2*N+1)
			printf("Too Bad\n");
		else
			printf("%d\n", res);
	}
	return 0;
}
