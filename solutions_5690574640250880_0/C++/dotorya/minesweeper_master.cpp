#include <stdio.h>
#include <algorithm>
int d[51][51];
int R,C;
void print_ans(int chk) {
	int i, j;
	if(chk == 0) {
		for(i = 1; i <= R; i++) {
			for(j = 1; j <= C; j++) {
				if(i == 1 && j == 1) printf("c");
				else if(d[i][j]==1) printf(".");
				else printf("*");
			}
			printf("\n");
		}
	}
	else {
		for(i = 1; i <= C; i++) {
			for(j = 1; j <= R; j++) {
				if(i == 1 && j == 1) printf("c");
				else if(d[j][i]==1) printf(".");
				else printf("*");
			}
			printf("\n");
		}
	}
	return;
}

int main() {
	freopen("C-small-attempt4.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int case_no, T, M, chk = 0, i, j;
	scanf("%d", &T);
	for(case_no = 1; case_no <= T; case_no++) {
		printf("Case #%d:\n", case_no);
		chk = 0;
		for(i = 1; i <= 50; i++) for(j = 1; j <= 50; j++) d[i][j] = 0;
		scanf("%d %d %d", &R, &C, &M);
		M = R*C - M;
		if(C<R) {
			std::swap(R, C);
			chk = 1;
		}
		if(M == 1) {
			print_ans(chk);
			continue;
		}
		if(R == 1) {
			if(C != 1 && M == 1) {
				printf("Impossible\n");
				continue;
			}
			for(i = 1; i <= M; i++) d[1][i] = 1;
			print_ans(chk);
			continue;
		}
		if(R == 2) {
			if(M % 2 == 1 || M == 2) {
				printf("Impossible\n");
				continue;
			}
			for(i = 1; i <= M/2; i++) d[1][i] = d[2][i] = 1;
			print_ans(chk);
			continue;
		}
		if(M <= 3 || M == 5 || M == 7) {
			printf("Impossible\n");
			continue;
		}
		if(M == 4) {
			d[1][1] = d[1][2] = d[2][1] = d[2][2] = 1;
			print_ans(chk);
			continue;
		}
		if(M <= 2*R+1) {
			if(M % 2 == 0) {
				for(i = 1; i <= M/2; i++) d[i][1] = d[i][2] = 1;
				print_ans(chk);
			}
			else {
				for(i = 1; i <= M/2-1; i++) d[i][1] = d[i][2] = 1;
				d[1][3] = d[2][3] = d[3][3] = 1;
				print_ans(chk);
			}
			continue;
		}
		if(M % R == 1) {
			for(i = 1; i <= M/R	- 1; i++) for(j = 1; j <= R; j++) d[j][i] = 1;
			for(i = 1; i <= R-1; i++) d[i][M/R] = 1;
			d[1][M/R+1] = d[2][M/R+1] = 1;
			print_ans(chk);
			continue;
		}
		for(i = 1; i <= M/R; i++) for(j = 1; j <= R; j++) d[j][i] = 1;
		for(i = 1; i <= M%R; i++) d[i][M/R+1] = 1;
		print_ans(chk);
		continue;
	}
	return 0;
}