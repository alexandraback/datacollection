#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <vector>
#define change(x,y) t=x,x=y,y=t;
int Mini(int x, int y) {
	return x < y ? x : y;
}
int Maxi(int x, int y) {
	return x > y ? x : y;
}
struct sg {
	int x;
	int y;
	bool friend operator < (const sg i, const sg j) {
		return i.x < j.x;
	}
}v[101];
int T, Co, i, j, k, l,N,data[55][55],Print[55][55],t,C1[55],C2[55];
int ValidP() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (Print[i][j] == 0) break;
			if (Print[i][j] <= Print[i][j - 1]) return 0;
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (Print[j][i] == 0) break;
			if (Print[j][i] <= Print[j-1][i]) return 0;
		}
	}
	return 1;
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		Co++;
		scanf("%d", &N);
		for (i = 1; i <= 2 * N - 1; i++) {
			for (j = 1; j <= N; j++) {
				C1[j] = C2[j] = 0;
				scanf("%d", &data[i][j]);
			}
		}
		for (i = 1; i <= 2*N-1; i++) {
			for (j = i + 1; j <= 2*N-1; j++) {
				for (k = 1; k <= N; k++) {
					if (data[i][k] > data[j][k]) break;
				}
				if (k<=N) {
					for (k = 1; k <= N; k++) {
						change(data[i][k], data[j][k]);
					}
				}
			}
		}
		for (i = 1; i <= N; i++) {
			Print[1][i] = data[1][i]; C1[1] = 1;
			Print[i][1] = data[2][i]; C2[1] = 1;
		}
		for (i = 3; i <= 2 * N - 1; i++) {
			if (data[i][1] == data[i + 1][1]) {
				for (j = 1; j <= N; j++) {
					if (Print[1][j] == data[i][1]) break;
				}
				for (k = 1; k <= N; k++) {
					Print[k][j] = data[i][k];
				}
				for (l = 1; l <= N; l++) {
					if (Print[l][1] == data[i+1][1]) break;
				}
				for (k = 1; k <= N; k++) {
					Print[l][k] = data[i+1][k];
				}
				C1[l] = 1; C2[j] = 1;
				if(ValidP()==0){
					for (k = 1; k <= N; k++) {
						Print[k][j] = data[i + 1][k]; Print[l][k] = data[i][k];
					}
				}
				i++;
			}
			else {
				for (j = 1; j <= N; j++) {
					if (Print[1][j] == data[i][1]) break;
				}
				int flag = 0;
				if (j <= N) {
					for (k = 1; k <= N; k++) {
						Print[k][j] = data[i][k];
					}
					if (ValidP() == 1) {
						C2[j] = 1; flag = 1;
					}
				}
				if(flag==0){
					for (j = 1; j <= N; j++) {
						if (Print[j][1] == data[i][1]) break;
					}
					C1[j] = 1;
					for (k = 1; k <= N; k++) {
						Print[j][k] = data[i][1];
					}
				}
			}
		}
		printf("Case #%d:", Co);
		for (i = 1; i <= N; i++) {
			if (C1[i] == 0) break;
		}
		if (i <= N) {
			for (j = 1; j <= N; j++) {
				printf(" %d", Print[i][j]);
			}
		}
		else {
			for (i = 1; i <= N; i++) {
				if (C2[i] == 0) break;
			}
			for (j = 1; j <= N; j++) {
				printf(" %d", Print[j][i]);
			}
		}
		printf("\n");
	}
	return 0;
}