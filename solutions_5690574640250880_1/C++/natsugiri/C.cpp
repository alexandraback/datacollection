#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;


int main() {
    int T;
    scanf("%d", &T);

    for (int tc=1; tc<=T; tc++) {

	int R, C, N, M;
	char F[64][64];
	scanf("%d%d%d", &R, &C, &N);
	M = R*C-N;
	memset(F, '*', sizeof F);
	
	bool no = false;
	if (R == 1) for (int j=0; j<M; j++) F[0][j] = '.';
	else if (C == 1) for (int i=0; i<M; i++) F[i][0] = '.';
	else if (M == 1) F[0][0] = '.';
	else if (M < 4 || M == 5 || M == 7) no = true;
	else {
	    int cnt = 4;
	    bool bc = false, br = false;
	    
	    F[0][0] = F[0][1] = F[1][0] = F[1][1] = '.';
	    if (C > 2 && M-cnt >= 2) {
		F[0][2] = F[1][2] = '.';
		cnt += 2;
		bc = true;
	    }
	    if (R > 2 && M-cnt >= 2) {
		F[2][0] = F[2][1] = '.';
		cnt += 2;
		br = true;
	    }
	    for (int j=3; j<C && M-cnt>=2; j++) {
		F[0][j] = F[1][j] = '.';
		cnt += 2;
	    }
	    for (int i=3; i<R && M-cnt>=2; i++) {
		F[i][0] = F[i][1] = '.';
		cnt += 2;
	    }
	    if (br && bc) {
		for (int i=2; i<R; i++) {
		    for (int j=2; j<C && cnt<M; j++) {
			F[i][j] = '.';
			cnt++;
		    }
		}
	    } else if (cnt < M) no = true;
	}
	
	printf("Case #%d:\n", tc);

	if (no) puts("Impossible");
	else {
	    F[0][0] = 'c';
	    for (int i=0; i<R; i++) {
		F[i][C] = 0;
		puts(F[i]);
	    }
	}
	fflush(stdout);
    }

    return 0;
}
