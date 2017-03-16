#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <queue>
#include <vector>
#include <time.h>
#include <complex>
#include <map>
#define LL long long
using namespace std;

const LL INF = 1000000000000000000;
const int MXL = 25, MXX = 38;

int T, n, m, l[2], record[MXX][2], rtot, bb[MXX];
LL minn;
char mina[MXL], minb[MXL];
char a[2][MXL], b[2][MXL];
void DFS(int step) {
	if(step == rtot + 1) {
		for(int i = 1; i <= rtot; i++) { //
			b[record[i][1]][record[i][0]] = bb[i] + '0';
		}
		LL A[2];
		A[0] = A[1] = 0;
		for(int w = 0; w < 2; w++) {
			for(int i = 0; i < l[w]; i++) {
				A[w] = A[w] * 10 + b[w][i] - '0';
			}
		}
		if(abs(A[0] - A[1]) < minn) {
			minn = abs(A[0] - A[1]);
			strcpy(mina, b[0]) ; strcpy(minb, b[1]);
		}
		return ;
	}
	for(int i = 0; i <= 9; i++) {
		bb[step] = i;
		DFS(step + 1);
	}
}
inline void solve() {
	scanf("%d\n", &T);
	for(int ii = 1; ii <= T; ii++) {
		scanf("%s %s\n", a[0], a[1]);
		//printf("%s %s\n", a[0], a[1]);
		n = strlen(a[0]); m = strlen(a[1]);
		l[0] = n; l[1] = m;
		rtot = 0;
		for(int w = 0; w < 2; w++) strcpy(b[w], a[w]);
		for(int w = 0; w < 2; w++) for(int i = 0; i < l[w]; i++) if(a[w][i] == '?') { ///
			record[++rtot][0] = i;
			record[rtot][1] = w; //
		}
		minn = INF;
		//printf("%d\n", rtot);
		DFS(1);
		printf("Case #%d: %s %s\n", ii, mina, minb);
	}
}
int main() {
	freopen("B.in","r",stdin);freopen("B.out","w",stdout);
	solve();
	return 0;
}
