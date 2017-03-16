#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1e6 + 5;

int tot, P[MAXN][3], Ans[MAXN][3], B1[20][20], B2[20][20], B3[20][20];
bool Flag[20][20][20];

int main() {
	freopen("C.in", "r", stdin), freopen("C.out", "w", stdout);
	
	int Test;
	scanf("%d", &Test);
	for (int Time = 1; Time <= Test; Time ++) {
		printf("Case #%d: ", Time);
		int A, B, C, K;
		memset(Flag, 0, sizeof Flag);
		memset(B1, 0, sizeof B1);
		memset(B2, 0, sizeof B2);
		memset(B3, 0, sizeof B3);
		scanf("%d%d%d%d", &A, &B, &C, &K);
		tot = 0;
		for (int i = 1; i <= A; i ++)
			for (int j = 1; j <= B; j ++) {
				int Lim = min(K, C);
				for (int l = 1; l <= Lim; l ++) {
					P[++ tot][0] = i;
					P[tot][1] = j;
					P[tot][2] = (i + j + l) % C + 1;
				}
			}
		for (int i = 1; i <= tot; i ++) {
			bool Tmp = 0;
			int a = P[i][0], b = P[i][1], c = P[i][2];
			if (Flag[a][b][c]) Tmp = 1;
			if (B1[a][b] == K || B2[a][c] == K || B3[b][c] == K) Tmp = 1;
			if (Tmp == 1) {
				
			} else {
				Flag[a][b][c] = 1;
				B1[a][b] ++; 
				B2[a][c] ++;
				B3[b][c] ++;
			}
		}
		printf("%d\n", tot);
		for (int i = 1; i <= tot; i ++) printf("%d %d %d\n", P[i][0], P[i][1], P[i][2]);
	}
}