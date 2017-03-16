#include <iostream>
#include <cstdio>
using namespace std;

int R, C;
int MP[100][100];

bool Check(int r, int c, int dr, int dc, int chk) {
	if(r < 0 || r >= R) return true;
	if(c < 0 || c >= C) return true;

	if(MP[r][c] > chk) return false;
	return Check(r+dr, c+dc, dr, dc, chk);
}

int main() {
	freopen("B_Large.in", "r", stdin);
	freopen("B_Large.out", "w", stdout);

	int T;
	scanf("%d", &T);

	for(int TC=1; TC<=T; TC++) {
		scanf("%d %d", &R, &C);
		for(int i=0; i<R; i++) {
			for(int j=0; j<C; j++) {
				scanf("%d", &MP[i][j]);
			}
		}

		bool result = true;
		for(int i=0; i<R; i++) {
			for(int j=0; j<C; j++) {
				if(Check(i+1, j, 1, 0, MP[i][j]) && Check(i-1, j, -1, 0, MP[i][j])) continue;
				if(Check(i, j+1, 0, 1, MP[i][j]) && Check(i, j-1, 0, -1, MP[i][j])) continue;
				result = false;
			}
		}

		printf("Case #%d: ", TC);
		if(result) printf("YES\n");
		else printf("NO\n");
	}
}