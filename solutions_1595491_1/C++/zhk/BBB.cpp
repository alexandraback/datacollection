#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;


const int NN = 128;
int  N, S, a[NN], P;
int  f[NN][NN];

int  no_add(int t) {
	int  gg[] = {0, 1, 1};
	int  mm = t/3 + gg[t%3];
	return mm >= P ? 1 : 0;
}
int  yes_add(int t) {
	int  gg[] = {1, 1, 2};
	return ((t/3)+gg[t%3]) >= P ? 1 : 0;
}
int go() {
	
	scanf("%d%d%d", &N, &S, &P);
	for(int i=1; i<=S; ++i) f[0][i] = -(1<<20);
	f[0][0] = 0;
	for(int i=1; i<=N; ++i) {
		int  t = 0;
		scanf("%d", &t);
		for(int j=0; j<=S; ++j) {
			f[i][j] = f[i-1][j] + no_add(t);;
		} if(t < 2) continue;
		for(int j=1; j<=S; ++j) {
			f[i][j] = max(
					f[i][j],
					f[i-1][j-1] + yes_add(t)
					);
		}
	}

	int  ret = 0;
	ret = max(ret, f[N][S]);

	return ret;
}

int main(int argc, char* argv[]) {
	int T;
	scanf("%d", &T);
	for(int it=1; it<=T; ++it) {
		printf("Case #%d: %d\n",
				it, go());
	}
	return 0;
}
